#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
  vector<int> in(5);
  for (int i = 0; i < 5; ++i)
    cin >> in[i];

  sort(in.begin(), in.end(), greater<int>());

  cout << in[0];
  for (int i = 1; i < in.size(); ++i)
    cout << " " << in[i];
  cout << endl;

  return 0;
}
