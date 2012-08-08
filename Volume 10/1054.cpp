#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct
{
  string name;
  int x1, x2, y1, y2;
} Button;

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;

    int W, H;
    cin >> W >> H;

    vector<string > buf;
    map<string, vector<Button> > button;
    for (int i = 0; i < n; ++i) {
      string name;
      int b;
      cin >> name >> b;
      for (int j = 0; j < b; ++j) {
	Button tmp;
	cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2 >> tmp.name;
	button[name].push_back(tmp);
      }

      if (i == 0)
	buf.push_back(name);
    }

    int m, p = 0;
    cin >> m;
    while (m--) {
      string cmd;
      cin >> cmd;

      if (cmd == "click") {
	int x, y;
	cin >> x >> y;
	const vector<Button>& link = button[buf[p]];
	for (int i = 0; i < link.size(); ++i) {
	  if (link[i].x1 <= x && x <= link[i].x2 &&
	      link[i].y1 <= y && y <= link[i].y2) {
	    buf.erase(buf.begin()+p+1, buf.end());
	    buf.push_back(link[i].name);
	    ++p;
	    break;
	  }
	}
      } else if (cmd == "show") {
	cout << buf[p] << endl;
      } else if (cmd == "back") {
	if (p != 0)
	  --p;
      } else {
	if (p+1 < buf.size())
	  ++p;
      }
    }
  }
  return 0;
}
