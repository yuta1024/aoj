#include <string>
#include <iostream>
#include <vector>
using namespace std;

const string a2p = "peach";
const string p2a = "apple";

int main()
{
  string s;
  vector<string> output;
  while (cin >> s) {
    if (s.find("apple") != string::npos) {
      int rev = s.find("apple");
      for (int i = 0; i < 5; ++i)
	s[i+rev] = a2p[i];
    } else if (s.find("peach") != string::npos) {
      int rev = s.find("peach");
      for (int i = 0; i < 5; ++i)
	s[i+rev] = p2a[i];
    }
    output.push_back(s);
  }

  for (int i = 0; i < output.size()-1; ++i)
    cout << output[i] << " ";
  cout << output[output.size()-1] << endl;
  return 0;
}
