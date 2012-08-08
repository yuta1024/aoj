#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class State
{
public:
  int index, op, cost;
  string s;
  State(int _index, int _op, int _cost, string _s)
    :index(_index), op(_op), cost(_cost), s(_s) {}
};

int main()
{
  string s;
  queue<State> que;
  map<string, int> memo;
  que.push(State(0, -1, 0, "01234567"));
  while (!que.empty()) {
    const State st = que.front();
    que.pop();
    
    if (memo.find(st.s) != memo.end())
      continue;
    
    memo[st.s] = st.cost;
    if (st.index != 3 && st.index != 7 && st.op != 2) {
      s = st.s;
      swap(s[st.index], s[st.index+1]);
      if (memo.find(s) == memo.end())
	que.push(State(st.index+1, 0, st.cost+1, s));
    }
    
    if (st.index != 0 && st.index != 4 && st.op != 0) {
      s = st.s;
      swap(s[st.index], s[st.index-1]);
      if (memo.find(s) == memo.end())
	que.push(State(st.index-1, 2, st.cost+1, s));
    }
    
    if (st.index < 4 && st.op != 1) {
      s = st.s;
      swap(s[st.index], s[st.index+4]);
      if (memo.find(s) == memo.end())
	que.push(State(st.index+4, 3, st.cost+1, s));
    }

    if (st.index > 3 && st.op != 3) {
      s = st.s;
      swap(s[st.index], s[st.index-4]);
      if (memo.find(s) == memo.end())
	que.push(State(st.index-4, 1, st.cost+1, s));
      }
  }
  
  size_t p;
  while (getline(cin, s)) {
    while ((p = s.find_first_of(" \r\n")) != string::npos) {
      s.erase(s.begin()+p);
    }
    cout << memo.find(s)->second << endl;
  }
  return 0;
}
