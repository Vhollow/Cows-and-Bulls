#pragma once
#include <string>

using FString = std::string;
using int32 = int;


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

private:
	int32 CurrentTry;
	int32 MaxTries;
};
