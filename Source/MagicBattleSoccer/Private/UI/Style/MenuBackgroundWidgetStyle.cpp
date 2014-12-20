/** MenuBackgroundWidgetStyle.cpp - This is the base class for background style widget blueprints accessed in the Unreal Editor.
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "MagicBattleSoccer.h"
#include "MenuBackgroundWidgetStyle.h"

FMenuBackgroundStyle::FMenuBackgroundStyle()
{
}

FMenuBackgroundStyle::~FMenuBackgroundStyle()
{
}

const FName FMenuBackgroundStyle::TypeName(TEXT("FMenuBackgroundStyle"));

const FMenuBackgroundStyle& FMenuBackgroundStyle::GetDefault()
{
	static FMenuBackgroundStyle Default;
	return Default;
}

void FMenuBackgroundStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	OutBrushes.Add(&BackgroundBrush);
}

UMenuBackgroundWidgetStyle::UMenuBackgroundWidgetStyle(const class FObjectInitializer& OI)
	: Super(OI)
{

}
