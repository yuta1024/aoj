#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int ds[] = {5, 9, 13};
int dx[] = {0, 0, -1, 0, 1, -1, -1, 1, 1, 0, -2, 0, 2};
int dy[] = {0, -1, 0, 1, 0, -1, 1, 1, -1, -2, 0, 2, 0};

int main()
{
  int x, y, s;
  vector<vector<int> > paper(10, vector<int>(10, 0));
  while (scanf("%d,%d,%d", &x, &y, &s) != EOF) {
    for (int i = 0; i < ds[s-1]; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx >= 0 && xx < 10 && yy >= 0 && yy < 10)
	++paper[yy][xx];
    }
  }

  int plain = 0, con = 0;
  for (int i = 0; i < paper.size(); ++i) {
    for (int j = 0; j < paper[0].size(); ++j) {
      if (paper[i][j] == 0)
	++plain;
      con = max(con, paper[i][j]);
    }
  }
  
  cout << plain << endl << con << endl;

  return 0;
}
