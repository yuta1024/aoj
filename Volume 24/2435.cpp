#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
#include <cstring>
using namespace std;

const int INF = 1 << 30;
const double EPS = 1e-10;

int main()
{
  int m;
  while (cin >> m) {
    map<string, pair<int, int> > var;
    for (int i = 0; i < m; ++i) {
      string name;
      int lb, ub;
      cin >> name >> lb >> ub;
      var[name] = make_pair(lb, ub);
    }

    int n;
    cin >> n;

    vector<string> e(n);
    for (int i = 0; i < n; ++i)
      cin >> e[i];

    bool correct = true;
    stack<vector<int> > stk;
    for (int k = 0; k < n; ++k) {
      if (isdigit(e[k][0])) {
        stk.push(vector<int>(1, atoi(e[k].c_str())));
      } else if (isalpha(e[k][0])) {
        vector<int> tmp;
        for (int i = var[e[k]].first; i <= var[e[k]].second; ++i)
          tmp.push_back(i);
        stk.push(tmp);
      } else {
        vector<int> b = stk.top();
        stk.pop();
        vector<int> a = stk.top();
        stk.pop();

        set<int> s;
        if (e[k] == "+") {
          for (unsigned int i = 0; i < a.size(); ++i) {
            for (unsigned int j = 0; j < b.size(); ++j)
              s.insert((a[i] + b[j]) % 256);
          }
        } else if (e[k] == "-") {
          for (unsigned int i = 0; i < a.size(); ++i) {
            for (unsigned int j = 0; j < b.size(); ++j)
              s.insert((a[i] - b[j] + 256) % 256);
          }        
        } else if (e[k] == "*") {
          for (unsigned int i = 0; i < a.size(); ++i) {
            for (unsigned int j = 0; j < b.size(); ++j)
              s.insert((a[i] * b[j]) % 256);
          }
        } else {
          for (unsigned int i = 0; i < a.size(); ++i) {
            for (unsigned int j = 0; j < b.size(); ++j) {
              if (b[j] == 0) {
                correct = false;
                goto END;
              }
              s.insert((a[i] / b[j]) % 256);
            }
          }
        }

        vector<int> r;
        for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
          r.push_back(*it);
        stk.push(r);
      }
    }

  END:
    if (correct)
      cout << "correct" << endl;
    else
      cout << "error" << endl;
  }

  return 0;
}
