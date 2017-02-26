#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int FBullCowGame::GetTryNumber() const
{
	return CurrentTry;
}

void FBullCowGame::Reset()
{
	CurrentTry = 1;
	MaxTries = 5;
}

bool FBullCowGame::GameWon()
{
	return false;
}

bool FBullCowGame::CheckWord(std::string)
{
	return false;
}
