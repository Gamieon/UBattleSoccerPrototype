/**
MagicBattleSoccerHUD.cpp - The base class for all shooter-specific HUD's. This has the capability to display a loading screen
or the most recent error message from the shooter engine class.
**/

#include <cmath>
#include "LoadingUI.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerHUD.h"
#include "ErrorUI.h"
#include "MagicBattleSoccerStyles.h"
#include "MagicBattleSoccerPlayerController.h"

AMagicBattleSoccerHUD::AMagicBattleSoccerHUD(const class FObjectInitializer& OI)
	: Super(OI)
{
	bIsLoadingUIVisible = false;
	bIsErrorUIVisible = false;
#if !UE_BUILD_SHIPPING
	IsDebugMode = true;
#else
	IsDebugMode = false;
#endif
}

void AMagicBattleSoccerHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// We need to do this if we're in the editor.
		FMagicBattleSoccerStyles::Initialize();

		// Create the loading UI
		SAssignNew(LoadingUI, SLoadingUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));

		// Create the error UI
		SAssignNew(ErrorUI, SErrorUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));
	}
}

//////////////////////////////////////////////////////////////////////////
// Drawing helpers

void AMagicBattleSoccerHUD::DrawFrame(FLinearColor FrameColor, float X, float Y, float Width, float Height, float Thickness)
{
	if (nullptr == Canvas)
	{
		// This has actually happened before. No idea why.
	}
	else
	{
		FCanvasLineItem NewLine;
		NewLine.SetColor(FrameColor);
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
}

bool AMagicBattleSoccerHUD::IsPointOnCanvas(FVector2D Point)
{
	// Canvas has been null before. No idea why.
	return (nullptr != Canvas && Point.X >= 0 && Point.Y >= 0 && Point.X < Canvas->SizeX && Point.Y < Canvas->SizeY);
}

typedef int8 OutCode;

const int8 INSIDE = 0; // 0000
const int8 LEFT = 1;   // 0001
const int8 RIGHT = 2;  // 0010
const int8 BOTTOM = 4; // 0100
const int8 TOP = 8;    // 1000

// Compute the bit code for a point (x, y) using the clip rectangle
// bounded diagonally by (xmin, ymin), and (xmax, ymax)

// ASSUME THAT xmax, xmin, ymax and ymin are global constants.

OutCode ComputeOutCode(float x, float y, float xmin, float ymin, float xmax, float ymax)
{
	OutCode code;

	code = INSIDE;          // initialised as being inside of clip window

	if (x < xmin)           // to the left of clip window
		code |= LEFT;
	else if (x > xmax)      // to the right of clip window
		code |= RIGHT;
	if (y < ymin)           // below the clip window
		code |= BOTTOM;
	else if (y > ymax)      // above the clip window
		code |= TOP;

	return code;
}

// http://en.wikipedia.org/wiki/Cohen%E2%80%93Sutherland_algorithm
// Cohen–Sutherland clipping algorithm clips a line from
// P0 = (x0, y0) to P1 = (x1, y1) against a rectangle with 
// diagonal from (xmin, ymin) to (xmax, ymax).
void CohenSutherlandLineClipAndDraw(float& x0, float& y0, float& x1, float& y1, float xmin, float ymin, float xmax, float ymax)
{
	// compute outcodes for P0, P1, and whatever point lies outside the clip rectangle
	OutCode outcode0 = ComputeOutCode(x0, y0, xmin, ymin, xmax, ymax);
	OutCode outcode1 = ComputeOutCode(x1, y1, xmin, ymin, xmax, ymax);
	bool accept = false;

	while (true) {
		if (!(outcode0 | outcode1)) { // Bitwise OR is 0. Trivially accept and get out of loop
			accept = true;
			break;
		}
		else if (outcode0 & outcode1) { // Bitwise AND is not 0. Trivially reject and get out of loop
			break;
		}
		else {
			// failed both tests, so calculate the line segment to clip
			// from an outside point to an intersection with clip edge
			float x = 0.f, y = 0.f;

			// At least one endpoint is outside the clip rectangle; pick it.
			OutCode outcodeOut = outcode0 ? outcode0 : outcode1;

			// Now find the intersection point;
			// use formulas y = y0 + slope * (x - x0), x = x0 + (1 / slope) * (y - y0)
			if (outcodeOut & TOP) {           // point is above the clip rectangle
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			}
			else if (outcodeOut & BOTTOM) { // point is below the clip rectangle
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			}
			else if (outcodeOut & RIGHT) {  // point is to the right of clip rectangle
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			}
			else if (outcodeOut & LEFT) {   // point is to the left of clip rectangle
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}

			// Now we move outside point to intersection point to clip
			// and get ready for next pass.
			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0, xmin, ymin, xmax, ymax);
			}
			else {
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1, xmin, ymin, xmax, ymax);
			}
		}
	}
}

