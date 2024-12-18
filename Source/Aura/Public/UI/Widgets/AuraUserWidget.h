﻿// Copyright, RilAnca 2024

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

class UBaseWidgetController;

UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// ===== Widget Controller ===== //
	
	UPROPERTY(BlueprintReadOnly)
	TWeakObjectPtr<UBaseWidgetController> WidgetController;

	/** Called right after the widget controller is set */
	UFUNCTION(BlueprintNativeEvent)
	void OnWidgetControllerSet();

public:
	UPROPERTY(EditAnywhere, Category=Properties)
	bool bInheritController = false;
	
	void SetWidgetController(UBaseWidgetController* InController);

public:
	// ===== Properties ===== //

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetViewportOffsetByPercentage(TEnumAsByte<EAxis::Type> Axis, const float Percentage);
};
