#include <string>
#include <vector>

using namespace std;

class Words {
  public:
    Words(string filename);
    string get_word();
  private:
    vector<string> words;
};

