#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class UnionFind
{
private:
  vector<int> parent, rank;

public:
  UnionFind(int n)
  {
    for (int i = 0; i < n; ++i) {
      parent.push_back(i);
      rank.push_back(0);
    }
  }

  int find(int x)
  {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = find(parent[x]);
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return;

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y])
	++rank[x];
    }
  }

  bool same(int x, int y)
  {
    return find(x) == find(y);
  }
};

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > que;
    for (int i = 0; i < m; ++i) {
      pair<int, pair<int, int> > p;
      cin >> p.second.first >> p.second.second >> p.first;
      que.push(p);
    }

    int ans = 0;
    UnionFind uf(n);
    while (!que.empty()) {
      const pair<int, pair<int, int> > p = que.top();
      que.pop();

      if (!uf.same(p.second.first, p.second.second)) {
	uf.unite(p.second.first, p.second.second);
	ans += p.first;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
