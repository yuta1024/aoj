#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> ans(8, 0);
  vector<double> eye(2);
  while (cin >> eye[0] >> eye[1]) {
    for (int i = 0; i < 2; ++i) {
      if (eye[i] >= 1.1)
	++ans[0+i];
      else if (eye[i] >= 0.6)
	++ans[2+i];
      else if (eye[i] >= 0.2)
	++ans[4+i];
      else
	++ans[6+i];
    }
  }

  for (int i = 0; i < 8; i += 2)
    cout << ans[i] << " " << ans[i+1] << endl;

  return 0;
}
