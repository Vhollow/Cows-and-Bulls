#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;


constexpr int32 WORD_LENGTH = 6;
FText Guess = "";
FBullCowGame Game;


void PrintIntro() {
	//Print the introduction lines
	std::cout << "Welcome to Bulls and Cows.\n";
	std::cout << "In this game you have to guess a " << WORD_LENGTH << " letter length isogram\n" << std::endl;
	return;
}
FText GetGuessAndPrint() {
	FText g = "";
	// Get a guess from player
	std::cout << "Make a guess:";
	std::getline(std::cin, g);
	//Repeat back
	std::cout << "Your guess is:" << g << std::endl;
	std::cout << std::endl;
	
	return g;
}
void PlayGame() {
	Game.Reset();
	int32 Tries = Game.GetMaxTries();

	for (int32 i = 1; i <= Tries; i++)
	{
		Guess = GetGuessAndPrint();
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