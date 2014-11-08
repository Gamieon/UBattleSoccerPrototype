/** MagicBattleSoccerStyles.cpp - Provides an interface to blueprint styles from C++ code. You may also create your own styles; such as text formatting.
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerStyles.h"
#include "Slate.h"
#include "SlateGameResources.h"

TSharedPtr<FSlateStyleSet> FMagicBattleSoccerStyles::MenuStyleInstance = NULL;

void FMagicBattleSoccerStyles::Initialize()
{
	if (!MenuStyleInstance.IsValid())
	{
		MenuStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*MenuStyleInstance);
	}
}

void FMagicBattleSoccerStyles::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*MenuStyleInstance);
	ensure(MenuStyleInstance.IsUnique());
	MenuStyleInstance.Reset();
}

FName FMagicBattleSoccerStyles::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MenuStyles"));
	return StyleSetName;
}

#define TTF_FONT( RelativePath, ... ) FSlateFontInfo( FPaths::GameContentDir() / "Slate"/ RelativePath + TEXT(".ttf"), __VA_ARGS__ )

TSharedRef<FSlateStyleSet> FMagicBattleSoccerStyles::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FMagicBattleSoccerStyles::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");
	FSlateStyleSet& Style = StyleRef.Get();
	
	Style.Set("MagicBattleSoccer.ButtonTextStyle", FTextBlockStyle()
		.SetFont(TTF_FONT("Fonts/Roboto-Black", 24))
		.SetColorAndOpacity(FLinearColor(0.7f, 0.7f, 0.7f, 1.0f))
		.SetShadowOffset(FIntPoint(-1, 1))
		);

	// Fonts still need to be specified in code for now
	Style.Set("MagicBattleSoccer.MenuServerListTextStyle", FTextBlockStyle()
		.SetFont(TTF_FONT("Fonts/Roboto-Black", 14))
		.SetColorAndOpacity(FLinearColor::White)
		.SetShadowOffset(FIntPoint(-1, 1))
		);

	return StyleRef;
}

const ISlateStyle& FMagicBattleSoccerStyles::Get()
{
	return *MenuStyleInstance;
}