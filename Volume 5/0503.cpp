#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1 << 30;

class State
{
public:
  int cost, op;
  vector<int> tray;
  State(vector<int> _tray = vector<int>(), int _cost = 0, int _op = -1)
    :cost(_cost), op(_op)
  {
    tray = _tray;
  }

  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

inline int ntz(int bit)
{
  int res = __builtin_popcount((~bit)&(bit-1));
  if (res == 32)
    res = INF;
  return res;
}

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<int> tray(3, 0);
    for (int i = 0; i < tray.size(); ++i) {
      int num;
      cin >> num;
      for (int j = 0; j < num; ++j) {
	int bit;
	cin >> bit;
	tray[i] |= 1 << (n-bit);
      }
    }

    int ans = -1;
    State st, next;
    priority_queue<State> que;
    que.push(State(tray));
    const int FIN = (1 << n) - 1;
    while (!que.empty()) {
      st = que.top();
      que.pop();

      if (st.tray[0] == FIN || st.tray[2] == FIN) {
	ans = st.cost;
	break;
      }

      if (st.cost > m)
	break;

      int A = ntz(st.tray[0]), B = ntz(st.tray[1]), C = ntz(st.tray[2]);

      ++st.cost;
      // A -> B
      if (st.tray[0] != 0 && st.op !=  1 && A < B) {
	next = st;
	next.tray[0] ^= (1 << A);
	next.tray[1] |= (1 << A);
	next.op = 0;
	que.push(next);
      }

      if (st.tray[1] != 0) {
	// B -> A
	if (st.op != 0 && B < A) {
	  next = st;
	  next.tray[1] ^= (1 << B);
	  next.tray[0] |= (1 << B);
	  next.op = 1;
	  que.push(next);
	}

	// B -> C
	if (st.op != 3 && B < C) {
	  next = st;
	  next.tray[1] ^= (1 << B);
	  next.tray[2] |= (1 << B);
	  next.op = 2;
	  que.push(next);
	}
      }

      // C -> B
      if (st.tray[2] && st.op !=  2 && C < B ) {
	next = st;
	next.tray[2] ^= (1 << C);
	next.tray[1] |= (1 << C);
	next.op = 3;
	que.push(next);
      }
    }

    cout << ans << endl;
  }
  return 0;
}
