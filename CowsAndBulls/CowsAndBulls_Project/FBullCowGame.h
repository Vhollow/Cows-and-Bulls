#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset(int WordLength);
	int GetMaxTries();
	int GetTryNumber();
	bool GameWon();
	bool CheckWord(std::string);

private:
	int CurrentTry = 0;
	int MaxTries = 5;
};
