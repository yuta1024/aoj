#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int n;

void solve(vector<int>& sq, int idx)
{
  bool output = true;
  for (int i = 0; i < n-1; ++i) {
    if (sq[i] < sq[i+1]) {
      output = false;
      break;
    }
  }

  if (output) {
    printf("%d", sq[0]);
    for (int i = 1; i < n; ++i) {
      if (sq[i] == 0)
	break;
      printf(" %d", sq[i]);
    }
    puts("");
  }

  int init = 1;
  if (idx != 0 && sq[idx-1] < sq[idx])
    init = sq[idx] - sq[idx-1];

  for (int i = init; sq[idx]-i > 0; ++i) {
    sq[idx] -= i;
    sq[idx+1] += i;
    solve(sq, idx+1);
    sq[idx+1] -= i;
    sq[idx] += i;
  }
}

int main()
{
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;
    vector<int> sq(n, 0);
    sq[0] = n;
    solve(sq, 0);
  }
  return 0;
}
