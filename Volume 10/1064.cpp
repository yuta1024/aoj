#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
  int idx, read, x1, y1, x2, y2;
} Rec;

void solve(vector<Rec*> rem, int& reader)
{
  int minIndex = 0;
  for (unsigned int i = 1; i < rem.size(); ++i) {
    if (rem[minIndex]->x1 > rem[i]->x1) {
      minIndex = i;
    } else if (rem[minIndex]->x1 == rem[i]->x1) {
      if (rem[minIndex]->y1 > rem[i]->y1)
	minIndex = i;
    }
  }

  rem[minIndex]->read = reader++;
  int x = 501, y = rem[minIndex]->y2;
  vector<Rec*> rem1, rem2;
  for (unsigned int i = 0; i < rem.size(); ++i) {
    if (i == minIndex)
      continue;
    if (rem[i]->x1 < x && rem[i]->y1 < y && y < rem[i]->y2)
      x = min(x, rem[i]->x1);
  }
  /*
    printf("(%d, %d)-(%d, %d) ->(%d, %d)\n", 
	   rem[minIndex]->x1, rem[minIndex]->y1,
	   rem[minIndex]->x2, rem[minIndex]->y2,
	   x, y);
  */  

  for (unsigned int i = 0; i < rem.size(); ++i) {
    if (i == minIndex)
      continue;
    if (rem[i]->x2 <= x && rem[i]->y2 <= y)
      rem1.push_back(rem[i]);
    else
      rem2.push_back(rem[i]);
  }

  if (!rem1.empty())
    solve(rem1, reader);
  if (!rem2.empty())
    solve(rem2, reader);
}

int main()
{
  int n;
  bool first = true;
  while (~scanf("%d", &n)) {
    if (n == 0)
      break;

    if (!first)
      puts("");

    vector<Rec> rec(n);
    for (int i = 0; i < n; ++i) {
      rec[i].idx = i;
      scanf("%d %d %d %d", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
      if (rec[i].x1 > rec[i].x2)
	swap(rec[i].x1, rec[i].x2);
      if (rec[i].y1 > rec[i].y2)
	swap(rec[i].y1, rec[i].y2);
    }

    vector<Rec*> rem;
    for (unsigned int i = 0; i < rec.size(); ++i)
      rem.push_back(&rec[i]);

    int cnt = 1;
    solve(rem, cnt);

    for (unsigned int i = 0; i < rec.size(); ++i)
      printf("%d\n", rec[i].read);
    first = false;
  }
  return 0;
}
