#include <iostream>
#include <string>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int main()
{
  int W, H;
  while (cin >> W >> H) {
    if ((W|H) == 0)
      break;

    int x = 1, y = 1, d = 3;
    for ( ; ; ) {
      string cmd;
      cin >> cmd;
      if (cmd == "FORWARD") {
	int k;
	cin >> k;
	while (k-- && 
	       1 <= x + dx[d] && x + dx[d] <= W && 
	       1 <= y + dy[d] && y + dy[d] <= H) {
	  x += dx[d];
	  y += dy[d];
	}
      } else if (cmd == "BACKWARD") {
	int k;
	cin >> k;
	while (k-- &&
	       1 <= x + dx[(d+4-2)%4] && x + dx[(d+4-2)%4] <= W &&
	       1 <= y + dy[(d+4-2)%4] && y + dy[(d+4-2)%4] <= H) {
	  x += dx[(d+4-2)%4];
	  y += dy[(d+4-2)%4];
	}
      } else if (cmd == "RIGHT") {
	d = (d + 1) % 4;
      } else if (cmd == "LEFT") {
	d = (d + 4 - 1) % 4;
      } else {
	break;
      }
    }
    cout << x << " " << y << endl;
  }
  return 0;
}
