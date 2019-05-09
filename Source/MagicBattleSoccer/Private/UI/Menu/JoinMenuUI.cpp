/** JoinMenuUI.cpp - This widget implements the list of available games. 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "JoinMenuUI.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerHUD.h"
#include "MagicBattleSoccerGameSession.h"
#include "MagicBattleSoccerInstance.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"
#include "MenuItemWidgetStyle.h"

void SJoinMenuUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;
	bLANMatchSearch = false;
	bSearchingForServers = false;
	BoxWidth = 125;

	const FMenuBackgroundStyle* BackgroundStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuBackgroundStyle>("DefaultMenuBackgroundStyle");
	const FMenuItemStyle* ItemStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuItemStyle>("DefaultMenuItemStyle");
	const FButtonStyle* ButtonStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FButtonStyle>("DefaultMenuButtonStyle");
	
	ChildSlot
	.VAlign(VAlign_Center)
	.HAlign(HAlign_Center)
	[
		SNew(SBox)
		.WidthOverride(800)
		.HeightOverride(400)
		[
			SNew(SBorder)
			.BorderImage(&BackgroundStyle->BackgroundBrush)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding(FMargin(0, 20, 0, 20))
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(FMargin(15, 0, 15, 0))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SAssignNew(ServerListWidget, SListView<TSharedPtr<FServerEntry>>)
							.ItemHeight(20)
							.ListItemsSource(&ServerList)
							.SelectionMode(ESelectionMode::Single)
							.OnGenerateRow(this, &SJoinMenuUI::MakeListViewWidget)
							//.OnSelectionChanged(this, &SJoinMenuUI::EntrySelectionChanged)
							//.OnMouseButtonDoubleClick(this, &SJoinMenuUI::OnListItemDoubleClicked)
							.HeaderRow(
							SNew(SHeaderRow)
							+ SHeaderRow::Column("ServerName").FixedWidth(BoxWidth * 2).DefaultLabel(NSLOCTEXT("ServerList", "ServerNameColumn", "Server Name"))
							+ SHeaderRow::Column("GameType").DefaultLabel(NSLOCTEXT("ServerList", "GameTypeColumn", "Game Type"))
							+ SHeaderRow::Column("Map").DefaultLabel(NSLOCTEXT("ServerList", "MapNameColumn", "Map"))
							+ SHeaderRow::Column("Players").DefaultLabel(NSLOCTEXT("ServerList", "PlayersColumn", "Players"))
							+ SHeaderRow::Column("Ping").DefaultLabel(NSLOCTEXT("ServerList", "NetworkPingColumn", "Ping")))
						]
						+ SVerticalBox::Slot()
						.AutoHeight()
						[
							SNew(SOverlay)
							+ SOverlay::Slot()
							.VAlign(VAlign_Center)
							.HAlign(HAlign_Center)
							[
								SNew(STextBlock)
								.Text(this, &SJoinMenuUI::GetBottomText)
								.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.MenuServerListTextStyle")
							]
						]
					]
				]
			]
		]
	];

}

/**
* Get the current game session
*/
AMagicBattleSoccerGameSession* SJoinMenuUI::GetGameSession() const
{
	UMagicBattleSoccerInstance *GI = Cast<UMagicBattleSoccerInstance>(GEngine->GameViewport->GetGameInstance());
	return GI ? GI->GetGameSession() : nullptr;
}

/** Updates current search status */
void SJoinMenuUI::UpdateSearchStatus()
{
	check(bSearchingForServers); // should not be called otherwise

	bool bFinishSearch = true;
	AMagicBattleSoccerGameSession* GameSession = GetGameSession();
	if (GameSession)
	{
		int32 CurrentSearchIdx, NumSearchResults;
		EOnlineAsyncTaskState::Type SearchState = GameSession->GetSearchResultStatus(CurrentSearchIdx, NumSearchResults);

		UE_LOG(LogTemp, Log, TEXT("GameSession->GetSearchResultStatus: %s"), EOnlineAsyncTaskState::ToString(SearchState));

		switch (SearchState)
		{
		case EOnlineAsyncTaskState::InProgress:
			StatusText = TEXT("SEARCHING...");
			bFinishSearch = false;
			break;

		case EOnlineAsyncTaskState::Done:
			// copy the results
		{
			ServerList.Empty();
			const TArray<FOnlineSessionSearchResult> & SearchResults = GameSession->GetSearchResults();
			check(SearchResults.Num() == NumSearchResults);
			if (NumSearchResults == 0)
			{
				StatusText = TEXT("NO SERVERS FOUND, PRESS SPACE TO TRY AGAIN");
			}
			else
			{
				StatusText = TEXT("PRESS SPACE TO REFRESH SERVER LIST");
			}

			for (int32 IdxResult = 0; IdxResult < NumSearchResults; ++IdxResult)
			{
				TSharedPtr<FServerEntry> NewServerEntry = MakeShareable(new FServerEntry());

				const FOnlineSessionSearchResult & Result = SearchResults[IdxResult];

				NewServerEntry->ServerName = Result.Session.OwningUserName;
				NewServerEntry->Ping = FString::FromInt(Result.PingInMs);
				NewServerEntry->CurrentPlayers = FString::FromInt(Result.Session.SessionSettings.NumPublicConnections
					+ Result.Session.SessionSettings.NumPrivateConnections
					- Result.Session.NumOpenPublicConnections
					- Result.Session.NumOpenPrivateConnections);
				NewServerEntry->MaxPlayers = FString::FromInt(Result.Session.SessionSettings.NumPublicConnections
					+ Result.Session.SessionSettings.NumPrivateConnections);
				NewServerEntry->SearchResultsIndex = IdxResult;

				Result.Session.SessionSettings.Get(SETTING_GAMEMODE, NewServerEntry->GameType);
				Result.Session.SessionSettings.Get(SETTING_MAPNAME, NewServerEntry->MapName);

				ServerList.Add(NewServerEntry);
			}
		}
			break;

		case EOnlineAsyncTaskState::Failed:
			// intended fall-through
		case EOnlineAsyncTaskState::NotStarted:
			StatusText = "";
			// intended fall-through
		default:
			break;
		}
	}

	if (bFinishSearch)
	{
		OnServerSearchFinished();
	}
}

