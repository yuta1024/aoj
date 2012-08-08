#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int N;
string words[10], substr[10][10], memo[1 << 10][10];

inline string getMin(const string& lhs, const string& rhs)
{
  if (lhs == "")
    return rhs;
  else if (rhs == "")
    return lhs;

  if (lhs.size() == rhs.size()) {
    if (lhs <= rhs)
      return lhs;
    return rhs;
  }

  if (lhs.size() < rhs.size())
    return lhs;
  else
    return rhs;
}

string solve(int S, int v)
{
  if (memo[S][v] != "")
    return memo[S][v];

  if (S == (1 << N)-1)
    return "";

  string ret = "";
  for (int i = 0; i < N; ++i) {
    if (!(S & (1 << i)))
      ret = getMin(ret, substr[v][i]+solve(S | (1 << i), i));
  }
  return memo[S][v] = ret;
}

int main()
{
  while (cin >> N) {
    if (N == 0)
      break;

    // init
    for (int i = 0; i < (1 << N); ++i) {
      for (int j = 0; j < N; ++j)
	memo[i][j] = "";
    }

    for (int i = 0; i < N; ++i)
      cin >> words[i];

    int S = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
	if (i == j)
	  continue;
	substr[i][j] = words[j];
	if (words[i].find(words[j]) != string::npos) {
	  if (!(S & (1 << i)))
	    S |= 1 << j;
	} else {
	  for (unsigned int k = 0; k < words[i].size(); ++k) {
	    string s = words[i].substr(k);
	    string::size_type index = words[j].find(s);
	    if (index == 0) {
	      substr[i][j] = words[j].substr(s.size());
	      break;
	    }
	  }
	}
      }
    }

    string ans = "";
    for (int i = 0; i < N; ++i) {
      if (!(S & (1 << i)))
	ans = getMin(ans, words[i]+solve(S | (1 << i), i));
    }
    cout << ans << endl;
  }
  return 0;
}
