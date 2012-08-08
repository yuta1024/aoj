#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> array(n);
    for (int i = 0; i < n; ++i)
      cin >> array[i];

    int target;
    cin >> target;

    int ans = 0, low = 0, high = n-1;
    while (low <= high) {
      ++ans;
      int mid = (low + high) / 2;
      if (array[mid] == target)
	break;
      else if (array[mid] < target)
	low = mid+1;
      else
	high = mid-1;
    }
    cout << ans << endl;
  }
  return 0;
}
