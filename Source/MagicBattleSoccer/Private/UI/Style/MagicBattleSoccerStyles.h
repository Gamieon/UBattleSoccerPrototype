/** MagicBattleSoccerStyles.h - Provides an interface to blueprint styles from C++ code. You may also create your own styles; such as text formatting. */

#pragma once

/**
* Provides static methods for referencing our UI Styles.
**/
class FMagicBattleSoccerStyles
{
public:
	/**
	* Initializes the value of MenuStyleInstance and registers it with the Slate Style Registry.
	**/
	static void Initialize();

	/**
	* Unregisters the Slate Style Set and then resets the MenuStyleInstance pointer.
	**/
	static void Shutdown();

	/**
	* Retrieves a reference to the Slate Style pointed to by MenuStyleInstance.
	**/
	static const class ISlateStyle& Get();

	/**
	* Retrieves the name of the Style Set.
	**/
	static FName GetStyleSetName();

private:
	/**
	* Creates the Style Set.
	**/
	static TSharedRef<class FSlateStyleSet> Create();

	/**
	* Singleton instance used for our Style Set.
	**/
	static TSharedPtr<class FSlateStyleSet> MenuStyleInstance;
};