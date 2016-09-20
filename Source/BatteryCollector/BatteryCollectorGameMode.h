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
    
    /** Returns power to win - needed for the HUD */
    UFUNCTION(BlueprintPure, Category = "Power")
    float GetPowerToWin() const;
    
    virtual void BeginPlay() override;
    
protected:
    
    /** The rate at which the character loses power */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
    float DecayRate;
    
    /** The amount of power needed to win the game */
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected))
    float PowerToWin;
};



