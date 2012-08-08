#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  string s;
  while (cin >> s) {
    vector<int> cnt(9, 0), ans;
    for (unsigned int i = 0; i < s.size(); ++i)
      ++cnt[s[i]-'1'];

    for (int i = 0; i < 9; ++i) {
      if (cnt[i]+1 >= 5)
	continue;

      bool valid = false;
      for (int j = 0; j < 9; ++j) {
	vector<int> cp(cnt);
	++cp[i];
	 
	if (cp[j] < 2)
	  continue;
	cp[j] -= 2;

	for (int k = 0; k < 9; ++k) {
	  if (cp[k] >= 3)
	    cp[k] -= 3;
	}

	for (int k = 0; k < 7; ++k) {
	  while (cp[k] > 0 && cp[k+1] > 0 && cp[k+2] > 0) {
	    --cp[k];
	    --cp[k+1];
	    --cp[k+2];
	  }
	}

	bool ok = true;
	for (int k = 0; k < 9; ++k) {
	  if (cp[k] != 0)
	    ok = false;
	}

	if (ok) {
	  valid = true;
	  break;
	}
      }

      for (int j = 0; j < 9; ++j) {
	vector<int> cp(cnt);
	++cp[i];
	 
	if (cp[j] < 2)
	  continue;
	cp[j] -= 2;

	for (int k = 0; k < 7; ++k) {
	  while (cp[k] > 0 && cp[k+1] > 0 && cp[k+2] > 0) {
	    --cp[k];
	    --cp[k+1];
	    --cp[k+2];
	  }
	}

	for (int k = 0; k < 9; ++k) {
	  if (cp[k] >= 3)
	    cp[k] -= 3;
	}

	bool ok = true;
	for (int k = 0; k < 9; ++k) {
	  if (cp[k] != 0)
	    ok = false;
	}

	if (ok) {
	  valid = true;
	  break;
	}
      }

      if (valid)
	ans.push_back(i+1);
    }

    if (ans.empty()) {
      cout << "0" << endl;
    } else {
      for (unsigned int i = 0; i < ans.size()-1; ++i)
	cout << ans[i] << " ";
      cout << ans[ans.size()-1] << endl;
    }
  }
  return 0;
}