FString SJoinMenuUI::GetBottomText() const
{
	return StatusText;
}

/**
* Ticks this widget.  Override in derived classes, but always call the parent implementation.
*
* @param  AllottedGeometry The space allotted for this widget
* @param  InCurrentTime  Current absolute real time
* @param  InDeltaTime  Real time passed since last tick
*/
void SJoinMenuUI::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);

	if (bSearchingForServers)
	{
		UpdateSearchStatus();
	}
}

/** Starts searching for servers */
void SJoinMenuUI::BeginServerSearch(bool bLANMatch, const FString & InMapFilterName)
{
	bLANMatchSearch = bLANMatch;
	MapFilterName = InMapFilterName;
	bSearchingForServers = true;
	ServerList.Empty();

	UMagicBattleSoccerInstance *GI = Cast<UMagicBattleSoccerInstance>(GEngine->GameViewport->GetGameInstance());
	if (nullptr != GI)
	{
		ULocalPlayer* PlayerOwner = GEngine->GetFirstGamePlayer(GEngine->GameViewport);
		GI->FindSessions(PlayerOwner, bLANMatchSearch);
	}
}

/** Called when server search is finished */
void SJoinMenuUI::OnServerSearchFinished()
{
	bSearchingForServers = false;

	UpdateServerList();
}

/** fill/update server list, should be called before showing this control */
void SJoinMenuUI::UpdateServerList()
{
	/** Only filter maps if a specific map is specified */
	if (MapFilterName != "ANY")
	{
		for (int32 i = 0; i < ServerList.Num(); ++i)
		{
			/** Only filter maps if a specific map is specified */
			if (ServerList[i]->MapName != MapFilterName)
			{
				ServerList.RemoveAt(i);
			}
		}
	}

	int32 SelectedItemIndex = ServerList.IndexOfByKey(SelectedItem);

	ServerListWidget->RequestListRefresh();
	if (ServerList.Num() > 0)
	{
		ServerListWidget->UpdateSelectionSet();
		ServerListWidget->SetSelection(ServerList[SelectedItemIndex > -1 ? SelectedItemIndex : 0], ESelectInfo::OnNavigation);
	}

}

TSharedRef<ITableRow> SJoinMenuUI::MakeListViewWidget(TSharedPtr<FServerEntry> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	class SServerEntryWidget : public SMultiColumnTableRow< TSharedPtr<FServerEntry> >
	{
	public:
		SLATE_BEGIN_ARGS(SServerEntryWidget){}
		SLATE_END_ARGS()

			void Construct(const FArguments& InArgs, const TSharedRef<STableViewBase>& InOwnerTable, TSharedPtr<FServerEntry> InItem)
		{
			Item = InItem;
			SMultiColumnTableRow< TSharedPtr<FServerEntry> >::Construct(FSuperRowType::FArguments(), InOwnerTable);
		}

		TSharedRef<SWidget> GenerateWidgetForColumn(const FName& ColumnName)
		{
			FString ItemText;
			if (ColumnName == "ServerName")
			{
				ItemText = Item->ServerName + "'s Server";
			}
			else if (ColumnName == "GameType")
			{
				ItemText = Item->GameType;
			}
			else if (ColumnName == "Map")
			{
				ItemText = Item->MapName;
			}
			else if (ColumnName == "Players")
			{
				const FText PlayersOnServer = FText::Format(FText::FromString("{0}/{1}"), FText::FromString(Item->CurrentPlayers), FText::FromString(Item->MaxPlayers));
				ItemText = PlayersOnServer.ToString();
			}
			else if (ColumnName == "Ping")
			{
				ItemText = Item->Ping;
			}
			return SNew(STextBlock)
				.Text(ItemText)
				.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.MenuServerListTextStyle");
		}
		TSharedPtr<FServerEntry> Item;
	};
	return SNew(SServerEntryWidget, OwnerTable, Item);
}