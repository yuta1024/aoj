#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
  int cnt = 0, a, b;
  long long int price = 0, num = 0;
  while (~scanf("%d,%d", &a, &b)) {
    price += (a * b);
    num += b;
    ++cnt;
  }

  cout << price << endl;
  cout << static_cast<int>(num / static_cast<double>(cnt) + 0.5) << endl;
}
