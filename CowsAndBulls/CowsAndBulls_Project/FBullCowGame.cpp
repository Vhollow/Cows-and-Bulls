#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries()
{
	return MaxTries;
}

int FBullCowGame::GetTryNumber()
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
