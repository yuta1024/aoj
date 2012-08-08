#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 1 << 30;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

class Point
{
public:
  int x, y;
  Point()
    :x(INF), y(INF) {}
};

int main()
{
  int M, N;
  while (cin >> M >> N) {
    vector<string> C(M);
    for (int i = 0; i < M; ++i)
      cin >> C[i];

    vector<pair<set<char>, set<char> > > depends(26);

    for (char tar = 'A'; tar <= 'Z'; ++tar) {
      Point p1, p2;
      for (int y = 0; y < M; ++y) {
	for (int x = 0; x < N; ++x) {
	  if (C[y][x] == tar) {
	    if (p1.x == INF && p1.y == INF) {
	      p1.x = x;
	      p1.y = y;
	    } else {
	      p2.x = x;
	      p2.y = y;
	    }
	  }
	}
      }
   
      if ((p1.x == INF && p1.y == INF) ||
	  (p1.x == p2.x && abs(p1.y-p2.y) == 1) ||
	  (p1.y == p2.y && abs(p1.x-p2.x) == 1)) {
	depends[tar-'A'].first.insert('#');
	depends[tar-'A'].second .insert('#');
	continue;
      }

      
      set<char> c1, c2;
      
      for (int x = min(p1.x, p2.x); x <= max(p1.x, p2.x); ++x) {
	c1.insert(C[p1.y][x]);
	c2.insert(C[p2.y][x]);
      }
      for (int y = p1.y; y <= p2.y; ++y) {
	if (p1.x < p2.x) {
	  c1.insert(C[y][p2.x]);
	  c2.insert(C[y][p1.x]);
	} else {
	  c1.insert(C[y][p2.x]);
	  c2.insert(C[y][p1.x]);
	}
      }

      c1.erase(c1.find(tar));
      c2.erase(c2.find(tar));

      depends[tar-'A'].first  = c1;
      depends[tar-'A'].second = c2;
    }

    
    vector<char> root;
    for (unsigned int i = 0; i < depends.size(); ++i) {
      if ((depends[i].first.size() == 1 && depends[i].first.find('.') != depends[i].first.end()) || 
	  (depends[i].second.size() == 1 && depends[i].second.find('.') != depends[i].second.end())) {
	root.push_back(static_cast<char>(i + 'A'));
	depends[i].first.clear();
	depends[i].second.clear();
	depends[i].first.insert('#');
	depends[i].second.insert('#');
      }
    }
    
    int ans = 0;
    while (!root.empty()) {
      ans += 2;
      char front = root.front();
      root.erase(root.begin());

      for (unsigned int i = 0; i < depends.size(); ++i) {
	if (depends[i].first.find(front) != depends[i].first.end())
	  depends[i].first.erase((depends[i].first.find(front)));
	if (depends[i].second.find(front) != depends[i].second.end())
	  depends[i].second.erase((depends[i].second.find(front)));
	if ((depends[i].first.empty() || depends[i].first.size() == 1 && depends[i].first.find('.') != depends[i].first.end()) || 
	    (depends[i].second.empty() || depends[i].second.size() == 1 && depends[i].second.find('.') != depends[i].second.end())) {
	  root.push_back(static_cast<char>(i + 'A'));
	  depends[i].first.clear();
	  depends[i].second.clear();
	  depends[i].first.insert('#');
	  depends[i].second.insert('#');
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
