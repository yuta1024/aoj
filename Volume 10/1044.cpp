#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
  string name, type;
  while (cin >> name >> type) {
    if (type == "X")
      break;

    name[0] = tolower(name[0]);
    vector<string> words;
    if (name.find_first_of("_") != string::npos) {
      int s = 0;
      name += "_";
      for (int i = 0; i < name.size(); ++i) {
	if (name[i] == '_') {
	  words.push_back(name.substr(s, i-s));
	  s = i+1;
	}
      }
    } else {
      int s = 0;
      name += "X";
      for (int i = 0; i < name.size(); ++i) {
	if (isupper(name[i])) {
	  words.push_back(name.substr(s, i-s));
	  name[i] = tolower(name[i]);
	  s = i;
	}
      }
    }

    if (type == "D") {
      cout << words[0];
      for (int i = 1; i < words.size(); ++i)
	cout << "_" << words[i];
    } else {
      if (type == "U")
	words[0][0] = toupper(words[0][0]);
      cout << words[0];

      for (int i = 1; i < words.size(); ++i) {
	words[i][0] = toupper(words[i][0]);
	cout << words[i];
      }
    }
    cout << endl;
  }
  return 0;
}
