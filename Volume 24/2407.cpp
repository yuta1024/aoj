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
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
  string s;
  while (cin >> s) {
    if (s[0] == 'x' && s[s.size()-1] == 'x')
      cout << "x" << endl;
    else
      cout << "o" << endl;
  }
  return 0;
}
