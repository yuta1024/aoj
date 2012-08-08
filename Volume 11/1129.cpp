#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, r;
  for ( ; ; ) {
    cin >> n >> r;
    if (n == 0 && r == 0)
      break;

    vector<int> Card;
    for (int i = n; i > 0; --i)
      Card.push_back(i);

    for (int i = 0; i < r; ++i) {
      int p, c;
      cin >> p >> c;
      vector<int> Card_new;
      for (int j = 0; j < c; ++j) {
	Card_new.push_back(Card[p-1]);
	Card.erase(Card.begin() + p - 1);
      }
      for (unsigned int j = 0; j < Card.size(); ++j)
	Card_new.push_back(Card[j]);
      Card = Card_new;
    }
    cout << Card[0] << endl;
  }
  return 0;
}
