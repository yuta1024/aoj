#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using namespace std;

typedef struct
{
  short d;
  string c1, c2;
} Path;

class State
{
public:
  short pos, cap;
  int cost;
  State(short _pos, short _cap, int _cost)
    :pos(_pos), cap(_cap), cost(_cost) {}
  bool operator < (const State& st) const
  {
    return this->cost > st.cost;
  }
};

const short INF = 10000;
const int MAX_N = 3000;

Path path[MAX_N];
bool LGP[MAX_N];

int main()
{
  int N, M, cap;
  while (cin >> N >> M >> cap) {
    if((N|M|cap) == 0)
      break;

    for (int i = 0; i < MAX_N; ++i)
      LGP[i] = false;

    string src, dest;
    cin >> src >> dest;

    int cnt = 0;
    map<string, short> index;
    for (int i = 0; i < N; ++i) {
      cin >> path[i].c1 >> path[i].c2 >> path[i].d;
      if (index.find(path[i].c1) == index.end())
	index[path[i].c1] = cnt++;
      if (index.find(path[i].c2) == index.end())
	index[path[i].c2] = cnt++;
    }

    for (int i = 0; i < M; ++i) {
      string s;
      cin >> s;
      LGP[index.find(s)->second] = true;
    }

    vector< vector<short> > cost(index.size(), vector<short>(index.size(), INF));
    for (int i = 0; i < N; ++i) {
      short int c1 = index.find(path[i].c1)->second;
      short int c2 = index.find(path[i].c2)->second;
      cost[c1][c2] = cost[c2][c1] = path[i].d;
    }

    int ans = -1;
    short destIndex = index.find(dest)->second;
    priority_queue<State> que;
    que.push(State(index.find(src)->second, cap*10, 0));
    set<State> visited;
    while (!que.empty()) {
      State st = que.top();
      que.pop();

      if (st.pos == destIndex) {
	ans = st.cost;
	break;
      }

      if (visited.find(st) != visited.end())
	continue;

      visited.insert(st);

      if (LGP[st.pos])
	st.cap = cap * 10;

      for (unsigned int i = 0; i < cost[st.pos].size(); ++i) {
	if (st.cap < cost[st.pos][i])
	  continue;
	State next(i, st.cap-cost[st.pos][i], st.cost+cost[st.pos][i]);
	if (visited.find(next) == visited.end())
	  que.push(next);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
