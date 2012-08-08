#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int INF = 1 << 30;

class BigInteger
{
private:
  static const int DIGIT = 1000;

public:
  int num[DIGIT];

  BigInteger()
  {
    for (int i = 0; i < DIGIT; ++i)
      num[i] = 0;
  }

  BigInteger(const string& s)
  {
    BigInteger();
    for (int i = 0; i < s.size(); ++i)
      num[DIGIT-1-i] = s[s.size()-1-i];
  }

  BigInteger(const BigInteger& b)
  {
    for (int i = 0; i < DIGIT; ++i)
      num[i] = b.num[i];
  }

  BigInteger operator +(const BigInteger& rhs) const
  {
    BigInteger res;
    for (int i = 0; i < DIGIT; ++i)
      res.num[i] = num[i] + rhs.num[i];
    for (int i = DIGIT-1; i > 0; --i) {
      if (res.num[i] >= 10) {
	res.num[i] -= 10;
	++res.num[i-1];
      }
    }
    return res;
  }

  void operator +=(int rhs)
  {
    int index = DIGIT-1;
    while (rhs != 0) {
      num[index--] += rhs % 10;
      rhs /= 10;
    }
    for (int i = DIGIT-1; i > 0; --i) {
      if (num[i] >= 10) {
	num[i] -= 10;
	++num[i-1];
      }
    }
  }

  void operator *=(const int rhs)
  {
    BigInteger tmp(*this);
    for (int i = 0; i < rhs-1; ++i) {
      for (int j = 0; j < DIGIT; ++j)
	num[j] += tmp.num[j];
      for (int j = DIGIT-1; j > 0; --j) {
	if (num[j] >= 10) {
	  num[j] -= 10;
	  ++num[j-1];
	}
      }
    }
  }

  bool operator ==(const BigInteger& rhs) const
  {
    bool eq = true;
    for (int i = 0; i < DIGIT && eq; ++i) {
      if (num[i] != rhs.num[i])
	eq = false;
    }
    return eq;
  }

  void print() const
  {
    bool lz = true;
    for (int i = 0; i < DIGIT; ++i) {
      if (num[i] != 0)
	lz = false;
      if (!lz)
	cout << num[i];
    }
    cout << endl;
  }
};

int main()
{
  string s;
  while (cin >> s) {
    bool found = false;
    for (int i = 0; i <= 9; ++i) {
      int idx = 0, digit = 1;
      bool valid = true;
      const BigInteger ZERO;
      vector<BigInteger> num(3);
      for (unsigned int j = 0; j < s.size(); ++j) {
	if (s[j] == '+' || s[j] == '=') {
	  ++idx;
	  digit = 1;
	  continue;
	}
	num[idx] *= 10;
	if (s[j] == 'X') {
	  if (digit != 1 && i == 0 && num[idx] == ZERO) {
	    valid = false;
	    break;
	  }
	  num[idx] += i;
	} else {
	  num[idx] += (int)(s[j] - '0');
	}
	++digit;
      }
      if (valid && num[0] + num[1] == num[2]) {
	found = true;
	cout << i << endl;
	break;
      }
    }
    if (!found)
      cout << "NA" << endl;
  }
  return 0;
}
