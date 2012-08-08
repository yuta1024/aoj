#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  vector<vector<int> > p(2, vector<int>(10));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 10; ++j)
      cin >> p[i][j];
  }
  sort(p[0].begin(), p[0].end(), greater<int>());
  sort(p[1].begin(), p[1].end(), greater<int>());
  cout << p[0][0]+p[0][1]+p[0][2] << " " << p[1][0]+p[1][1]+p[1][2] << endl;
  return 0;
}
