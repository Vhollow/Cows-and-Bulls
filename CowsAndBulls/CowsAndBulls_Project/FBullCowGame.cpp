#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int32 FBullCowGame::GetTryNumber() const
{
	return CurrentTry;
}

void FBullCowGame::Reset()
{
	CurrentTry = 1;
	MaxTries = 5;
	HiddenWord = "vision";
}

bool FBullCowGame::GameWon()
{
	return false;
}

bool FBullCowGame::CheckWord(FString)
{
	return false;
}

BullsAndCows FBullCowGame::SubmitGuess(FString)
{
	CurrentTry++;

	BullsAndCows BAndC;

	return BAndC;
}
