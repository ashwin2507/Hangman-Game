#include <iostream>
#include "puzzle.h"
#include "fuse.h"
#include "words.h"

using namespace std;

int main(int argc, char *argv[]) {

  srand(time(NULL));

  // Select a word for the game
  string solution;
  Words wordlist{(argc == 2) ? argv[1] : "wordlist.txt"};
  Puzzle puzzle{wordlist.get_word()};

  // Define the other local variables

  Fuse fuse{8};
  char guess; 
  string proposed_solution;
  bool winner = false;   // true if the player won

  // Explain the rules

  cout << "         =================" << endl
       << "             B O O M !"     << endl 
       << "         =================" << endl << endl;
  cout << "Enter lower case letters to guess, " << endl
       << "! to propose a solution," << endl
       << "0 to exit." << endl << endl;
  
  while(!winner) {

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
      winner = puzzle.solve(proposed_solution);
      break;

    // Otherwise, check their guess
    } else {
      try {
        if (!puzzle.guess(guess)) {
          if (!fuse.burn()) break;
        }
      } catch (Puzzle::Bad_char e) {
        cerr << "Invalid character - try again" << endl;
      }
    }
    winner = puzzle.solved();
  }

  if (winner) {
    cout << "*** W I N N E R ***" << endl;
  } else {
    cout << "###### BOOM ######" << endl;
  }
  cout << "The answer was: '" << puzzle.get_solution() << "'" << endl;
}
