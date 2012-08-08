#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

class File
{
public:
  int index, left, right;
  File (int i, int l, int r)
    :index(i), left(l), right(r) {}
};

int main()
{
  int N;
  while (~scanf("%d\n", &N)) {
    if (N == 0)
      break;

    list<File> disk(1, File(-1, -1, -1));
    for (int i = 0; i < N; ++i) {
      char op;
      scanf("%c", &op);
      if (op == 'W') {
	int I, S;
	scanf("%d %d\n", &I, &S);

	int last = 0;
	for (list<File>::iterator it = disk.begin(); it != disk.end(); ) {
	  list<File>::iterator next = it;
	  ++next;
	  if (next == disk.end()) {
	    last = it->right+1;
	    break;
	  }

	  int left  = it->right+1;
	  int right = next->left-1;
	  int cap = right - left + 1;
	  if (cap >= 1) {
	    if (cap > S) {
	      disk.insert(next, File(I, left, left+S-1));
	      S = 0;
	      break;
	    } else {
	      disk.insert(next, File(I, left, right));
	      S -= cap;
	    }
	  } else {
	    ++it;
	  }
	}

	if (S > 0)
	  disk.push_back(File(I, last, last+S-1));
      } else if (op == 'D') {
	int I;
	scanf("%d\n", &I);
	for (list<File>::iterator it = disk.begin(); it != disk.end(); ) {
	  if (it->index == I)
	    it = disk.erase(it);
	  else
	    ++it;
	}

      } else {
	int P, ans = -1;
	scanf("%d\n", &P);
	for (list<File>::iterator it = disk.begin(); it != disk.end(); ++it) {
	  if (it->left <= P && P <= it->right) {
	    ans = it->index;
	    break;
	  }
	}
	printf("%d\n", ans);
      }
    }
    puts("");
  }
  return 0;
}
