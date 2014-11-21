/**
GameHUD.h - The HUD class for game maps.
**/

#include "MagicBattleSoccer.h"
#include "SoccerGameHUD.h"
#include "MagicBattleSoccerEngine.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerPlayer.h"

ASoccerGameHUD::ASoccerGameHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

void ASoccerGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ASoccerGameHUD::DrawRect(float X, float Y, float Width, float Height, const FLinearColor& Color)
{
	FCanvasTileItem RectItem(
		FVector2D(X, Y),
		FVector2D(Width, Height),
		Color
		);

	RectItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(RectItem);
}

void ASoccerGameHUD::DrawRectFrame(float X, float Y, float Width, float Height, float Thickness, const FLinearColor& Color)
{
	FCanvasLineItem NewLine;
	NewLine.SetColor(Color);
	NewLine.LineThickness = Thickness;
	NewLine.BlendMode = SE_BLEND_Translucent;

	NewLine.Origin = FVector(X, Y, 0.f);
	NewLine.EndPos = FVector(X + Width, Y, 0.f);
	Canvas->DrawItem(NewLine);

	NewLine.EndPos = FVector(X, Y + Height, 0.f);
	Canvas->DrawItem(NewLine);

	NewLine.Origin = FVector(X + Width, Y + Height, 0.f);
	NewLine.EndPos = FVector(X, Y + Height, 0.f);
	Canvas->DrawItem(NewLine);

	NewLine.EndPos = FVector(X + Width, Y, 0.f);
	Canvas->DrawItem(NewLine);
}

void ASoccerGameHUD::DrawString(
	UFont*	TheFont,
	const FString& TheStr,
	float X, float Y,
	const FLinearColor& TheColor,
	float TheScale,
	bool DrawOutline,
	const FLinearColor& OutlineColor
	) 
{
	//Text and Font
	FCanvasTextItem NewText(
		FVector2D(X, Y),
		FText::FromString(TheStr),
		TheFont,
		TheColor
		);

	//Text Scale
	NewText.Scale.Set(TheScale, TheScale);

	//Outline gets its alpha from the main color
	NewText.bOutlined = true;
	NewText.OutlineColor = OutlineColor;
	NewText.OutlineColor.A = TheColor.A * 2;

	//Draw
	Canvas->DrawItem(NewText);
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
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Game->SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			DrawSoccerPlayerStats(*It);
		}
	}
}

void ASoccerGameHUD::DrawSoccerPlayerStats(AMagicBattleSoccerPlayer *Player)
{
	APlayerController* MyPC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	FVector2D ScreenPosition;

	// Get the screen position of the player
	MyPC->ProjectWorldLocationToScreen(Player->GetActorLocation(), ScreenPosition);

	// Render their health
	float w = (float)Canvas->SizeX * 0.04f;
	float h = w * 0.15f;

	DrawRect(
		ScreenPosition.X - w * 0.5f,
		ScreenPosition.Y - h * 8.f,
		w * Player->Health / Player->MaxHealth, h, FLinearColor::Red
		);

	DrawRectFrame(
		ScreenPosition.X - w * 0.5f,
		ScreenPosition.Y - h * 8.f,
		w, h, 1.f, FLinearColor::Black
		);
}