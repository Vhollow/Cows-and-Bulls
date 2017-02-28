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
	Won = false;
}

bool FBullCowGame::GameWon()
{
	return Won;
}

EValidGuess FBullCowGame::CheckWord(FString Guess)
{	
	if (false) {
		return EValidGuess::Not_Isogram;
	}
	else if(false)
	{
		return EValidGuess::Not_LowerCase;
	}
	else if (Guess.length() != GetWordLength())
	{
		return EValidGuess::Wrong_Length;
	}
	else
	{
		return EValidGuess::OK;
	}
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
		}
	}
	if (BAndC.Bulls == GetWordLength())
	{
		Won = true;
	}

	return BAndC;
}
