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
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "In this game you have to guess a " << Game.GetWordLength() << " letter length isogram\n" << std::endl;
	return;
}

FText GetGuess() {
	FText g = "";
	EValidGuess State;
	// Get a guess from player
	do
	{

		std::cout << "Make a guess:";
		std::getline(std::cin, g);

		State = Game.CheckWord(g);
		switch (State)
		{
		case Wrong_Length:
			std::cout << "Wrong length. Enter a " << Game.GetWordLength() << " letter isogram.\n";
			break;
		case Not_LowerCase:
			std::cout << "Enter a lower case word.\n";
			break;
		case Not_Isogram:
			std::cout << "Enter a word without repeating letters.\n";
			break;
		default:
			break;
		}

		std::cout << std::endl;

	} while (State != EValidGuess::OK);

	return g;
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

void PrintSummary() {

	if (Game.GameWon()) std::cout << "YOU WON" << std::endl;
	else std::cout << "You run out of tries. Better luck next time" << std::endl;

	std::cout << std::endl;
}

void PlayGame() {
	Game.Reset();
	int32 Tries = Game.GetMaxTries();
	int32 i = 1;

	while ( !Game.GameWon() && Game.GetTryNumber() <= Tries)
	{
		std::cout << "Try number: " << Game.GetTryNumber() << ".\n";
		Guess = GetGuess();
		FBullsAndCows BullsAndCows = Game.SubmitGuess(Guess);

		std::cout << "Bulls: " << BullsAndCows.Bulls << std::endl;
		std::cout << "Cows: " << BullsAndCows.Cows << std::endl;
		std::cout << std::endl;
	}
	PrintSummary();
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