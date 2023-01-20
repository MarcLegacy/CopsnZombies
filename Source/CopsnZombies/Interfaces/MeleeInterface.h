// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MeleeInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMeleeInterface : public UInterface
{
	GENERATED_BODY()
};

class COPSNZOMBIES_API IMeleeInterface
{
	GENERATED_BODY()

public:

	void OnMeleeAttack();
};
