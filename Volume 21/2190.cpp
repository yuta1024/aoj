#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string Chord[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

bool solve(int k, int p, const vector<string>& T, const vector<string>& S)
{
  if (k == 0) {
    if (p == -1)
      return true;
    return false;
  }

  bool ret = false;
  // k+1
  if (S[p] == T[k])
    ret |= solve(max(0, k-1), p-1, T, S);

  // k+2
  if (k-2 >= 0) {
    for (int i = 0; i < 12; ++i) {
      if (Chord[i] == T[k]) {
        if (Chord[(i+1)%12] == S[p])
          ret |= solve(max(0, k-2), p-1, T, S);
        break;
      }
    }
  }

  // k-1
  if (k+1 < (int)T.size()-1) {
    for (int i = 0; i < 12; ++i) {
      if (Chord[i] == T[k]) {
        if (Chord[(12+i-1)%12] == S[p])
          ret |= solve(k+1, p-1, T, S);
        break;
      }
    }
  }

  return ret;
}

int main()
{
  int T;
  cin >> T;
  while  (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> t(n+2), s(m);
    for (int i = 0; i < n; ++i)
      cin >> t[i+1];
    for (int i = 0; i < m; ++i)
      cin >> s[i];

    if (solve(n-1, m-1, t, s) || solve(n, m-1, t, s))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
