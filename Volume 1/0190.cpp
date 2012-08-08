#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

const int INF = 1 << 28;

int main()
{
  vector<vector<int> > table(13);
  table[0].push_back(2);
  table[1].push_back(2);
  table[1].push_back(5);
  table[2].push_back(0);
  table[2].push_back(1);
  table[2].push_back(3);
  table[2].push_back(6);
  table[3].push_back(2);
  table[3].push_back(7);
  table[4].push_back(5);
  table[5].push_back(1);
  table[5].push_back(4);
  table[5].push_back(6);
  table[5].push_back(9);
  table[6].push_back(2);
  table[6].push_back(5);
  table[6].push_back(7);
  table[6].push_back(10);
  table[7].push_back(3);
  table[7].push_back(6);
  table[7].push_back(8);
  table[7].push_back(11);
  table[8].push_back(7);
  table[9].push_back(5);
  table[9].push_back(10);
  table[10].push_back(6);
  table[10].push_back(9);
  table[10].push_back(11);
  table[10].push_back(12);
  table[11].push_back(7);
  table[11].push_back(10);
  table[12].push_back(10);

  vector<vector<int> > MH(13, vector<int>(13, INF));
  for (unsigned int i = 0; i < table.size(); ++i) {
    for (unsigned int j = 0; j < table[i].size(); ++j)
      MH[i][table[i][j]] = 1;
  }

  for (int i = 0; i < 13; ++i)
    MH[i][i] = 0;

  for (int k = 0; k < 13; ++k) {
    for (int i = 0; i < 13; ++i) {
      for (int j = 0; j < 13; ++j)
	MH[i][j] = min(MH[i][j], MH[i][k]+MH[k][j]);
    }
  }

  vector<int> p(13);
  while (cin >> p[0]) {
    if (p[0] == -1)
      break;

    for (unsigned int i = 1; i < p.size(); ++i)
      cin >> p[i];

    string s;
    const string g = "0123456789AB0";
    for (unsigned int i = 0; i < p.size(); ++i) {
      if (p[i] == 10)
	s += "A";
      else if (p[i] == 11)
	s += "B";
      else
	s += ('0' + p[i]);
    }

    int ans = -1;
    queue<pair<int, string> > que;
    que.push(make_pair(0, s));
    set<string> visited;
    while (!que.empty()) {
      const pair<int, string> st = que.front();
      que.pop();

      if (st.first > 20)
	continue;

      if (st.second == g) {
	ans = st.first;
	break;
      }

      visited.insert(st.second);
      vector<int> zero;
      for (unsigned int i = 0; i < st.second.size(); ++i) {
	if (st.second[i] == '0')
	  zero.push_back(i);
      }

      for (unsigned int i = 0; i < zero.size(); ++i) {
	for (unsigned int j = 0; j < table[zero[i]].size(); ++j) {
	  s = st.second;
	  swap(s[zero[i]], s[table[zero[i]][j]]);

	  int cost = 0;
	  for (unsigned int k = 0; k < s.size(); ++k) {
	    if (s[k] == '0')
	      cost += min(MH[0][k], MH[12][k]);
	    else if (s[k] == 'A')
	      cost += MH[10][k];
	    else if (s[k] == 'B')
	      cost += MH[11][k];
	    else
	      cost += MH[s[k]-'0'][k];
	  }
	  cost /= 2;
	  if (cost + st.first > 20)
	    continue;

	  if (visited.find(s) == visited.end()) {
	    visited.insert(s);
	    que.push(make_pair(st.first+1, s));
	  }
	}
      }
    }

    if (ans == -1)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
