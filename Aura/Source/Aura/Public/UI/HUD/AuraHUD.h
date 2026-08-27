// Copyright Core Mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

// Forward Declarations
class UAttributeSet;
class UAbilitySystemComponent;
class UOverlayWidgetController;
class UAuraUserWidget;
struct FWidgetControllerParams;

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	
	// Getter for widget controller
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
	
// Create override function to put HUD on screen
protected:
	
private:
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;
	
	// Store pointer to existing widget controller
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
	// Make class for controller
	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
};
