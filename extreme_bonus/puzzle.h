#include <string>
#include <exception>
using namespace std;

class Puzzle {
  public:
    Puzzle(string solution) : _solution{solution} {_guesses[' '] = true;}
    class Bad_char : public exception { };
    bool guess(char c);                   // true if char is in solution
                                          // throws Bad_char is invalid
    bool solve(string proposed_solution); // true if correctly guessed
    bool solved();       // true if all letters were correctly guessed
    string to_string();
    string get_solution();
  private:
    string _solution;
    bool _guesses[255] = {false};
};
