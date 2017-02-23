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
void GetGuess() {
	// Get a guess from player
	cout << "Make a guess:";
	getline(cin, Guess);
	//Repeat back
	cout << "Your guess is:" << Guess << endl;
	return;
}

int main() {

	PrintIntro();
	GetGuess();

	return 0;
}