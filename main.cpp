// JAAR
// 06/16/2023
// Guessing Game
// Version 1


// Creates an instance of a guessing game:

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

// TODO: Use the esc key to exit the program.

struct game_information
{
	int total_attemps;
	int random_number;
};

bool is_digit(string guess);
int check_input();
inline void gives_hint(const int& guess, const int& random_number)
{
	(guess > random_number) ? cout << "Guess Lower!" : cout <<  "Guess Higher";
};

int main()
{
	int guess;
	srand((unsigned)time(0));
	game_information guess_data =
	{
		0,
		rand() % 100 + 1
	};

	// Introduction:
	cout << "Guess the Number.\n";

	// Instance of game:
	do
	{
		cout << "Enter your guess: ";
		guess = check_input();
		if (guess != guess_data.random_number){
		gives_hint(guess, guess_data.random_number);
		}
		cout << endl;
		guess_data.total_attemps++;
	} while (guess != guess_data.random_number);
	cout << "You got it in " << guess_data.total_attemps << "!\n"
		"Way to go!";
	cout << "DONE!";
}

// Gets an input from the user and if it's a number returns it otherwise, it prompts
// the user to enter another response.
// return: int guess
int check_input()
{
	string guess;
	getline(cin, guess);
	while (!is_digit(guess))
	{
		cout << "Your input was invalid. Please enter a number: ";
		getline(cin, guess);
	}
	return stoi(guess);
}

// Checks if a string is a number.
// Param: string guess
// Return: bool
bool is_digit(string guess)
{
	for (char c : guess)
	{
		if (!isdigit(c))
		{
			return false;
		}
	}
	return true;
}