#include <iostream>
#include <string>

using namespace std;

constexpr int WORD_LENGTH = 6;
constexpr int NUMBER_TURNS = 5;
string Guess = "";

void PrintIntro() {
	//Print the introduction lines
	cout << "Welcome to Bulls and Cows.\n";
	cout << "In this game you have to guess a " << WORD_LENGTH << " letter length isogram\n" << endl;
	return;
}
string GetGuessAndPrint() {
	string g = "";
	// Get a guess from player
	cout << "Make a guess:";
	getline(cin, g);
	//Repeat back
	cout << "Your guess is:" << g << endl;
	cout << endl;
	return g;
}
void PlayGame() {
	for (int i = 1; i <= NUMBER_TURNS; i++)
	{
		Guess = GetGuessAndPrint();
	}
}

bool AskAgain() {
	cout << "Do you want to play again? (Y/N):";
	string Res = "";
	cin >> Res;
	cout << endl;
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