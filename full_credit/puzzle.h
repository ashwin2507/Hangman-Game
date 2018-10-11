#include <string>
#include <functional>
using namespace std;

class Puzzle {
  public:
    Puzzle(string solution) : _solution{solution} {
        _guesses[' '] = true; 
    }
    bool guess(char c);                   // true if valid guess
    bool solve(string proposed_solution); // true if correctly guessed
    string to_string();
    string get_solution();
  private:
    string _solution;
    bool _guesses[255] = {false};
};
