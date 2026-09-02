// Copyright Core Mechanics


#include "UI/WidgetController/AuraWidgetController.h"

// Set key variables for widget controller
void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UAuraWidgetController::BroadcastInitialValues()
{
	// Empty because we'll only define this elsewhere
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
	// This will be overridden
}
