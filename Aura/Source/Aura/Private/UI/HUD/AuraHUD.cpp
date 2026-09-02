// Copyright Core Mechanics


#include "UI/HUD/AuraHUD.h"
// #include "UnrealWidgetFwd.h"
#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	// Check if HUD already exists, if not create one
	if (OverlayWidgetController == nullptr)
	{
		// Create it
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		// Set params
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		
		//Bind Callbacks Now that Params are set so that if any attributes change it will be broadcast
		OverlayWidgetController->BindCallbacksToDependencies();
		
		// Return it
		return OverlayWidgetController;
	}
	// Return it (if it already exists)
	return OverlayWidgetController;
}

// This function constructs the widget controller, the widget, set widget controller and add to viewport
void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	// Check logic
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitialized, please fill out BP_AuraHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitialized, please fill out BP_AuraHUD"));
	
	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	
	// Cast widget so we can set overlay widget
	OverlayWidget = Cast<UAuraUserWidget>(Widget);
	
	// Initialize parameters into const struct
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	
	// Call the Getter function (defined ablve) and store the results in WidgetContorller to finish construction
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	// ^^ Variable Type       ^^ Variable Name   ^^ Variable Value
	
	// Now set the controller - only broadcast values after this is done
	OverlayWidget->SetWidgetController(WidgetController);
	
	// Broadcast initial values now that controller is set up
	WidgetController->BroadcastInitialValues();
	
	// Add it to viewport
	Widget->AddToViewport();
}


