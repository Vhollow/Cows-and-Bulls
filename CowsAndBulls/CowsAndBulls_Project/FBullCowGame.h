#pragma once

class FBullCowGame
{
public:
	void Reset(int WordLength);
	int GetMaxTries();
	int GetTryNumber();
	bool GameWon();
	bool CheckWord(string);

private:
	int CurrentTry;
	int MaxTries;
};
