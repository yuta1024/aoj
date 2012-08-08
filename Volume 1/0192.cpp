#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

class Parking
{
public:
  int id, time;

  Parking(int _id = -1, int _time = INF)
    :id(_id), time(_time) {}
};

int main()
{
  int n, m;
  while (cin >> m >> n) {
    if ((n|m) == 0)
      break;

    vector<int> cars(n);
    for (int i = 0; i < n; ++i)
      cin >> cars[i];

    int id = 0;
    vector<int> ans;
    vector<Parking> p1(m), p2(m);
    for (int time = 0; ans.size() < n; ++time) {
      for (int i = 0; i < m; ++i) {
	if (p1[i].id != -1)
	  --p1[i].time;
	if (p2[i].id != -1)
	  --p2[i].time;
      }

      for (int i = 0; i < m; ++i) {
	bool out = false;
	if (p1[i].id != -1 && p1[i].time <= 0) {
	  ans.push_back(p1[i].id);
	  p1[i].id = -1;
	  p1[i].time = INF;
	  out = true;
	}

	if (p1[i].id == -1 && p2[i].id != -1 && p2[i].time <= 0) {
	  ans.push_back(p2[i].id);
	  p2[i].id = -1;
	  p2[i].time = INF;
	}

	if (out && p2[i].id != -1) {
	  p1[i].id = p2[i].id;
	  p1[i].time = p2[i].time;
	  p2[i].id = -1;
	  p2[i].time = INF;
	}
      }

      while (id < n && id * 10 <= time) {
	bool in = false;
	for (int i = 0; i < m; ++i) {
	  if (p1[i].id == -1) {
	    p1[i].id = id;
	    p1[i].time = cars[id++];
	    in = true;
	    break;
	  }
	}

	if (in)
	  continue;

	int minIndex = -1;
	for (int i = 0; i < m; ++i) {
	  if (p2[i].id != -1)
	    continue;

	  if (p1[i].time >= cars[id]) {
	    if (minIndex == -1 || p1[i].time < p1[minIndex].time)
	      minIndex = i;
	  }
	}

	if (minIndex != -1) {
	  p2[minIndex].id = p1[minIndex].id;
	  p2[minIndex].time = p1[minIndex].time;
	  p1[minIndex].id = id;
	  p1[minIndex].time = cars[id++];
	  continue;
	}

	for (int i = 0; i < m; ++i) {
	  if (p2[i].id != -1)
	    continue;

	  if (p1[i].time < cars[id]) {
	    if (minIndex == -1 || p1[i].time > p1[minIndex].time)
	      minIndex = i;
	  }
	}

	if (minIndex != -1) {
	  p2[minIndex].id = p1[minIndex].id;
	  p2[minIndex].time = p1[minIndex].time;
	  p1[minIndex].id = id;
	  p1[minIndex].time = cars[id++];
	  continue;
	}

	break;
      }
    }

    for (int i = 0; i < n-1; ++i)
      cout << ans[i]+1 << " ";
    cout << ans[n-1]+1 << endl;

  }
  return 0;
}
