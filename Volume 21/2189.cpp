#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;

    vector<int> v;
    for (unsigned int i = 0; i < s.size(); ++i)
      v.push_back(s[i]-'0');

    int turn = 0;
    while (v.size() >= 2) {
      int a = v.back();
      v.pop_back();
      int b = v.back();
      v.pop_back();

      int sum = a + b;
      if (sum >= 10)
	v.push_back(sum/10);
      v.push_back(sum%10);
      ++turn;
    }

    if (turn & 1)
      cout << "Fabre wins." << endl;
    else
      cout << "Audrey wins." << endl;
  }
  return 0;
}
