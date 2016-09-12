// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollector.h"
#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"

ABatteryCollectorGameMode::ABatteryCollectorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
    
    // base decay rate
    DecayRate = 0.01f;
}

void ABatteryCollectorGameMode::Tick(float DeltaTime) {
    
    Super::Tick(DeltaTime);
    
    ABatteryCollectorCharacter* Character = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    if(Character) {
        
        if(Character->GetCurrentPower() > 0) {
            Character->UpdatePower(-DeltaTime * DecayRate * (Character->GetCurrentPower()));
            
            if(Character->GetCurrentPower() < 0) {
                Character->UpdatePower(0);
            }
            
        }
    }
}