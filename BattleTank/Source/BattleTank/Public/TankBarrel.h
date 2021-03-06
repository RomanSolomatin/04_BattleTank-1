// Copyright Nicholas Wilkie

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movement, and +1 is max upward movement
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // If adding new tanks, make this EditAnywhere to allow different barrel movement speeds in editor.
	float MaxDegreesPerSecond = 7; // Sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 30;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = -2;
	
};
