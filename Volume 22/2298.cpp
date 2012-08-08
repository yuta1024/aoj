#include <cstdio>
#include <vector>
using namespace std;

const double EPS = 10e-9;

int main()
{
  int N, K, T, U, V, L;
  while (~scanf("%d %d %d %d %d %d", &N, &K, &T, &U, &V, &L)) {
    vector<int> D(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &D[i]);

    int carrot = 0, D_index = 0;
    double ans = 0.0, Us = 1.0 / U, Vs = 1.0 / V, ksk_time = 0.0;
    for (int i = 0; i < L; ++i) {
      if (i == D[D_index]) {
	if ((ksk_time <= EPS && carrot == 0) || carrot == K)
	  ksk_time = T;
	else
	  ++carrot;
	++D_index;
      }

      if (ksk_time <= EPS && carrot > 0) {
	--carrot;
	ksk_time = T;
      }

      if (ksk_time > EPS) {
	ans += Vs;
	ksk_time -= Vs;
      } else {
	ans += Us;
      }
    }
    printf("%.9f\n", ans);
  }
  return 0;
}
