#include <iostream>
#include <string>
using namespace std;

int main()
{
  string comp;
  while (cin >> comp) {
    string dec = "";
    for (unsigned int i = 0; i < comp.size(); ++i) {
      if (comp[i] == '@') {
	for (int j = 0; j < (comp[i+1]-'0'); ++j)
	  dec += comp[i+2];
	i += 2;
      } else {
	dec +=  comp[i];
      }
    }
    cout << dec << endl;
  }
  return 0;
}
