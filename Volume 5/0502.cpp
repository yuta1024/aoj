#include <iostream>
using namespace std;

/* Verified AOJ0502 */
class Dice
{
private:
  /*
    pip[0] = top, pip[1] = south, pip[2] = east
    pip[3] = bottom, pip[4] = north, pip[5] = west
  */
  int pip[6];
public:
  enum { TOP, SOUTH, EAST, BOTTOM, NORTH, WEST };

  Dice(int top = 1, int south = 2, int east = 3)
  {
    pip[TOP] = top;
    pip[SOUTH] = south;
    pip[EAST] = east;
    pip[BOTTOM] = 7 - top;
    pip[NORTH] = 7 - south;
    pip[WEST] = 7 - east;
  }

  // east:+, west:-
  void rotateX(int r)
  {
    if (r < 0)
      r += 4 * (-(r/4) + 1);
    r %= 4;
    for (int i = 0; i < r; ++i) {
      int tmp = pip[TOP];
      pip[TOP] = pip[WEST];
      pip[WEST] = pip[BOTTOM];
      pip[BOTTOM] = pip[EAST];
      pip[EAST] = tmp;
    }
  }

  // north:, south:-
  void rotateY(int r)
  {
    if (r < 0)
      r += 4 * (-(r/4) + 1);
    r %= 4;
    for (int i = 0; i < r; ++i) {
      int tmp = pip[TOP];
      pip[TOP] = pip[SOUTH];
      pip[SOUTH] = pip[BOTTOM];
      pip[BOTTOM] = pip[NORTH];
      pip[NORTH] = tmp;
    }
  }

  // right:+, left:-
  void rotateZ(int r)
  {
    if (r < 0)
      r += 4 * (-(r/4) + 1);
    r %= 4;
    for (int i = 0; i < r; ++i) {
      int tmp = pip[SOUTH];
      pip[SOUTH] = pip[EAST];
      pip[EAST] = pip[NORTH];
      pip[NORTH] = pip[WEST];
      pip[WEST] = tmp;
    }
  }
 
  inline int get(int p) const
  {
    return pip[p];
  } 
};

int main()
{
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int ans = 1;
    Dice dice;
    for (int i = 0; i < n; ++i) {
      string op;
      cin >> op;
      if (op == "North")
	dice.rotateY(1);
      else if (op == "East")
	dice.rotateX(1);
      else if (op == "South")
	dice.rotateY(-1);
      else if (op == "West")
	dice.rotateX(-1);
      else if (op == "Right")
	dice.rotateZ(1);
      else 
	dice.rotateZ(-1);
      ans += dice.get(Dice::TOP);
    }
    cout << ans << endl;
  }
  return 0;
}
