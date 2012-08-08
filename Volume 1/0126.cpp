#include <cstdio>
#include <vector>
using namespace std;

const int sx[] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
const int sy[] = {0, 0, 0, 3, 3, 3, 6, 6, 6};

bool valid[9][9];
int puzzle[9][9];

int main()
{
  int n;
  while (~scanf("%d", &n)) {
    for (int dataset = 0; dataset < n; ++dataset) {
      if (dataset != 0)
	puts("");

      for (int i = 0; i < 9; ++i) {
	for (int j = 0; j < 9; ++j) {
	  scanf("%d", &puzzle[i][j]);
	  valid[i][j] = true;
	}
      }

      // horizonal/vertical
      for (int i = 0; i < 9; ++i) {
	vector<int> h_cnt(10, 0), v_cnt(10, 0);
	for (int j = 0; j < 9; ++j) {
	  ++h_cnt[puzzle[i][j]];
	  ++v_cnt[puzzle[j][i]];
	}
	for (int j = 0; j < 9; ++j) {
	  if (h_cnt[puzzle[i][j]] != 1)
	    valid[i][j] = false;
	  if (v_cnt[puzzle[j][i]] != 1)
	    valid[j][i] = false;
	}
      }

      // block
      for (int b = 0; b < 9; ++b) {
	vector<int> cnt(10, 0);
	for (int i = sy[b]; i < sy[b]+3; ++i) {
	  for (int j = sx[b]; j < sx[b]+3; ++j) {
	    ++cnt[puzzle[i][j]];
	  }
	}
	for (int i = sy[b]; i < sy[b]+3; ++i) {
	  for (int j = sx[b]; j < sx[b]+3; ++j) {
	    if (cnt[puzzle[i][j]] != 1)
	      valid[i][j] = false;
	  }
	}
      }

      for (int i = 0; i < 9; ++i) {
	for (int j = 0; j < 9; ++j) {
	  if (valid[i][j])
	    printf(" %d", puzzle[i][j]);
	  else
	    printf("*%d", puzzle[i][j]);
	}
	puts("");
      }
    }
  }
  return 0;
}
