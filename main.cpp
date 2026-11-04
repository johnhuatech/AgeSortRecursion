#include <iostream> // Provides standard input and output.
#include <limits> // Provides numeric limits used when clearing invalid input.
using namespace std; // Allows standard-library names to be used without the std:: prefix.

// Recursively search a sorted array; return the matching index or -1.
int recursiveBinarySearch(const int a[], int low, int high, int x) { // Searches within the inclusive range [low, high].
	if (low > high) { // Stops when the search range is empty.
		return -1; // Reports that the value is not present.
	} // Ends the empty-range check.

	const int mid = low + (high - low) / 2; // Finds the middle index while avoiding addition overflow.
	if (a[mid] == x) { // Checks whether the middle value matches the target.
		return mid; // Returns the matching index.
	} // Ends the match check.
	if (x < a[mid]) { // Checks whether the target belongs in the lower half.
		return recursiveBinarySearch(a, low, mid - 1, x); // Searches the lower half recursively.
	} // Ends the lower-half check.
	return recursiveBinarySearch(a, mid + 1, high, x); // Searches the upper half recursively.
} // Ends the recursive search function.

// Let the player enter numeric guesses for an age from 0 to 115.
void guessAge(int age) { // Repeatedly prompts the player until they guess the age or input ends.
	int guess; // Stores the player's current guess.
	while (true) { // Keeps asking until a correct guess or end-of-file.
		cout << "Enter your age guess (0-115): "; // Prompts for a guess.
		if (!(cin >> guess)) { // Detects input that cannot be read as an integer.
			if (cin.eof()) { // Checks whether input has ended.
				return; // Exits the function when there is no more input.
			} // Ends the end-of-file check.
			cout << "Please enter a number.\n"; // Informs the player that the input was invalid.
			cin.clear(); // Resets the input stream's error state.
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards the rest of the invalid input line.
			continue; // Prompts for another guess.
		} // Ends invalid-input handling.

		if (guess < age) { // Checks whether the guess is below the correct age.
			cout << "Too low.\n"; // Tells the player to guess higher.
		} else if (guess > age) { // Checks whether the guess is above the correct age.
			cout << "Too high.\n"; // Tells the player to guess lower.
		} else { // Runs when the guess matches the age.
			cout << "Correct!\n"; // Confirms that the player guessed correctly.
			return; // Ends the guessing function.
		} // Ends the guess comparison.
	} // Ends the guessing loop.
} // Ends the age-guessing function.

int main() { // Starts the program.
	int age; // Stores the age that the player will try to guess.
	cout << "Enter the age to be guessed (0-115): "; // Prompts for the target age.
	if (!(cin >> age) || age < 0 || age > 115) { // Rejects non-integer input and ages outside the allowed range.
		cout << "Please enter an age from 0 to 115.\n"; // Displays the valid age range.
		return 1; // Exits with an error status for invalid input.
	} // Ends target-age validation.
	guessAge(age); // Starts the guessing interaction using the chosen age.
	return 0; // Exits successfully.
} // Ends the program entry point.


