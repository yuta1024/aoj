#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int n, num;
  long long int price, count;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<int> index;
    vector<long long int> sale(4000, 0);
    for (int i = 0; i < n; ++i) {
      cin >> num >> price >> count;
      sale[num] += price * count;
      if (find(index.begin(), index.end(), num) == index.end())
	index.push_back(num);
    }

    bool found = false;
    for (unsigned int i = 0; i < index.size(); ++i) {
      if (sale[index[i]] >= 1000000LL) {
	cout << index[i] << endl;
	found = true;
      }
    }
    if (!found)
      cout << "NA" << endl;
  }
  return 0;
}
