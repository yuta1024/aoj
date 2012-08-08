#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
  int p, t;
} Balloon;

class Vihicle
{
public:
  int p, k, dis, achive;
  Vihicle(int pp, int kk, int dd, int aa)
    :p(pp), k(kk), dd(dis), achive(aa);
  bool operator < (const Vihicle& v) const
  {
    return this->dis > v.dis;
  }
};

int main()
{
  int n;
  while (scanf("%d", &n) != EOF) {
    if (n == 0)
      break;

    vector<Balloon> b;
    for (int i = 0; i < n; ++i)
      scanf("%d %d", &b[i].p, &b[i].t);

    priority_queue<Vihicle> que;
    que.push(0, 0, 0, -1);
    while (!que.empty()) {
      Vihicle v = que.top();
      que.pop();



    }

  }

  return 0;
}
