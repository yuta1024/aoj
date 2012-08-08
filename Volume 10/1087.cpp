#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int n, m, p;
string s;
bool error = false;
vector<pair<string, vector<int> > > unit;

int getUnitIndex(const vector<int>& d)
{
  int ret = -1;
  for (int i = 0; i < unit.size(); ++i) {
    bool same = true;
    for (int j = 0; j < unit[i].second.size(); ++j) {
      if (unit[i].second[j] != d[j])
	same = false;
    }
    if (same)
      ret = i;
  }
  return ret;
}

int getUnitIndex(const string& u)
{
  int ret = -1;
  for (int i = 0; i < unit.size(); ++i) {
    if (unit[i].first == u)
      ret = i;
  }
  return ret;
}

vector<int> p_formula();

vector<int> p_variable()
{
  string ret = "";
  while (isalpha(s[p]))
    ret += s[p++];
  return unit[getUnitIndex(ret)].second;
}

vector<int> p_factor()
{
  if (s[p] == '(') {
    ++p;
    vector<int> ret =  p_formula();
    ++p;
    return ret;
  } else {
    return p_variable();
  }
}

vector<int> p_term()
{
  vector<int> lhs = p_factor();
  for ( ; ; ) {
    if (s[p] == '*' || s[p] == '/') {
      char op = s[p];
      ++p;
      vector<int> rhs = p_factor();
      for (int i = 0; i < lhs.size(); ++i) {
	if (op == '*')
	  lhs[i] += rhs[i];
	else
	  lhs[i] -= rhs[i];
      }

    } else {
      break;
    }
  }
  return lhs;
}

vector<int> p_formula()
{
  vector<int> lhs = p_term();
  for ( ; ; ) {
    if (s[p] == '+' || s[p] == '-') {
      ++p;
      vector<int> rhs = p_term();
      bool same = true;
      for (int i = 0; i < lhs.size(); ++i) {
	if (lhs[i] != rhs[i])
	  same = false;
      }
      if (!same)
	error = true;
    } else {
      break;
    }
  }
  return lhs;
}

int main()
{
  while (cin >> n >> m >> p) {
    if ((n|m|p) == 0)
      break;

    unit.clear();

    for (int i = 0; i < m; ++i) {
      string derived;
      cin >> derived;
      vector<int> d(n);
      for (int j = 0; j < n; ++j)
	cin >> d[j];
      unit.push_back(make_pair(derived, d));
    }

    string t;
    cin >> t;
    t += '@';

    map<string, string> var;
    for (int i = 0; i < p; ++i) {
      string v, D;
      cin >> v >> D;
      var[v] = D;
    }

    s = "";
    for (int i = 0; i < t.size(); ++i) {
      string v = "";
      while (isalpha(t[i]))
	v += t[i++];
      if (v != "")
	s += var[v];
      s += t[i];
    }

    p = 0;
    error = false;
    vector<int> ans = p_formula();

    if (error) {
      cout << "error" << endl;
    } else {
      int ansIndex = getUnitIndex(ans);
      if (ansIndex == -1)
	cout << "undefined" << endl;
      else
	cout << unit[ansIndex].first << endl;
    }
  }
  return 0;
}
