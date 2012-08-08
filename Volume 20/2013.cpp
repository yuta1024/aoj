#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int start;
  string time;
} Train;

class LessTime
{
public:
  bool operator() (const Train& lhs, const Train& rhs)
  {
    if (lhs.time == rhs.time)
      return lhs.start < rhs.start;
    return lhs.time < rhs.time;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Train> train(2*n);
    for (int i = 0; i < 2*n; ++i) {
      cin >> train[i].time;
      if (i&1)
	train[i].start = 0;
      else
	train[i].start = 1;
    }

    sort(train.begin(), train.end(), LessTime());
    int ans = 0, pool = 0;
    for (int i = 0; i < train.size(); ++i) {
      if (train[i].start == 1) {
	if (pool == 0)
	  ++ans;
	else
	  --pool;
      } else {
	++pool;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
