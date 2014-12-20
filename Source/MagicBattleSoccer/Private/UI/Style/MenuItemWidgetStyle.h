/** MenuBackgroundWidgetStyle.h - This is the base class for menu item style widget blueprints accessed in the Unreal Editor. */
// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SlateWidgetStyleContainerBase.h"
#include "MenuItemWidgetStyle.generated.h"

/**
* Represents the appearance of an FMenuItem
*/
USTRUCT()
struct FMenuItemStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FMenuItemStyle();
	virtual ~FMenuItemStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;
	static const FName TypeName;
	virtual const FName GetTypeName() const override { return TypeName; };
	static const FMenuItemStyle& GetDefault();

	/**
	* The image used for the left arrow
	*/
	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateBrush LeftArrowImage;
	FMenuItemStyle& SetLeftArrowImage(const FSlateBrush& InLeftArrowImage) { LeftArrowImage = InLeftArrowImage; return *this; }

	/**
	* The image used for the right arrow
	*/
	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateBrush RightArrowImage;
	FMenuItemStyle& SetRightArrowImage(const FSlateBrush& InRightArrowImage) { RightArrowImage = InRightArrowImage; return *this; }
};


/**
*/
UCLASS(hidecategories = Object, MinimalAPI)
class UMenuItemWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_UCLASS_BODY()

public:
	/** The actual data describing the menu's appearance. */
	UPROPERTY(Category = Appearance, EditAnywhere, meta = (ShowOnlyInnerProperties))
	FMenuItemStyle BackgroundStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >(&BackgroundStyle);
	}
};
