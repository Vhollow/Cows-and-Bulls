#include <iostream>
#include <string>


constexpr int WORD_LENGTH = 6;
constexpr int NUMBER_TURNS = 5;
std::string Guess = "";

void PrintIntro() {
	//Print the introduction lines
	std::cout << "Welcome to Bulls and Cows.\n";
	std::cout << "In this game you have to guess a " << WORD_LENGTH << " letter length isogram\n" << std::endl;
	return;
}
std::string GetGuessAndPrint() {
	std::string g = "";
	// Get a guess from player
	std::cout << "Make a guess:";
	std::getline(std::cin, g);
	//Repeat back
	std::cout << "Your guess is:" << g << std::endl;
	std::cout << std::endl;
	
	return g;
}
void PlayGame() {
	for (int i = 1; i <= NUMBER_TURNS; i++)
	{
		Guess = GetGuessAndPrint();
	}
}

bool AskAgain() {
	std::cout << "Do you want to play again? (Y/N):";
	std::string Res = "";
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