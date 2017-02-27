#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct BullsAndCows {
	int32 Bulls = 0;
	int32 Cows = 0;
};


class FBullCowGame
{
public:
	//Constructor
	FBullCowGame();
	//Getters
	int32 GetMaxTries() const;
	int32 GetTryNumber() const;
	//Other methods
	void Reset();
	bool GameWon();
	bool CheckWord(FString);
	BullsAndCows SubmitGuess(FString);

private:
	int32 CurrentTry;
	int32 MaxTries;
	FString HiddenWord;
};
