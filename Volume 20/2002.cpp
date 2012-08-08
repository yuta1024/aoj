#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Point
{
public:
  int x, y;
  Point(int xx = -1, int yy = -1)
    :x(xx), y(yy) {}
};

class Rect
{
public:
  char sign;
  Point lu, rd;
  Rect(char s, Point a, Point b)
    :sign(s), lu(a), rd(b) {}
};

int main()
{
  int N;
  cin >> N;
  while (N--) {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; ++i)
      cin >> s[i];

    set<char> alpha;
    for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
	if (s[i][j] != '.')
	  alpha.insert(s[i][j]);
      }
    }

    
    vector<Rect> rec;
    for (set<char>::iterator it = alpha.begin(); it != alpha.end(); ++it) {
      Point lu, rd;
      // y
      for (int y = 0; y < H; ++y) {
	for (int x = 0; x < W; ++x) {
	  if (s[y][x] == (*it)) {
	    if (lu.y == -1)
	      lu.y = y;
	    rd.y = y;
	  }
	}
      }

      // x
      for (int x = 0; x < W; ++x) {
	for (int y = 0; y < H; ++y) {
	  if (s[y][x] == (*it)) {
	    if (lu.x == -1)
	      lu.x = x;
	    rd.x = x;
	  }
	}
      }

      rec.push_back(Rect(*it, lu, rd));
    }

    for ( ; ; ) {
      bool op = false;

      for (int i = 0; i < rec.size(); ++i) {
	bool ok = true, found = false;
	for (int y = rec[i].lu.y; y <= rec[i].rd.y && ok; ++y) {
	  for (int x = rec[i].lu.x; x <= rec[i].rd.x; ++x) {
	    if (s[y][x] == rec[i].sign)
	      found = true;
	    if (s[y][x] != rec[i].sign && s[y][x] != '$') {
	      ok = false;
	      break;
	    }
	  }
	}

	if (ok && found) {
	  op = true;
	  for (int y = rec[i].lu.y; y <= rec[i].rd.y; ++y) {
	    for (int x = rec[i].lu.x; x <= rec[i].rd.x; ++x)
	      s[y][x] = '$';
	  }
	}
      }

      if (!op)
	break;
    }
    
    bool safe = true;
    for (int i = 0; i < H && safe; ++i) {
      if (s[i].find_first_not_of("$.", 0) != string::npos)
	safe = false;
    }

    if (safe)
      cout << "SAFE" << endl;
    else
      cout << "SUSPICIOUS" << endl;

  }
  return 0;
}
