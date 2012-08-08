#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int W, Q;
  while (cin >> W >> Q) {
    if ((W | Q) == 0)
      break;

    vector<int> wall(W, -1);
    for (int q = 0; q < Q; ++q) {
      string op;
      cin >> op;

      if (op == "s") {
	int id, w;
	cin >> id >> w;

	int cnt = 0, left = -1;
	for (int i = 0; i < W; ++i) {
	  if (wall[i] == -1) {
	    if (left == -1)
	      left = i;
	    ++cnt;
	    if (cnt == w)
	      break;
	  } else {
	    cnt = 0;
	    left = -1;
	  }
	}

	if (cnt == w) {
	  for (int i = left; i < left+w; ++i)
	    wall[i] = id;
	  cout << left << endl;
	} else {
	  cout << "impossible" << endl;
	}
      } else {
	int id;
	cin >> id;
	for (int i = 0; i < W; ++i) {
	  if (wall[i] == id)
	    wall[i] = -1;
	}
      }
    }
    cout << "END" << endl;
  }
  return 0;
}
