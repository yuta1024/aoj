#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 14;

int n;
unsigned int subcnt[MAX_N][MAX_N];
int memo[1 << MAX_N][MAX_N];

unsigned int solve(int S, int v)
{
  if (S == (1 << n)-1)
    return 0;

  if (memo[S][v] != -1)
    return memo[S][v];

  unsigned int ret = 1 << 30;
  for (int i = 0; i < n; ++i) {
    if (!(S & (1 << i)))
      ret = min(ret, solve(S | (1 << i), i)+subcnt[v][i]);
  }
  return memo[S][v] = ret;
}

int main()
{
  while (cin >> n) {
    if (n == 0)
      break;

    vector<string> name(n);
    for (int i = 0; i < n; ++i)
      cin >> name[i];

    for (int i = 0; i < (1 << MAX_N); ++i) {
      for (int j = 0; j < MAX_N; ++j)
	memo[i][j] = -1;
    }

    int S = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	if (i == j)
	  continue;
	subcnt[i][j] = name[j].size();
	if (name[i].find(name[j]) != string::npos) {
	  if (!(S & (1 << i)))
	    S |= 1 << j;
	} else {
	  for (unsigned int k = 0; k < name[i].size(); ++k) {
	    string substr = name[i].substr(k);
	    if (name[j].find(substr) == 0) {
	      subcnt[i][j] = name[j].size() - substr.size();
	      break;
	    }
	  }
	}
      }
    }

    unsigned int ans = 1 << 30;
    for (int i = 0; i < n; ++i) {
      if (!(S & (1 << i)))
	  ans = min(ans, name[i].size()+solve(S | (1 << i), i));
    }
    cout << ans << endl;
  }
  return 0;
}
