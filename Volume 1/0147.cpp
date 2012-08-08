#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int time = 0;
  vector<int> seat(17, INF), ans(100);
  for (int i = 0; i < 100; ++i) {
    time = max(time, i*5);
    int people = 2;
    if (i%5 == 1)
      people = 5;

    for ( ; ; ) {
      for (int j = 0; j < seat.size(); ++j) {
	if (seat[j] <= time)
	  seat[j] = INF;
      }

      int con = 0;
      bool in = false;
      for (int j = 0; j < seat.size(); ++j) {
	if (seat[j] == INF) {
	  ++con;
	  if (con == people) {
	    in = true;
	    for (int k = j; k > j-con; --k)
	      seat[k] = time + 17*(i%2) + 3*(i%3) + 19;
	    ans[i] = max(0, time - i*5);
	    break;
	  }
	} else {
	  con = 0;
	}
      }

      if (in)
	break;

      int min_time = INF;
      for (int j = 0; j < seat.size(); ++j)
	min_time = min(min_time, seat[j]);
      time = min_time;
    }
  }

  int n;
  while (cin >> n)
    cout << ans[n] << endl;

  return 0;
}
