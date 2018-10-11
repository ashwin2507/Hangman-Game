#include <iostream>
#include "puzzle.h"
#include "fuse.h"

using namespace std;

int main() {

  // Define the solution and create the puzzle

  string solution;
  cout << "Enter solution string: ";
  getline(cin, solution);
  Puzzle puzzle{solution};
  for(int i=0; i<80; ++i) cout << endl;

  // Define the other local variables

  Fuse fuse{8};              // The firecracker fuse object
  char guess;                // Temporary character to receive the player's guesses
  string proposed_solution;  // Temporary string to receive the player's guess
  bool is_winner = false;    // true if the player won

  // Explain the rules

  cout << "         =================" << endl
       << "             B O O M !"     << endl 
       << "         =================" << endl << endl;
  cout << "Enter lower case letters to guess, " << endl
       << "! to propose a solution," << endl
       << "0 to exit." << endl << endl;
  
  while(true) {

    // Print the board and obtain a guess
    cout << endl << endl << fuse.to_string() << puzzle.to_string() << ": ";
    cin >> guess;

    // If the guess is zero, exit
    if (guess == '0') {
      exit(0);

    // If the guess is an exclamation, obtain and check their guess
    } else if (guess == '!') {
      cout << "Disarming the firecracker - what is the solution? ";
      cin.ignore();
      getline(cin, proposed_solution);
      is_winner = puzzle.solve(proposed_solution);
      break;

    // Otherwise, check their guess
    } else {
      if (puzzle.guess(guess)) {
        if (!fuse.burn()) break;
       } else {
        cerr << "Invalid character - try again" << endl;
      }
    }
  }

  if (is_winner) {
    cout << "*** W I N N E R ***" << endl;
  } else {
    cout << "###### BOOM ######" << endl;
    cout << "The answer was: '" << puzzle.get_solution() << "'" << endl;
  }
}
