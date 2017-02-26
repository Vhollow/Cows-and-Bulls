#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int FBullCowGame::GetTryNumber() const
{
	return CurrentTry;
}

void FBullCowGame::Reset(int WordLength)
{
}

bool FBullCowGame::GameWon()
{
	return false;
}

bool FBullCowGame::CheckWord(std::string)
{
	return false;
}
