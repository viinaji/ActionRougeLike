#pragma once
struct FWarningLog
{
	/** Log Warning String To Unreal OutputLog */
	UE_NODISCARD static FORCEINLINE void MyLog(const char* Message)
	{
		const FString OutputMessage{Message};
		UE_LOG(LogTemp, Warning, TEXT("%s"), *OutputMessage);
	}

	/** Log Warning String With Args To Unreal OutputLog */
	template <typename TMessage, typename... Types>
	FORCEINLINE static void MyLog(const TMessage& Message, Types ... Args)
	{
		const FString TempMessage = FString::Printf(Message, Args...);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *TempMessage);
	}

	/** Log Warning FVector To Unreal OutputLog */
	FORCEINLINE static void MyLog(const FVector Vector)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Vector.ToString());
	}

	/** Log Warning FRotator To Unreal OutputLog */
	FORCEINLINE static void MyLog(const FRotator Rotator)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Rotator.ToString());
	}

	/** Log Warning FString To Unreal OutputLog */
	FORCEINLINE static void MyLog(const FString& Message)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
	}

	/** Log Warning Integer To Unreal OutputLog */
	FORCEINLINE static void MyLog(const int Number)
	{
		UE_LOG(LogTemp, Warning, TEXT("%i"), Number);
	}

	/** Log Warning Boolean To Unreal OutputLog */
	FORCEINLINE static void MyLog(const bool bBool)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), (bBool ? TEXT("true") : TEXT("false") ));
	}

	/** Log Warning Float To Unreal OutputLog */
	FORCEINLINE static void MyLog(const float Value)
	{
		UE_LOG(LogTemp, Warning, TEXT("%f"), Value);
	}
};

struct FErrorLog
{
	/** Log Error String To Unreal OutputLog */
	FORCEINLINE static void MyLog(const char* Message)
	{
		const FString OutputMessage{Message};
		UE_LOG(LogTemp, Error, TEXT("%s"), *OutputMessage);
	}

	/** Log Error String With Args To Unreal OutputLog */
	template <typename TMessage, typename... Types>
	FORCEINLINE static void MyLog(const TMessage& Message, Types ... Args)
	{
		const FString TempMessage = FString::Printf(Message, Args...);
		UE_LOG(LogTemp, Error, TEXT("%s"), *TempMessage);
	}

	/** Log Error FVector To Unreal OutputLog */
	FORCEINLINE static void MyLog(const FVector Vector)
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), *Vector.ToString());
	}

	/** Log Error FRotator To Unreal OutputLog */
	FORCEINLINE static void MyLog(const FRotator Rotator)
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), *Rotator.ToString());
	}

	/** Log Error FString To Unreal OutputLog */
	FORCEINLINE static void MyLog(const FString& Message)
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
	}

	/** Log Error Integer To Unreal OutputLog */
	FORCEINLINE static void MyLog(const int Number)
	{
		UE_LOG(LogTemp, Error, TEXT("%i"), Number);
	}

	/** Log Error Boolean To Unreal OutputLog */
	FORCEINLINE static void MyLog(const bool bBool)
	{
		UE_LOG(LogTemp, Error, TEXT("%s"), (bBool ? TEXT("true") : TEXT("false") ));
	}

	/** Log Error Float To Unreal OutputLog */
	FORCEINLINE static void MyLog(const float Value)
	{
		UE_LOG(LogTemp, Error, TEXT("%f"), Value);
	}
};

struct FScreenLog
{
	template <typename TMessage, typename... Types>
	FORCEINLINE static void MyLog(const uint64 KeyNumber, const TMessage& Message, Types ... Args)
	{
		const FString TempMessage = FString::Printf(Message, Args...);
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, FColor::Blue, TempMessage); }
	}

	template <typename TMessage, typename... Types>
	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FColor& Color, const TMessage& Message, Types ... Args)
	{
		const FString TempMessage = FString::Printf(Message, Args...);
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, Color, TempMessage); }
	}

	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FVector& Vector)
	{
		const FString TempMessage = FString::Printf(TEXT("%s"), *Vector.ToString());
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, FColor::Blue, TempMessage); }
	}


	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FColor& Color, const FVector& Vector)
	{
		const FString TempMessage = FString::Printf(TEXT("%s"), *Vector.ToString());
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, Color, TempMessage); }
	}

	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FRotator& Rotator)
	{
		const FString TempMessage = FString::Printf(TEXT("%s"), *Rotator.ToString());
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, FColor::Blue, TempMessage); }
	}


	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FColor& Color, const FRotator& Rotator)
	{
		const FString TempMessage = FString::Printf(TEXT("%s"), *Rotator.ToString());
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, Color, TempMessage); }
	}

	FORCEINLINE static void MyLog(const uint64 KeyNumber, const float Number)
	{
		const FString TempMessage = FString::Printf(TEXT("%f"), Number);
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, FColor::Blue, TempMessage); }
	}

	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FColor& Color, const float Number)
	{
		const FString TempMessage = FString::Printf(TEXT("%f"), Number);
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, Color, TempMessage); }
	}

	FORCEINLINE static void MyLog(const uint64 KeyNumber, const bool bBool)
	{
		const FString BoolString = bBool ? TEXT("true") : TEXT("false");
		const FString TempMessage = FString::Printf(TEXT("%s"), *BoolString);
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, FColor::Blue, TempMessage); }
	}

	FORCEINLINE static void MyLog(const uint64 KeyNumber, const FColor& Color, const bool bBool)
	{
		const FString BoolString = bBool ? TEXT("true") : TEXT("false");
		const FString TempMessage = FString::Printf(TEXT("%s"), *BoolString);
		if (GEngine) { GEngine->AddOnScreenDebugMessage(KeyNumber, 0, Color, TempMessage); }
	}
};
