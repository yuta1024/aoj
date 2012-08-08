#include <iostream>
#include <string>
#include <complex>
#include <cctype>
using namespace std;

const int MAX_NUM = 10000;

int p;
string s;
bool _ob;

void ob(const complex<int>& c)
{
  if (c.real() > MAX_NUM || c.real() < -MAX_NUM ||
      c.imag() > MAX_NUM || c.imag() < -MAX_NUM)
    _ob = true;
}

complex<int> p_exp();

complex<int> p_number()
{
  int num = 0;
  while (isdigit(s[p])) {
    if (num > MAX_NUM)
      _ob = true;
    num *= 10;
    num += s[p] - '0';
    ++p;
  }

  if (s[p] == 'i') {
    ++p;
    if (num == 0)
      ++num;
    return complex<int>(0, num);
  } else {
    return complex<int>(num);
  }
}

complex<int> p_factor()
{
  if (s[p] == '(') {
    ++p;
    complex<int> res = p_exp();
    ++p;
    ob(res);
    return res;
  } else {
    return p_number();
  }
}

complex<int> p_term()
{
  complex<int> res = p_factor();
  ob(res);
  for ( ; ; ) {
    if (s[p] == '*') {
      ++p;
      res *= p_factor();
      ob(res);
    } else if (s[p] == '/') {
      ++p;
      res /= p_factor();
      ob(res);
    } else {
      break;
    }
  }
  return res;
}

complex<int> p_exp()
{
  complex<int> res = p_term();
  ob(res);
  for ( ; ; ) {
    if (s[p] == '+') {
      ++p;
      res += p_term();
      ob(res);
    } else if (s[p] == '-') {
      ++p;
      res -= p_term();
      ob(res);
    } else {
      break;
    }
  }
  return res;
}

int main()
{
  while (cin >> s) {
    p = 0;
    _ob = false;
    complex<int> ans = p_exp();
    if (_ob)
      cout << "overflow" << endl;
    else if (ans.real() == 0 && ans.imag() == 0)
      cout << "0" << endl;
    else if (ans.real() == 0)
      cout << ans.imag() << "i" << endl;
    else if (ans.imag() == 0)
	cout << ans.real() << endl;
    else if (ans.imag() > 0)
      cout << ans.real() << "+" << ans.imag() << "i" << endl;
    else
      cout << ans.real() << ans.imag() << "i" << endl;
  }
  return 0;
}
