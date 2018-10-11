#include "puzzle.h"

bool Puzzle::guess(char c) {
  if (c<'a' || c>'z' || _guesses[c])  {
    return false;
  } else {
    _guesses[c] = true;
    return true;
  }
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


