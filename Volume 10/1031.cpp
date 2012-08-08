#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Tag
{
  string name;
  int x1, y1, x2, y2;
  vector<Tag> child;
} Tag;

string start_tag(const string& s, int& p)
{
  string name = "";
  ++p;
  while (s[p] != '>')
    name += s[p++];
  ++p;
  return name;
}

void tag_value(const string&s, int& p, Tag& tag)
{
  tag.x1 = tag.y1 = tag.x2 = tag.y2 = 0;
  
  while (s[p] != ',') {
    tag.x1 *= 10;
    tag.x1 += s[p++] - '0';
  }
  ++p;
  
  while (s[p] != ',') {
    tag.y1 *= 10;
    tag.y1 += s[p++] - '0';
  }
  ++p;
  
  while (s[p] != ',') {
    tag.x2 *= 10;
    tag.x2 += s[p++] - '0';
  }
  ++p;
  
  while (s[p] != '<') {
    tag.y2 *= 10;
    tag.y2 += s[p++] - '0';
  }
}

Tag tag(const string& s, int& p)
{
  Tag node;
  node.name = start_tag(s, p);
  tag_value(s, p, node);
  while (s[p+1] != '/')
    node.child.push_back(tag(s, p));
  while (s[p] != '>')
    ++p;
  ++p;
  return node;
}

bool solve(int x, int y, const Tag& root)
{
  bool found = false;
  if (root.x1 <= x && x <= root.x2 && root.y1 <= y && y <= root.y2) {
    for (unsigned int i = 0; i < root.child.size(); ++i)
      found |= solve(x, y, root.child[i]);
    if (!found) {
      cout << root.name << " " << root.child.size() << endl;
      found = true;
    }
  }
  return found;
}

int main()
{
  int n;
  while (cin >> n) {
    if (n == 0)
      break;
    
    string s;
    cin >> s;
    int p = 0;
    
    Tag root = tag(s, p);
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      if (!solve(x, y, root))
	cout << "OUT OF MAIN PANEL 1" << endl;
    }
    
  }
  return 0;
}
