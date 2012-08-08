#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  string line;
  map<string, int> cnt;
  cnt["A"] = cnt["B"] = cnt["AB"] = cnt["O"] = 0;
  while (getline(cin, line)) {
    if (line.find_first_of("\n") != string::npos)
      line.erase(line.end()-1);
    if (line.find_first_of("\r") != string::npos)
      line.erase(line.end()-1);
    string bt = line.substr(line.find_first_of(",")+1);
    ++cnt[bt];
  }

  cout << cnt.find("A")->second << endl;
  cout << cnt.find("B")->second << endl;
  cout << cnt.find("AB")->second << endl;
  cout << cnt.find("O")->second << endl;
  return 0;
}
