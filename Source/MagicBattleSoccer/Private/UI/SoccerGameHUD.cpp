/**
GameHUD.h - The HUD class for game maps.
**/

#include "MagicBattleSoccer.h"
#include "SoccerGameHUD.h"
#include "MagicBattleSoccerEngine.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerCharacter.h"

ASoccerGameHUD::ASoccerGameHUD(const class FObjectInitializer& OI)
	: Super(OI)
{
}

void ASoccerGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ASoccerGameHUD::DrawHUD()
{
	Super::DrawHUD();

	if (nullptr != Canvas)
	{
		DrawAllSoccerPlayerStats();
	}
}

void ASoccerGameHUD::DrawAllSoccerPlayerStats()
{
	AMagicBattleSoccerGameState *Game = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	if (nullptr != Game)
	{
		APlayerController* MyPC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		TArray<AMagicBattleSoccerCharacter*> Teammates = Game->GetTeammates(Cast<AMagicBattleSoccerPlayerState>(MyPC->PlayerState));
		for (TArray<AMagicBattleSoccerCharacter*>::TConstIterator It(Teammates.CreateConstIterator()); It; ++It)
		{
			DrawSoccerPlayerStats(*It);
		}

		if (nullptr != MyPC->GetPawn())
		{
			DrawSoccerPlayerStats(Cast<AMagicBattleSoccerCharacter>(MyPC->GetPawn()));
		}
	}
}

void ASoccerGameHUD::DrawSoccerPlayerStats(AMagicBattleSoccerCharacter *Player)
{
	APlayerController* MyPC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FVector2D ScreenPosition;

	// Get the screen position of the player
	MyPC->ProjectWorldLocationToScreen(Player->GetActorLocation(), ScreenPosition);

	// Render their health
	float w = (float)Canvas->SizeX * 0.04f;
	float h = w * 0.15f;

	DrawRect(
		FLinearColor::Red
		,ScreenPosition.X - w * 0.5f
		,ScreenPosition.Y - h * 8.f
		,w * Player->Health / Player->MaxHealth
		,h
		);

	DrawFrame(
		FLinearColor::Black
		,ScreenPosition.X - w * 0.5f
		,ScreenPosition.Y - h * 8.f
		,w
		,h
		,1.f
		);
}