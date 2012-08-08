#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;

  long long int sum = 0LL;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    sum += tmp;
  }

  cout << sum / n << endl;

  return 0;
}
