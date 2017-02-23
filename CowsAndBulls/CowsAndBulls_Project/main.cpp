#include <iostream>
#include <string>

using namespace std;

constexpr int WORD_LENGTH = 6;
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
	return g;
}

int main() {

	PrintIntro();
	for (int i = 1; i <= 5; i++)
	{
		Guess = GetGuessAndPrint();
	}

	return 0;
}