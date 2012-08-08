#include <iostream>
#include <vector>
#include <string>
using namespace std;

void escape(string &s)
{
  if (s.find_first_of("\n") != string::npos)
    s.erase(s.end()-1);
  if (s.find_first_of("\r") != string::npos)
    s.erase(s.end()-1);
}

int main()
{
  string s;
  vector<string> line;
  while (getline(cin, s)) {
    escape(s);
    if (s == "END_OF_TEXT")
      break;
    line.push_back(s);
  }

  int x = 0, y = 0;
  string buffer = "";
  while (cin >> s) {
    if (s == "-")
      break;

    if (s == "a") {
      x = 0;
    } else if (s == "e") {
      x = line[y].size();
    } else if (s == "p") {
      x = 0;
      if (y > 0)
	--y;
    } else if (s == "n") {
      x = 0;
      if (y != line.size()-1)
	++y;
    } else if (s == "f") {
      if (x < line[y].size()) {
	  ++x;
      } else if (y != line.size()-1) {
	x = 0;
	++y;
      }
    } else if (s == "b") {
      if (x > 0) {
	--x;
      } else if (y > 0) {
	--y;
	x = line[y].size();
      }
    } else if (s == "d") {
      if (x < line[y].size()) {
	line[y].erase(x, 1);
      } else if (y != line.size()-1) {
	line[y] += line[y+1];
	line.erase(line.begin()+y+1);
      }
    } else if (s == "k") {
      if (x >= line[y].size() && y != line.size()-1) {
	line[y] += line[y+1];
	line.erase(line.begin()+y+1);
	buffer = "\n";
      } else if (x < line[y].size()) {
	buffer = line[y].substr(x);
	line[y].erase(x);
      }
    } else if (s == "y" && buffer != "") {
      if (buffer == "\n") {
	s = line[y].substr(x);
	line[y].erase(x);
	line.insert(line.begin()+y+1, s);
	x = 0;
	++y;
      } else {
	line[y].insert(x, buffer);
	x += buffer.size();
      }
    }
  }
  
  for (unsigned int i = 0; i < line.size(); ++i)
    cout << line[i] << endl;
  return 0;
}
