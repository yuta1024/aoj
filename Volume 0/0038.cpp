#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int main()
{
  vector<int> cards(5);
  while (~scanf("%d,%d,%d,%d,%d",
		&cards[0], &cards[1], &cards[2], &cards[3], &cards[4])) {
    sort(cards.begin(), cards.end());

    vector<int> cnt(15, 0);
    for (unsigned int i = 0; i < cards.size(); ++i)
      ++cnt[cards[i]];

    sort(cnt.begin(), cnt.end(), greater<int>());
    if (cnt[0] == 4) {
      cout << "four card" << endl;
    } else if (cnt[0] == 3 && cnt[1] == 2) {
      cout << "full house" << endl;
    } else {
      bool straight = true;
      for (unsigned int i = 1; i < cards.size(); ++i) {
	if (cards[i-1]+1 != cards[i])
	  straight = false;
      }

      if (straight ||
	  (cards[0] == 1 && cards[1] == 10 && cards[2] == 11 && cards[3] == 12 && cards[4] == 13)) {
	cout << "straight" << endl;
      } else if (cnt[0] == 3) {
	cout << "three card" << endl;
      } else if (cnt[0] == 2 && cnt[1] == 2) {
	cout << "two pair" << endl;
      } else if (cnt[0] == 2) {
	cout << "one pair" << endl;
      } else {
	cout << "null" << endl;
      }
    }
  }
  return 0;
}
