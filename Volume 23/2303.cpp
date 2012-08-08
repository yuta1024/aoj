#include <cstdio>
#include <vector>
using namespace std;

const double INF = 1e30;

typedef struct
{
  int P, T, V;
  double goal;
} Runner;

int main()
{
  int N, M, L;
  while (~scanf("%d %d %d", &N, &M, &L)) {
    vector<Runner> r(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d %d %d", &r[i].P, &r[i].T, &r[i].V);
      if (r[i].V == 0)
	r[i].goal = INF;
      else
	r[i].goal = L / static_cast<double>(r[i].V);
    }

    vector<vector<double> > p(N, vector<double>(M+1, 1.0));
    for (int i = 0; i < N; ++i) {
      vector<vector<double> > dp(M+1, vector<double>(M+1, 0.0));
      dp[0][0] = 1.0;
      for (int j = 0; j < M; ++j) {
	for (int k = 0; k < M; ++k) {
	  dp[j+1][k]   += dp[j][k] * ((100 - r[i].P) / 100.0);
	  dp[j+1][k+1] += dp[j][k] * (r[i].P / 100.0);
	}
      }
      for (int j = 0; j < M+1; ++j)
	p[i][j] = dp[M][j];
    }

    vector<vector<double> > pp(N, vector<double>(M+1));
    for (int i = 0; i < N; ++i) {
      for (int j = M; j >= 0; --j) {
	pp[i][j] = p[i][j];
	if (j != M)
	  pp[i][j] += pp[i][j+1];
      }
    }

    vector<double> ans(N, 0.0);
    for (int i = 0; i < N; ++i) {
      if (r[i].goal == INF)
	continue;

      for (int j = 0; j < M+1; ++j) {
	double m_ans = p[i][j];
	double time = r[i].goal + r[i].T * j;
	for (int k = 0; k < N; ++k) {
	  if (i == k)
	    continue;
	  if (time - r[k].goal >= 0.0) {
	    int rest = static_cast<int>((time - r[k].goal) / static_cast<double>(r[k].T)) + 1;
	    if (rest > M || r[k].T == 0) {
	      m_ans = 0.0;
	      break;
	    }
	    m_ans *= pp[k][rest];
	  }
	}
	ans[i] += m_ans;
      }
    }

    for (int i = 0; i < N; ++i)
      printf("%.8f\n", ans[i]);
  }
  return 0;
}
