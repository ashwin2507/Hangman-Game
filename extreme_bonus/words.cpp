#include "words.h"
#include <iostream>
#include <fstream>

string Words::get_word() {
    return words[rand() % words.size()];
}

Words::Words(string filename) {
  srand(time(NULL));
  try {
    string word;
    ifstream ifs;
    ifs.open(filename, ifstream::in);
    while (getline(ifs, word)) {
      words.push_back(word);
    }
    ifs.close();

  } catch(exception e) {
    cerr << "Unable to load wordlist: " << filename << endl;
    exit(1);
  }
}

