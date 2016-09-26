// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "BatteryCollector.h"
#include "BatteryCollectorGameMode.h"
#include "BatteryCollectorCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

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

void ABatteryCollectorGameMode::BeginPlay() {
    
    Super::BeginPlay();
    
    // Set the score to beat
    ABatteryCollectorCharacter* Character = Cast<ABatteryCollectorCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    if(Character) {
        PowerToWin = (Character->GetInitialPower()) * 1.25f;
    }
    
    if (HUDWidgetClass != nullptr) {
        CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
    }
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

float ABatteryCollectorGameMode::GetPowerToWin() const {
    return 0;
}