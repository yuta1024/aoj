#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string s;
  while (cin >> s) {
    int flag = 0;
    vector<string> g;
    vector<vector<string> > t;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'e') {
	i += 2;
	if (flag == 1) {
	  t.push_back(g);
	  g.clear();
	}
	flag = 1;
	g.push_back("egg");
      } else {
	i += 6;
	if (flag == 2) {
	  t.push_back(g);
	  g.clear();
	}
	flag = 2;
	g.push_back("chicken");
      }
    }

    if (!g.empty())
      t.push_back(g);

    int maxIndex = 0;
    for (int i = 1; i < t.size(); ++i) {
      if (t[i].size() > t[maxIndex].size())
	maxIndex = i;
    }

    cout << t[maxIndex].back() << endl;
  }
  return 0;
}
