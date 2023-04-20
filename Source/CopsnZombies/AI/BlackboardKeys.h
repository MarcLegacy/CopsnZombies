#pragma once

#include "Runtime/Core/Public/UObject/NameTypes.h"

namespace BlackboardKeys
{
    // TCHAR* used instead of FName& is because VS shows errors using the latter.
    // inline used to avoid having variables being defined by different classes.

    inline const TCHAR* TargetPosition = TEXT("TargetPosition");
    inline const TCHAR* IsTargetSeen = TEXT("IsTargetSeen");
    inline const TCHAR* TargetCharacter = TEXT("TargetCharacter");
}