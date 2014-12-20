/** MenuBackgroundWidgetStyle.cpp - This is the base class for menu item style widget blueprints accessed in the Unreal Editor. */

#include "MagicBattleSoccer.h"
#include "MenuItemWidgetStyle.h"

FMenuItemStyle::FMenuItemStyle()
{
}

FMenuItemStyle::~FMenuItemStyle()
{
}

const FName FMenuItemStyle::TypeName(TEXT("FMenuItemStyle"));

const FMenuItemStyle& FMenuItemStyle::GetDefault()
{
	static FMenuItemStyle Default;
	return Default;
}

void FMenuItemStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	OutBrushes.Add(&LeftArrowImage);
	OutBrushes.Add(&RightArrowImage);
}

UMenuItemWidgetStyle::UMenuItemWidgetStyle(const class FObjectInitializer& OI)
	: Super(OI)
{

}
