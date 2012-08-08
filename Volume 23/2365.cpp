#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int NULLPO = 1 << 30;
const int UNDEFINED = -NULLPO;

int M, p, sum_heap = 0;
string s;
bool error = false;
vector<int> heap, var(26, UNDEFINED);

int p_expr();

int p_number()
{
  int ret = 0;
  while (isdigit(s[p])) {
    ret *= 10;
    ret += s[p] - '0';
    ++p;
  }
  return ret;
}

int p_clone()
{
  p += 6;
  int ret = p_expr();
  if (ret != NULLPO) {
    if (ret == UNDEFINED || heap[ret] == UNDEFINED) {
      error = true;
      ret = UNDEFINED;
    } else if (heap[ret] + sum_heap > M) {
      ret = NULLPO;
    } else {
      sum_heap += heap[ret];
      heap.push_back(heap[ret]);
      ret = heap.size() - 1;
    }
  }
  ++p;
  return ret;
}

int p_malloc()
{
  p += 7;
  int ret = p_number();
  if (ret + sum_heap > M) {
    ret = NULLPO;
  } else {
    sum_heap += ret;
    heap.push_back(ret);
    ret = heap.size() - 1;
  }
  ++p;
  return ret;
}

int p_assign()
{
  char v = s[p];
  p += 2;
  int ret = p_expr();
  var[v-'A'] = ret;
  return ret;
}

int p_expr()
{
  int ret = UNDEFINED;
  if (s[p] == '(') {
    ++p;
    ret = p_expr();
    ++p;
  } else if (p+1 < s.size() && s[p+1] == '=') {
    ret = p_assign();
  } else if (s[p] == 'N') {
    ret = NULLPO;
  } else if (s[p] == 'm') {
    ret = p_malloc();
  } else if (s[p] == 'c') {
    ret = p_clone();
  } else {
    ret = var[s[p]-'A'];
  }
  return ret;
}

void p_free()
{
  p += 5;
  int ret = p_expr();
  if (ret != NULLPO) {
    if (ret == UNDEFINED || heap[ret] == UNDEFINED) {
      error = true;
    } else {
      sum_heap -= heap[ret];
      heap[ret] = UNDEFINED;
    }
  }
  ++p;
}

void p_line()
{
  if (s[p] == 'f')
    p_free();
  else
    p_expr();
}

int main()
{
  cin >> M;
  while (cin >> s) {
    p = 0;
    p_line();
  }

  if (error) {
    cout << "Error" << endl;
  } else {
    int ans = sum_heap;
    for (int i = 0; i < var.size(); ++i) {
      if (var[i] == UNDEFINED || var[i] == NULLPO || heap[var[i]] == UNDEFINED)
	continue;
      ans -= heap[var[i]];
    }
    cout << ans << endl;
  }
  return 0;
}
