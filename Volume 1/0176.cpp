#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int INF = 1 << 30;

const int color[8][3] = { {  0,   0,   0},
			  {  0,   0, 255},
			  {  0, 255,   0},
			  {  0, 255, 255},
			  {255,   0,   0},
			  {255,   0, 255},
			  {255, 255,   0},
			  {255, 255, 255} };
const string name[] = {"black", "blue", "lime", "aqua",
		       "red", "fuchsia", "yellow", "white" };

int main()
{
  string RGB;
  while (cin >> RGB) {
    if (RGB == "0")
      break;

    int R = strtol(RGB.substr(1, 2).c_str(), NULL, 16);
    int G = strtol(RGB.substr(3, 2).c_str(), NULL, 16);
    int B = strtol(RGB.substr(5, 2).c_str(), NULL, 16);

    int d = INF, index = 0;
    for (int i = 0; i < 8; ++i) {
      int dd = (R-color[i][0]) * (R-color[i][0])
	+ (G-color[i][1]) * (G-color[i][1])
	+ (B-color[i][2]) * (B-color[i][2]);

      if (d > dd) {
	d = dd;
	index = i;
      }
    }
    cout << name[index] << endl;
  }
  return 0;
}
