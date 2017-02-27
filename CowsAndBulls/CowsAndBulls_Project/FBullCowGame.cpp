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

int32 FBullCowGame::GetWordLength() const
{
	return HiddenWord.length();
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

EValidGuess FBullCowGame::CheckWord(FString)
{
	return EValidGuess::OK;
}

FBullsAndCows FBullCowGame::SubmitGuess(FString Guess)
{
	CurrentTry++;

	FBullsAndCows BAndC;

	for (int32 i = 0; i < HiddenWord.length(); i++) {
		for (int32 j = 0; j < HiddenWord.length(); j++) {
			if (Guess[i] == HiddenWord[j]) {
				if(i==j) BAndC.Bulls++;
				else BAndC.Cows++;
			}
			else {

			}
		}
	}

	return BAndC;
}
