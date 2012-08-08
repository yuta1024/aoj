#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
using namespace std;

int main()
{
  int N;
  bool first = true;
  while (cin >> N) {
    if (!first)
      cout << endl;

    int point[4][13], rate[10];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 13; ++j)
	cin >> point[i][j];
    }
    rate[0] = 0;
    for (int i = 0; i < 9; ++i)
      cin >> rate[i+1];

    vector<pair<int, int> > card(5);
    for (int loop = 0; loop < N; ++loop) {
      set<char> suit;
      map<int, int> cnt;

      for (int i = 0; i < 5; ++i) {
	string s;
	cin >> s;
	if (s[0] == 'A')
	  card[i].first = 1;
	else if (s[0] == 'T')
	  card[i].first = 10;
	else if (s[0] == 'J')
	  card[i].first = 11;
	else if (s[0] == 'Q')
	  card[i].first = 12;
	else if (s[0] == 'K')
	  card[i].first = 13;
	else
	  card[i].first = s[0] - '0';
 
	if (s[1] == 'S')
	  card[i].second = 0;
	else if (s[1] == 'C')
	  card[i].second = 1;
	else if (s[1] == 'H')
	  card[i].second = 2;
	else
	  card[i].second = 3;

	suit.insert(s[1]);
	++cnt[card[i].first];
      }
      sort(card.begin(), card.end());

      vector<int> same;
      for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
	same.push_back(it->second);
      sort(same.begin(), same.end(), greater<int>());

      bool straight = true;
      for (int i = 1; i < 5; ++i) {
	if (card[i-1].first+1 != card[i].first)
	  straight = false;
      }
      bool straight_A = false;
      if (card[0].first == 1 && card[1].first == 10 && card[2].first == 11 && card[3].first == 12 && card[4].first == 13)
	straight_A = true;

      int rank = 0;
      if (suit.size() == 1 && straight_A)
	rank = 9;
      else if (suit.size() == 1 && straight)
	rank = 8;
      else if (same[0] == 4)
	rank = 7;
      else if (same[0] == 3 && same[1] == 2)
	rank = 6;
      else if (suit.size() == 1)
	rank = 5;
      else if (straight || straight_A)
	rank = 4;
      else if (same[0] == 3)
	rank = 3;
      else if (same[0] == 2 && same[1] == 2)
	rank = 2;
      else if (same[0] == 2)
	rank = 1;

      int ans = 0;
      for (int i = 0; i < 5; ++i)
	ans += point[card[i].second][card[i].first-1];
      ans *= rate[rank];
      cout << ans << endl;
    }
    first = false;
  }
  return 0;
}
