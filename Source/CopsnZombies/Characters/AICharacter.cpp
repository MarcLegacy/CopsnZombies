// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "AICharacter.h"

#include "BehaviorTree/BehaviorTree.h"
#include "StateTree.h"
#include "CopsnZombies/Utility/Logger.h"

AAICharacter::AAICharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsPropertySet(this, BehaviorTree, GET_MEMBER_NAME_CHECKED(AAICharacter, BehaviorTree));
    FLogger::CheckAndLogIsPropertySet(this, StateTree, GET_MEMBER_NAME_CHECKED(AAICharacter, StateTree));
}


