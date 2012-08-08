#include <iostream>
#include <vector>
using namespace std;

int dp[1000+1];

void solve(int idx, int sum, const vector<pair<int, int> >& cards)
{
  if (sum > 1000)
    return;

  if (idx >= cards.size()) {
    ++dp[sum];
    return;
  }

  for (int i = 0; i <= cards[idx].second; ++i)
    solve(idx+1, sum+cards[idx].first*i, cards);
}

int main()
{
  int m;
  while (cin >> m) {
    if (m == 0)
      break;

    vector<pair<int, int> > cards(m);
    for (int i = 0; i < m; ++i)
      cin >> cards[i].first >> cards[i].second;

    for (int i = 0; i <= 1000; ++i)
      dp[i] = 0;
    solve(0, 0, cards);

    int g;
    cin >> g;
    for (int i = 0; i < g; ++i) {
      int n;
      cin >> n;
      cout << dp[n] << endl;
    }
  }
  return 0;
}
