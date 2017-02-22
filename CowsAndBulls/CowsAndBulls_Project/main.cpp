#include <iostream>
#include <string>

using namespace std;

int main() {
	constexpr int WORD_LENGTH = 6;

	cout << "Welcome to Bulls and Cows.\n";
	cout << "In this game you have to guess a "<< WORD_LENGTH << " letter length isogram\n"<< endl;

	// Get a guess from player
	string Guess = "";
	cout << "Make a guess:";
	cin >> Guess;
	//Repeat back
	cout << "Your guess is:" << Guess << endl;

	return 0;
}