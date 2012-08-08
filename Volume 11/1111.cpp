#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct
{
  string rule, src, dest;
} Filter;

int main()
{
  int n, m;
  while (cin >> n >> m) {
    if ((n|m) == 0)
      break;

    vector<Filter> filter(n);
    for (int i = 0; i < n; ++i)
      cin >> filter[i].rule >> filter[i].src >> filter[i].dest;
    reverse(filter.begin(), filter.end());

    vector<Filter> ans;
    for (int i = 0; i < m; ++i) {
      string src, dest, msg;
      cin >> src >> dest >> msg;

      for (int j = 0; j < n; ++j) {
	if (filter[j].rule == "permit") {
	  bool permit = true;
	  for (unsigned int k = 0; k < 8 && permit; ++k) {
	    if (filter[j].src[k] != '?' && filter[j].src[k] != src[k])
	      permit = false;
	    if (filter[j].dest[k] != '?' && filter[j].dest[k] != dest[k])
	      permit = false;
	  }
	  if (permit) {
	    ans.push_back((Filter){msg, src, dest});
	    break;
	  }
	} else {
	  bool deny = true;
	  for (unsigned int k = 0; k < 8 && deny; ++k) {
	    if (filter[j].src[k] != '?' && filter[j].src[k] != src[k])
	      deny = false;
	    if (filter[j].dest[k] != '?' && filter[j].dest[k] != dest[k])
	      deny = false;
	  }
	  if (deny)
	    break;
	}
      }
    }

    cout << ans.size() << endl;
    for (unsigned int i = 0; i < ans.size(); ++i)
      cout << ans[i].src << " " << ans[i].dest << " " << ans[i].rule << endl;
  }
  return 0;
}
