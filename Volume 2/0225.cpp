#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void solve(int v, vector<int>& visited, const vector<vector<int> >& deg)
{
  visited[v] = 1;
  for (int i = 0; i < deg.size(); ++i) {
    if (deg[v][i] != 0 && !visited[i])
      solve(i, visited, deg);
  }
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<vector<int> > deg(26, vector<int>(26, 0));
    set<char> v;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      ++deg[s[0]-'a'][s[s.size()-1]-'a'];
      v.insert(s[0]);
    }

    vector<int> visited(26, 0);
    solve(0, visited, deg);
    bool connected = true;
    int cnt = 0;
    for (int i = 1; i < 26; ++i) {
      if (visited[i])
	++cnt;
    }
    if (cnt != v.size()-1)
      connected = false;
    
    bool euler = true;
    for (int i = 0; i < 26; ++i) {
      int in = 0, out = 0;
      for (int j = 0; j < 26; ++j) {
	in += deg[j][i];
	out += deg[i][j];
      }
      if (in != out)
	euler = false;
    }

    if (connected && euler)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
