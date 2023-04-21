// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"

class COPSNZOMBIES_API FLogger
{
public:
	FLogger() = default;
	~FLogger() = default;

    /**
     * @brief 
     * @param Message: pass in the message to display.
     * @param bToScreen: pass in true to display the message on the screen.
     * @param DisplayTime: pass in the time the message should be displayed on the screen.
     */
    static void LogMessage(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
    /**
     * @brief
     * @param Message: pass in the message to display.
     * @param bToScreen: pass in true to display the message on the screen.
     * @param DisplayTime: pass in the time the message should be displayed on the screen.
     */
	static void LogWarning(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
    /**
     * @brief
     * @param Message: pass in the message to display.
     * @param bToScreen: pass in true to display the message on the screen.
     * @param DisplayTime: pass in the time the message should be displayed on the screen.
     */
	static void LogError(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);
    /**
     * @brief
     * @param Message: pass in the message to display.
     * @param bToScreen: pass in true to display the message on the screen.
     * @param DisplayTime: pass in the time the message should be displayed on the screen.
     */
	static void LogFatal(const FString& Message, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

   /**
	* @brief
	* @param CurrentActor: pass in 'this' to get the Actor.
	* @param PropertyName: pass in 'GET_MEMBER_NAME_CHECKED(ClassName, MemberName) to get the name of the property.
	* @param bToScreen: pass in true to display the message on the screen.
	* @param DisplayTime: pass in the time the message should be displayed on the screen.
	*/
	static void LogPropertyNotSet(const AActor* CurrentActor, const FName& PropertyName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

    /**
     * @brief 
     * @tparam T: pass in the class name.
     * @param FunctionName: pass in __FUNCTION__ to get the name of the function.
     * @param bToScreen: pass in true to display the message on the screen.
     * @param DisplayTime: pass in the time the message should be displayed on the screen.
     */
    template <typename T>
	static void LogNullptr(const FString& FunctionName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

    /**
    * @brief
    * @param CurrentActor: pass in 'this' to get the Actor.
    * @param Property: pass in the property to check.
    * @param PropertyName: pass in 'GET_MEMBER_NAME_CHECKED(ClassName, MemberName) to get the name of the property.
    * @param bToScreen: pass in true to display the message on the screen.
    * @param DisplayTime: pass in the time the message should be displayed on the screen.
    */
	static bool CheckAndLogIsPropertySet(const AActor* CurrentActor, const UObject* Property, const FName& PropertyName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

    /**
     * @brief 
     * @tparam T: pass in the class name.
     * @param ObjectToCheck: pass in the object to check.
     * @param FunctionName: pass in __FUNCTION__ to get the name of the function.
     * @param bToScreen: pass in true to display the message on the screen.
     * @param DisplayTime: pass in the time the message should be displayed on the screen.
     * @return 
     */
    template <typename T>
	static bool CheckAndLogIsValidPtr(const T* ObjectToCheck, const FString& FunctionName, const bool bToScreen = true, const float DisplayTime = STANDARD_DISPLAY_TIME);

private:
	// 'static' is needed because the variable is used in static functions.
	// 'constexpr' is added so that the variable is evaluated at compile-time.
	static constexpr uint64 DEFAULT_SLOT = -1;
	static constexpr float STANDARD_DISPLAY_TIME = 5.0f;
};

template <typename T>
void FLogger::LogNullptr(const FString& FunctionName, const bool bToScreen, const float DisplayTime)
{
	if (FunctionName == "")
	{
		LogError(T::StaticClass()->GetName() + " is a nullptr!", bToScreen, DisplayTime);
	}
    else
    {
        LogError(FunctionName + ": " + T::StaticClass()->GetName() + " is a nullptr!", bToScreen, DisplayTime);
    }
}

template <typename T>
bool FLogger::CheckAndLogIsValidPtr(const T* ObjectToCheck, const FString& FunctionName, const bool bToScreen,
	const float DisplayTime)
{
	if (ObjectToCheck == nullptr)
	{
		LogNullptr<T>(FunctionName, bToScreen, DisplayTime);
		return false;
	}

	return true;
}
