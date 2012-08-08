#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 10;
const int dx[] = {0, 1, 0, -1, 0};
const int dy[] = {0, 0, 1, 0, -1};

bool solve(vector<vector<int> > state, vector<vector<int> >& ans)
{
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if ((i == 0 && ans[i][j]) || (i > 0 && state[i-1][j])) {
	ans[i][j] = 1;
	for (int d = 0; d < 5; ++d) {
	  int xx = j + dx[d];
	  int yy = i + dy[d];
	  if (0 <= xx && xx < SIZE && 0 <= yy && yy < SIZE)
	    state[yy][xx] ^= 1;
	}
      }
    }
  }

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (state[i][j])
	return false;
    }
  }
  return true;
}

int main()
{
  int n;
  while (cin >> n) {
    while (n--) {
      vector<vector<int> > state(SIZE, vector<int>(SIZE));
      for (int i = 0; i < SIZE; ++i) {
	for (int j = 0; j < SIZE; ++j)
	  cin >> state[i][j];
      }

      for (int i = 0; i < (1 << SIZE); ++i) {
	vector<vector<int> > ans(SIZE, vector<int>(SIZE, 0));
	for (int j = 0; j < SIZE; ++j) {
	  if (i & (1 << j))
	    ans[0][j] = 1;
	}
	if (solve(state, ans)) {
	  for (int i = 0; i < SIZE; ++i) {
	    for (int j = 0; j < SIZE-1; ++j) 
	      cout << ans[i][j] << " ";
	    cout << ans[i][SIZE-1] << endl;
	  }
	  break;
	}
      }
    }
  }
  return 0;
}
