#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    string chair(n, '#');

    while (m--) {
      string a;
      cin >> a;
      if (a == "A") {
	for (int i = 0; i < n; ++i) {
	  if (chair[i] == '#') {
	    chair[i] = 'A';
	    break;
	  }
	}
      } else if (a == "B") {
	int sit = -1;
	for (int i = n-1; i > 0 && sit == -1; --i) {
	  if (chair[i] != '#')
	    continue;

	  if (i == 0) {
	    if (chair[i+1] != 'A')
	      sit = i;
	  } else if (i == n-1) {
	    if (chair[i-1] != 'A')
	      sit = i;
	  } else if (chair[i+1] != 'A' && chair[i-1] != 'A') {
	    sit = i;
	  }
	}
	if (sit != -1) {
	  chair[sit] = 'B';
	  continue;
	}

	for (int i = 0; i < n; ++i) {
	  if (chair[i] == '#') {
	    chair[i] = 'B';
	    break;
	  }
	}
      } else if (a  == "C") {
	int sit = -1;
	for (int i = 0; i < n && sit == -1; ++i) {
	  if (chair[i] == '#')
	    continue;

	  if (i == 0) {
	    if (chair[i+1] == '#')
	      sit = i+1;
	  } else if (i == n-1) {
	    if (chair[i-1] == '#')
	      sit = i-1;
	  } else if (chair[i+1] == '#') {
	    sit = i+1;
	  } else if (chair[i-1] == '#') {
	    sit = i-1;
	  }
	}
	if (sit != -1) {
	  chair[sit] = 'C';
	  continue;
	}

	if (n&1)
	  chair[(n+1)/2-1] = 'C';
	else
	  chair[n/2] = 'C';
      } else {
	int maxIndex = -1, dist = -1;
	for (int i = 0; i < n; ++i) {
	  if (chair[i] != '#')
	    continue;

	  int right = 0;
	  if (i == n-1)
	    right = n;
	  for (int j = i+1; j < n; ++j) {
	    if (chair[j] == '#')
	      ++right;
	    else
	      break;
	  }

	  int left = 0;
	  if (i == 0)
	    left = n;
	  for (int j = i-1; j >= 0; --j) {
	    if (chair[j] == '#')
	      ++left;
	    else
	      break;
	  }

	  if (dist < min(right, left)) {
	    maxIndex = i;
	    dist = min(right, left);
	  }
	}
	chair[maxIndex] = 'D';
      }
    }

    cout << chair << endl;
  }
  return 0;
}
