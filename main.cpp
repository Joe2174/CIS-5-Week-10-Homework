#include <iostream>


using std::cout;


// Practice 10 — Your Name
// CIS 5 Week 10 · Gradebook tools
// Explains Functions, Arrays, and Pointers

void printScores(const int scores[], int n) // prints the scores in the array
{
	for (int i = 0; i < n; i++) cout << scores[i] << " "; // traverse array, print each score followed by a space
	cout << "\n";
}

void curve(int scores[], int n, int points) // adds points to every score in the array
{
	for (int i = 0; i < n; i++) // traverse the array
		scores[i] += points; // add points to each score
}

void minMax(const int scores[], int n, int& lo, int& hi) // finds the lowest and highest scores in the array
{
	lo = scores[0]; // initialize lo to the first score
	hi = scores[0]; // initialize hi to the first score
	for (int i = 1; i < n; i++) // traverse the array starting from the second score
	{
		if (scores[i] < lo) lo = scores[i]; // update lo if a lower score is found
		if (scores[i] > hi) hi = scores[i]; // update hi if a higher score is found
	}
	// TODO: start lo and hi at scores[0], then check the rest
}

bool findScore(const int scores[], int n, int target, int* where) // searches for target in the array and returns true if found, false otherwise
{
	for (int i = 0; i < n; i++) // traverse the array
	{
		if (scores[i] == target) // check if the current score matches the target
		{
			if (where != nullptr) *where = i; // if where is not null, store the index of the found score
			return true; // return true since the target was found
		}
	}

  return false;
}

int main() 
{
  int scores[5] = {72, 88, 95, 60, 81};
  const int N = 5;

  cout << "Before: ";
  printScores(scores, N);

  int lo = 0, hi = 0;
  minMax(scores, N, lo, hi);
  cout << "Low: " << lo << "  High: " << hi << "\n";

  curve(scores, N, 5);
  cout << "After curve +5: ";
  printScores(scores, N);

  int at = -1;
  if (findScore(scores, N, 100, &at)) cout << "100 found at index " << at << "\n";
  if (!findScore(scores, N, 50, nullptr)) cout << "50 not found\n";
  return 0;
}
