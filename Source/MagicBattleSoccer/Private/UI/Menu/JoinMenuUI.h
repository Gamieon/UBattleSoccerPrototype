/** JoinMenuUI.h - This widget implements the list of available games. 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#pragma once

#include "SlateBasics.h"

struct FServerEntry
{
	FString ServerName;
	FString CurrentPlayers;
	FString MaxPlayers;
	FString GameType;
	FString MapName;
	FString Ping;
	int32 SearchResultsIndex;
};

/**
* Lays out and controls the Options Menu UI.
**/
class SJoinMenuUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SJoinMenuUI)
		: _MenuHUD()
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMagicBattleSoccerHUD>, MenuHUD);

	SLATE_END_ARGS()

	/**
	* Constructs and lays out the Main Menu UI Widget.
	*
	* \args Arguments structure that contains widget-specific setup information.
	**/
	void Construct(const FArguments& args);

	/** creates single item widget, called for every list item */
	TSharedRef<ITableRow> MakeListViewWidget(TSharedPtr<FServerEntry> Item, const TSharedRef<STableViewBase>& OwnerTable);

	/**
	* Get the current game session
	*
	* @return The current game session
	*/
	class AMagicBattleSoccerGameSession* GetGameSession() const;

	/** Updates current search status */
	void UpdateSearchStatus();

	/** Starts searching for servers */
	void BeginServerSearch(bool bLANMatch, const FString & InMapFilterName);

	/** Called when server search is finished */
	void OnServerSearchFinished();

	/** fill/update server list, should be called before showing this control */
	void UpdateServerList();

	/**
	* Ticks this widget.  Override in derived classes, but always call the parent implementation.
	*
	* @param  AllottedGeometry The space allotted for this widget
	* @param  InCurrentTime  Current absolute real time
	* @param  InDeltaTime  Real time passed since last tick
	*/
	void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime);

protected:
	/** Whether last searched for LAN (so spacebar works) */
	bool bLANMatchSearch;

	/** Whether we're searching for servers */
	bool bSearchingForServers;

	/** action bindings array */
	TArray< TSharedPtr<FServerEntry> > ServerList;

	/** action bindings list slate widget */
	TSharedPtr< SListView< TSharedPtr<FServerEntry> > > ServerListWidget;

	/** Map filter name to use during server searches */
	FString MapFilterName;

	/** currently selected list item */
	TSharedPtr<FServerEntry> SelectedItem;

	/** get current status text */
	FString GetBottomText() const;

	/** current status text */
	FString StatusText;

	/** size of standard column in pixels */
	int32 BoxWidth;

	/**
	* Stores a weak reference to the HUD controlling this class.
	**/
	TWeakObjectPtr<class AMagicBattleSoccerHUD> MenuHUD;
};