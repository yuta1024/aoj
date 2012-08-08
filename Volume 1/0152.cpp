#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef struct
{
  int id, score;
} Student;

class GreaterScore
{
public:
  bool operator() (const Student& lhs, const Student& rhs) const
  {
    if (lhs.score == rhs.score)
      return lhs.id < rhs.id;
    return lhs.score > rhs.score;
  }
};

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    vector<Student> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i].id;

      vector<int> p;
      for (int j = 0; j < 10; ++j) {
	int p1;
	cin >> p1;
	p.push_back(p1);
	if (p1 == 10 && j != 9)
	  continue;

	int p2;
	cin >> p2;
	p.push_back(p2);

	if (p1+p2 >= 10 && j == 9) {
	  int p3;
	  cin >> p3;
	  p.push_back(p3);
	}
      }

      int idx = 0;
      bool first = true;
      vector<int> frame(10, 0);
      for (unsigned int j = 0; j < p.size(); ++j) {
	if (idx == 9) {
	  frame[idx] += p[j];
	  continue;
	} else if (first) {
	  frame[idx] += p[j];
	  if (frame[idx] == 10)
	    frame[idx++] += p[j+1] + p[j+2];
	  else
	    first = false;
	} else {
	  frame[idx] += p[j];
	  if (frame[idx] == 10)
	    frame[idx] += p[j+1];
	  ++idx;
	  first = true;
	}
      }
      s[i].score = accumulate(frame.begin(), frame.end(), 0);
    }

    sort(s.begin(), s.end(), GreaterScore());
    for (int i = 0; i < n; ++i)
      cout << s[i].id << " " << s[i].score << endl;
  }
  return 0;
}
