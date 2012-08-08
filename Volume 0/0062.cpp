#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string s;
  while (cin >> s) {
    vector<int> prev;
    for (unsigned int i = 0; i < s.size(); ++i)
      prev.push_back(s[i]-'0');

    while (prev.size() != 1) {
      vector<int> next;
      for (unsigned int i = 1; i < prev.size(); ++i)
	next.push_back((prev[i-1]+prev[i])%10);
      prev = next;
    }

    cout << prev[0] << endl;
  }
  return 0;
}
