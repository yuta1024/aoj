#include <iostream>
#include <algorithm>
using namespace std;

int table[7][7] = { { 0, 300, 500, 600, 700, 1350, 1650},
		    { 6,   0, 350, 450, 600, 1150, 1500},
		    {13,   7,   0, 250, 400, 1000, 1350},
		    {18,  12,   5,   0, 250,  850, 1300},
		    {23,  17,  10,   5,   0,  600, 1150},
		    {43,  37,  30,  25,  20,    0,  500},
		    {58,  52,  45,  40,  35,   15,    0} };

int main()
{
  int sic;
  while (cin >> sic) {
    if (sic == 0)
      break;

    int sh, sm, tic, th, tm;
    cin >> sh >> sm >> tic >> th >> tm;
    --sic;
    --tic;

    bool half = false;
    if (((17*60+30 <= sh*60+sm && sh*60+sm <= 19*60+30) ||
	 (17*60+30 <= th*60+tm && th*60+tm <= 19*60+30)) &&
	table[max(sic, tic)][min(sic, tic)] <= 40)
      half = true;

    int ans = table[min(sic, tic)][max(sic, tic)];
    if (half) {
      ans /= 2;
      if (ans % 50 != 0)
	ans = ((ans+49) / 50) * 50;
    }
    cout << ans << endl;
  }

  return 0;
}
