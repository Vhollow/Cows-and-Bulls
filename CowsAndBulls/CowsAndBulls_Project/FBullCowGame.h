/*
	Game logic.
*/
#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullsAndCows {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EValidGuess {
	OK,
	Wrong_Length,
	Not_LowerCase,
	Not_Isogram
};


class FBullCowGame
{
public:
	//Constructor
	FBullCowGame();
	//Getters
	int32 GetMaxTries() const;
	int32 GetTryNumber() const;
	int32 GetWordLength() const;
	//Other methods
	void Reset();
	bool GameWon();
	EValidGuess CheckWord(FString);
	FBullsAndCows SubmitGuess(FString);

private:
	int32 CurrentTry;
	FString HiddenWord;
	bool Won;
	bool IsLowerCase(FString) const;
	bool IsIsogram(FString) const;
};
