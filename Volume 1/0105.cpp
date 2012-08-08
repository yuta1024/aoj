#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
  string word;
  int page;
  map<string, vector<int> > index;
  while (cin >> word >> page)
    index[word].push_back(page);

  for (map<string, vector<int> >::iterator it = index.begin(); it != index.end(); ++it) {
    vector<int>& pages = it->second;
    sort(pages.begin(), pages.end());
    cout << it->first << endl;
    for (int i = 0; i < pages.size()-1; ++i)
      cout << pages[i] << " ";
    cout << pages[pages.size()-1] << endl;
  }
  return 0;
}
