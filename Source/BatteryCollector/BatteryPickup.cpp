// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"



// Set default values
ABatteryPickup::ABatteryPickup() {
    GetMesh()->SetSimulatePhysics(true);
    
    // set default battery power
    BatteryPower = 150.0f;
}

void ABatteryPickup::Collected_Implementation() {
    
    // use base pickup behaviour
    Super::Collected_Implementation();
    
    // destroy the battery
    Destroy();
}

// report the power level of the battery
float ABatteryPickup::GetBatteryPower() {
    return BatteryPower;
}
