// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "BatteryPickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYCOLLECTOR_API ABatteryPickup : public APickup
{
	GENERATED_BODY()
	
	
public:
    
    // Sets default values for this actor's properties
    ABatteryPickup();
    
	/** Override the Collected function - use _Implementation here because it is a Blueprint native event */
    void Collected_Implementation();
    
    /** Return how much power this battery has */
    float GetBatteryPower();
    
protected:
    
    /** Set the amount of power the battery gives to the character */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
    float BatteryPower;

};
