// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "BatteryCollectorGameMode.generated.h"

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();
    
    virtual void Tick(float DeltaTime) override;
    
    virtual void BeginPlay() override;
    
    /** Returns power to win - needed for the HUD */
    UFUNCTION(BlueprintPure, Category = "Power")
    float GetPowerToWin() const;
    
protected:
    
    /** The rate at which the character loses power */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
    float DecayRate;
    
    /** The amount of power needed to win the game */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
    float PowerToWin;
    
    /** The widget class to use for our HUD screen */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
    TSubclassOf<class UUserWidget> HUDWidgetClass;
    
    /** The instance of the HUD */
    UPROPERTY()
    class UUserWidget* CurrentWidget;
};



