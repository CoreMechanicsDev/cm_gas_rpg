// Copyright Core Mechanics


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAttributeSet.h"

// Function to broadcast INITIAL values
void UOverlayWidgetController::BroadcastInitialValues()
{
	// Set up attributeset variable after checking 
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	// Broadcast the values from the attribute set
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	
	// Broadcast the values from the attribute set
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	// Whenever the data from our Attribute Set changes (GetFooAttribute), call our function (FooChanged)
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, & UOverlayWidgetController::HealthChanged);
	
	// Whenever the health from our Attribute Set changes (GetHealthAttribute), call our function (HealthChanged)
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, & UOverlayWidgetController::MaxHealthChanged);

	// Whenever the data from our Attribute Set changes (GetFooAttribute), call our function (FooChanged)
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddUObject(this, & UOverlayWidgetController::ManaChanged);
	
	// Whenever the health from our Attribute Set changes (GetHealthAttribute), call our function (HealthChanged)
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, & UOverlayWidgetController::MaxManaChanged);
}

// Broadcast data change for Health
void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast value that was passed to this function in variable 'Data'
	OnHealthChanged.Broadcast(Data.NewValue);
}

// Broadcast data change for MaxHealth
void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast value that was passed to this function in variable 'Data'
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast value that was passed to this function in variable 'Data'
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	// Broadcast value that was passed to this function in variable 'Data'
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
