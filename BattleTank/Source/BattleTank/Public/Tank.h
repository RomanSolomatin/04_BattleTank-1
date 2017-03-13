// Copyright Nicholas Wilkie

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// Forward declarations
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup") // If adding new tanks, make this EditAnywhere and allow multiple projectile types in editor.
	TSubclassOf<AProjectile>ProjectileBlueprint; // Alternative https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf/

	// TODO Remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing") // If adding new tanks, make this EditAnywhere and allow different reload speeds in editor.
	float ReloadTimeInSeconds = 3;

	UTankBarrel* Barrel = nullptr; // Local barrel reference for spawning projectile 
	// TODO Remove

	double LastFireTime = 0;
};