FVector2D AMagicBattleSoccerHUD::ClipPointToCanvas(FVector2D Point, float Thickness)
{
	FVector2D O(Canvas->SizeX / 2, Canvas->SizeY / 2);
	CohenSutherlandLineClipAndDraw(O.X, O.Y, Point.X, Point.Y, Thickness, Thickness, (float)Canvas->SizeX - Thickness, (float)Canvas->SizeY - Thickness);
	return Point;
}

float AMagicBattleSoccerHUD::ConvertXYToDegrees(FVector2D Origin, FVector2D Point)
{
	return std::atan2(Point.Y - Origin.Y, Point.X - Origin.X) * 180.f / 3.14159f;
}

//////////////////////////////////////////////////////////////////////////
// Menu helpers

/** Drills down from the current menu into the specified menu. */
void AMagicBattleSoccerHUD::PushMenu(TSharedPtr<class SCompoundWidget> Menu)
{
	UGameViewportClient* Viewport = GEngine->GameViewport;

	if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
	{
		Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
	
	MenuStack.Add(SNew(SWeakWidget).PossiblyNullContent(Menu));

	if (!IsSystemPromptVisible())
	{
		Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
}

/** Returns to the previous menu. */
void AMagicBattleSoccerHUD::PopMenu()
{
	UGameViewportClient* Viewport = GEngine->GameViewport;

	if (MenuStack.Num() > 0)
	{
		if (!IsSystemPromptVisible())
		{
			Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}
		MenuStack.Pop();
	}

	if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
	{
		Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
}

//////////////////////////////////////////////////////////////////////////
// System widget helpers

/** True if a loading or error prompt are visible */
bool AMagicBattleSoccerHUD::IsSystemPromptVisible()
{
	return bIsLoadingUIVisible || bIsErrorUIVisible;
}

/** Shows the loading screen */
void AMagicBattleSoccerHUD::ShowLoadingScreen()
{
	if (IsSystemPromptVisible())
	{
		// We should not get here; but if we do, don't do anything
	}
	else
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// Hide the existing menu
		if (MenuStack.Num() > 0)
		{
			Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}

		// Show the loading widget
		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(LoadingUI));
		bIsLoadingUIVisible = true;
	}
}

/** Hides the loading screen */
void AMagicBattleSoccerHUD::HideLoadingScreen()
{
	if (bIsLoadingUIVisible)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;
		Viewport->RemoveAllViewportWidgets();
		bIsLoadingUIVisible = false;

		if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
		{
			Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}
	}
}

/** Shows the most recently retained error message in the MagicBattleSoccerEngine object with a dismiss button */
void AMagicBattleSoccerHUD::ShowLastEngineErrorScreen()
{
	// Hide the loading screen if it's up
	HideLoadingScreen();

	if (IsSystemPromptVisible())
	{
		// We should not get here; but if we do, don't do anything
	}
	else
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// Hide the existing menu
		if (MenuStack.Num() > 0)
		{
			Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}

		// Show the error widget
		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(ErrorUI));
		bIsErrorUIVisible = true;
	}
}

/** Hides the error screen */
void AMagicBattleSoccerHUD::HideErrorScreen()
{
	if (bIsErrorUIVisible)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;
		Viewport->RemoveAllViewportWidgets();
		bIsErrorUIVisible = false;

		if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
		{
			Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}
	}
}