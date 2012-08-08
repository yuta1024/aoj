#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

int main()
{
  vector<string> c2s(128, "");
  c2s['A'] = "00000";
  c2s['B'] = "00001";
  c2s['C'] = "00010";
  c2s['D'] = "00011";
  c2s['E'] = "00100";
  c2s['F'] = "00101";
  c2s['G'] = "00110";
  c2s['H'] = "00111";
  c2s['I'] = "01000";
  c2s['J'] = "01001";
  c2s['K'] = "01010";
  c2s['L'] = "01011";
  c2s['M'] = "01100";
  c2s['N'] = "01101";
  c2s['O'] = "01110";
  c2s['P'] = "01111";
  c2s['Q'] = "10000";
  c2s['R'] = "10001";
  c2s['S'] = "10010";
  c2s['T'] = "10011";
  c2s['U'] = "10100";
  c2s['V'] = "10101";
  c2s['W'] = "10110";
  c2s['X'] = "10111";
  c2s['Y'] = "11000";
  c2s['Z'] = "11001";
  c2s[' '] = "11010";
  c2s['.'] = "11011";
  c2s[','] = "11100";
  c2s['-'] = "11101";
  c2s['\''] = "11110";
  c2s['?'] = "11111";

  map<string, char> s2c;
  s2c["101"] = ' ';
  s2c["000000"] = '\'';
  s2c["000011"] = ',';
  s2c["10010001"] = '-';
  s2c["010001"] = '.';
  s2c["000001"] = '?';
  s2c["100101"] = 'A';
  s2c["10011010"] = 'B';
  s2c["0101"] = 'C';
  s2c["0001"] = 'D';
  s2c["110"] = 'E';
  s2c["01001"] = 'F';
  s2c["10011011"] = 'G';
  s2c["010000"] = 'H';
  s2c["0111"] = 'I';
  s2c["10011000"] = 'J';
  s2c["0110"] = 'K';
  s2c["00100"] = 'L';
  s2c["10011001"] = 'M';
  s2c["10011110"] = 'N';
  s2c["00101"] = 'O';
  s2c["111"] = 'P';
  s2c["10011111"] = 'Q';
  s2c["1000"] = 'R';
  s2c["00110"] = 'S';
  s2c["00111"] = 'T';
  s2c["10011100"] = 'U';
  s2c["10011101"] = 'V';
  s2c["000010"] = 'W';
  s2c["10010010"] = 'X';
  s2c["10010011"] = 'Y';
  s2c["10010000"] = 'Z';

  string s;
  while (getline(cin, s)) {
    string enc = "";
    for (unsigned int i = 0; i < s.size(); ++i)
      enc += c2s[s[i]];

    string ans = "";
    string::size_type b = 0;
    for (unsigned int i = 0; i < enc.size(); ++i) {
      string sub = enc.substr(b, i-b+1);
      map<string, char>::iterator it = s2c.find(sub);
      if (it != s2c.end()) {
	b = i+1;
	ans += it->second;
      }
    }

    map<string, char>::iterator it = s2c.find(enc.substr(b));
    if (it != s2c.end())
      ans += it->second;
    cout << ans << endl;
  }
  return 0;
}
