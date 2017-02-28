#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ { 3,4 },{ 4,7 },{ 5,10 },{ 6,16 },{ 7,20 } };
	return WordLengthToMaxTries[HiddenWord.length()];
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
	HiddenWord = "planet";
	Won = false;
}

bool FBullCowGame::GameWon()
{
	return Won;
}

EValidGuess FBullCowGame::CheckWord(FString Guess)
{	
	if (!IsIsogram(Guess)) {
		return EValidGuess::Not_Isogram;
	}
	else if(!IsLowerCase(Guess))
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

bool FBullCowGame::IsLowerCase(FString Word) const
{
	if (Word.length() < 1 || Word == "\0") { return false; }
	for (char Letter : Word) {
		if (Letter == ' ') {
			return false;
		}
		else if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}

bool FBullCowGame::IsIsogram(FString Word) const
{	
	if (Word.length() <= 1) { return false; }
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
	return true;
}
