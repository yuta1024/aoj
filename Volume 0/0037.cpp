#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_SIZE = 4+2;
enum { RIGHT, DOWN, LEFT, UP };

typedef struct
{
  bool wall[4];
} Cell;

int main()
{
  Cell field[MAX_SIZE][MAX_SIZE];
  for (int i = 0; i < MAX_SIZE; ++i) {
    for (int j = 0; j < MAX_SIZE; ++j) {
      for (int k = 0; k < 4; ++k)
	field[i][j].wall[k] = false;
    }
  }

  for (int i = 0; i < 9; ++i) {
    string s;
    cin >> s;

    if (i%2 == 0) {
    for (unsigned int j = 0; j < s.size(); ++j) {
      if (s[j] == '1')
	field[i/2][j+1].wall[DOWN] = field[i/2+1][j+1].wall[UP] = true;
    }

    } else {
    for (unsigned int j = 0; j < s.size(); ++j) {
      if (s[j] == '1')
	field[i/2+1][j].wall[RIGHT] = field[i/2+1][j+1].wall[LEFT] = true;
    }
    }
  }

  string ans = "";
  int x = 1, y = 0, dir = RIGHT;
  do {
    switch (dir) {
    case RIGHT:
      cout << "R: " << x << ", " << y << " -> " << ans << endl;
      if (field[y][x].wall[RIGHT]) {
	dir = UP;
	ans += "U";
      }	else if (field[y][x].wall[DOWN]) {
	ans += "R";
	++x;
      } else {
	dir = DOWN;
	if (field[y][x].wall[LEFT] || field[y][x].wall[DOWN])
	  ans += "D";
	++y;
      }
      break;
    
    case DOWN:
      cout << "D: " << x << ", " << y << " -> " << ans << endl;
      if (field[y][x].wall[DOWN]) {
	dir = RIGHT;
	ans += "R";
      } else if (field[y][x].wall[LEFT]) {
	ans += "D";
	++y;
      } else {
	dir = LEFT;
	if (field[y][x].wall[UP] || field[y][x].wall[LEFT])
	  ans += "L";
	--x;
      }
      break;

    case LEFT:
      cout << "L: " << x << ", " << y << " -> " << ans << endl;
      if (field[y][x].wall[LEFT]) {
	dir = DOWN;
	ans += "D";
      } else if (field[y][x].wall[UP]) {
	ans += "L";
	--x;
      } else {
	dir = UP;
	if (field[y][x].wall[RIGHT] || field[y][x].wall[UP])
	  ans += "U";
	--y;
      }
      break;

    case UP:
      cout << "U: " << x << ", " << y << " -> " << ans << endl;
      if (field[y][x].wall[UP]) {
	dir = LEFT;
	ans += "L";
      } else if (field[y][x].wall[RIGHT]) {
	ans += "U";
	--y;
      } else {
	dir = RIGHT;
	if (field[y][x].wall[DOWN] || field[y][x].wall[RIGHT])
	  ans += "R";
	++x;
      }

    }
  } while (x != 1 || y != 0);
  cout << ans << endl;
  return 0;
}
