#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> index, abcd(4);
  for (int i = 0; i < 4; ++i)
    index.push_back(i);

  while (cin >> abcd[0] >> abcd[1] >> abcd[2] >> abcd[3]) {
    sort(index.begin(), index.end());
    do {

    } while (next_permutation(index.begin(), index.end()));
  }
  return 0;
}
