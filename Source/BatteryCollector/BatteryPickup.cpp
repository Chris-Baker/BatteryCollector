// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"



// Set default values
ABatteryPickup::ABatteryPickup() {
    GetMesh()->SetSimulatePhysics(true);
}

void ABatteryPickup::Collected_Implementation() {
    
    // use base pickup behaviour
    Super::Collected_Implementation();
    
    // destroy the battery
    Destroy();
}
