#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int N;
  while (cin >> N) {
    if (N == 0)
      break;

    vector<int> c(N+2);
    for (int i = 0; i < N; ++i)
      cin >> c[i+1];
    // sentinel
    c[0] = INF;
    c[N+1] = -INF;

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= 3; ++j) {
        if (c[i] == j)
          continue;

        int tmp = c[i];
        c[i] = j;

        int up = i, down = i, sum = 0;
        while (c[up] == c[down]) {
          int color = c[up], cnt = 0;
          if (up == i)
            --cnt;

          while (up > 0 && c[up] == color) {
            --up;
            ++cnt;
          }
          while (down <= N && c[down] == color) {
            ++down;
            ++cnt;
          }
          if (cnt >= 4)
            sum += cnt;
          else
            break;
        }

        c[i] = tmp;
        ans = max(ans, sum);
      }
    }
    cout << N-ans << endl;
  }
  return 0;
}
