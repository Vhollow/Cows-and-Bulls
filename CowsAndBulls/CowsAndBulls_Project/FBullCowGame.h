#pragma once
#include <string>

class FBullCowGame
{
public:
	//Constructor
	FBullCowGame();
	//Getters
	int GetMaxTries() const;
	int GetTryNumber() const;
	//Other methods
	void Reset();
	bool GameWon();
	bool CheckWord(std::string);

private:
	int CurrentTry;
	int MaxTries;
};
