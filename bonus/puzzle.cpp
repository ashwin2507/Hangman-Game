#include "puzzle.h"

// Returns true if char is in solution, false if not
// Throws Bad_char if char is invalid
bool Puzzle::guess(char c) {
  if (c<'a' || c>'z' || _guesses[c]) throw Bad_char{ };
  _guesses[c] = true;
  for (char a : _solution) {
    if (a == c) return true;
  }
  return false;
}

bool Puzzle::solve(string proposed_solution) {
  return (proposed_solution == _solution);
}

string Puzzle::to_string() {
  string result = "";
  for (char c: _solution) 
    result += _guesses[c] ? c : '_';
  return result;
}

string Puzzle::get_solution() {
  return _solution;
}


