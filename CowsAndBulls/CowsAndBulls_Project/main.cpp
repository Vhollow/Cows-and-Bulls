#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


FText Guess = "";
FBullCowGame Game = FBullCowGame::FBullCowGame();


void PrintIntro() {
	//Print the introduction lines
	std::cout << "Welcome to Bulls and Cows.\n";
	std::cout << "In this game you have to guess a " << Game.GetWordLength() << " letter length isogram\n" << std::endl;
	return;
}
FText GetGuess() {
	FText g = "";
	// Get a guess from player
	std::cout << "Make a guess:";
	std::getline(std::cin, g);
	std::cout << std::endl;
	
	return g;
}
void PlayGame() {
	Game.Reset();
	int32 Tries = Game.GetMaxTries();

	for (int32 i = 1; i <= Tries; i++)
	{
		Guess = GetGuess();
		FBullsAndCows BullsAndCows = Game.SubmitGuess(Guess);

		std::cout << "Bulls: " << BullsAndCows.Bulls << std::endl;
		std::cout << "Cows: " << BullsAndCows.Cows << std::endl;
		std::cout << std::endl;
	}
}

bool AskAgain() {
	std::cout << "Do you want to play again? (Y/N):";
	FText Res = "";
	std::cin >> Res;
	std::cout << std::endl;
	if (Res[0] == 'Y' || Res[0] == 'y') {
		return true;
	}
	else
	{
		return false;
	}
}

/*---------------------------------------------------------------------------------------------
								Main Program
---------------------------------------------------------------------------------------------*/
int main() {

	PrintIntro();
	bool again = false;
	do{
		PlayGame();
		again = AskAgain();
	} while (again);


	return 0;
}