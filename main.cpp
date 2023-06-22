// JAAR
// 06/22/2023
// Guessing Game
// Version 2


// Creates a guessing game where the user can guess a random number that is produced
// by the program. The user can play several times consecutively and can see their
// average guesses presented at the end as well as each games stats.

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

// TODO: Use the (esc) key to exit the program.

struct game_information
{
	int total_attemps;
	int random_number;
};

bool is_digit(string guess);
int check_input();
void game_instance(int& guess, game_information& guess_data);
inline void gives_hint(const int& guess, const int& random_number)
{ (guess > random_number) ? cout << "Guess Lower!" : cout <<  "Guess Higher"; };

int main()
{
	vector<game_information*> game_logs;
	string response;
	do
	{
		int guess;
		srand((unsigned)time(0));
		game_information* game = new game_information
		{
			0,
			rand() % 100 + 1
		};
		game_logs.push_back(game);
		cout << "Guess the Number.\n";
		cout << game->random_number << "\n";
		game_instance(guess, *game);
		cout << "You got it in " << game->total_attemps << "!\n"
			"Way to go!\n";
		cout << "Do you want to play again?: ";
		getline( cin, response );
	} while ( response == "yes" );
	int count = 0, total_guesses = 0;
	/*	!check the address of the data and ensure it is the same as the address above.
		!check to see if there is an issue printing it out this way in the for loop as a vector.
	*/
	for (game_information* game_instance : game_logs)
	{
		cout << "For Game #" << count + 1 << " the random number is: " << game_instance->random_number << "\n";
		cout << "\tYou guessed the right answer in " << game_instance->total_attemps << " tries.\n";
		total_guesses += game_instance->total_attemps;
		count++;
	}
	cout << "You played a total of " << count << " games today with an average of "
		<< (double) total_guesses / count << '\n';
	cout << "DONE!";
}

// Generates a single instance of the guessing game.
// Param: int& guess, game_information& game
void game_instance(int& guess, game_information& game)
{
	do
	{
		cout << "Enter your guess: ";
		guess = check_input();
		if (guess != game.random_number) {
			gives_hint(guess, game.random_number);
		}
		cout << endl;
		game.total_attemps++;
	} while (guess != game.random_number);
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
