#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    map<string, int> price;
    for (int i = 0; i < n; ++i) {
      string s;
      int p;
      cin >> s >> p;
      price[s] = p;
    }

    int m;
    cin >> m;
    map<string, vector<string> > alchemy;
    for (int i = 0; i < m; ++i) {
      string s;
      cin >> s;
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
	string q;
	cin >> q;
	alchemy[s].push_back(q);
      }
    }

    bool update = true;
    while (update) {
      update = false;
      for (map<string, vector<string> >::iterator it = alchemy.begin(); it != alchemy.end(); ++it) {
	int sum = 0;
	for (int i = 0; i < it->second.size(); ++i)
	  sum += price[it->second[i]];

	if (price[it->first] > sum) {
	  price[it->first] = sum;
	  update = true;
	  break;
	}
      }
    }

    string target;
    cin >> target;
    cout << price[target] << endl;
  }
  return 0;
}
