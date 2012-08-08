#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solve(const vector<string>& board, char c)
{
  if (board[0][0] == c && board[0][1] == c && board[0][2] == c ||
      board[1][0] == c && board[1][1] == c && board[1][2] == c ||
      board[2][0] == c && board[2][1] == c && board[2][2] == c ||
      board[0][0] == c && board[1][0] == c && board[2][0] == c ||
      board[0][1] == c && board[1][1] == c && board[2][1] == c ||
      board[0][2] == c && board[1][2] == c && board[2][2] == c ||
      board[0][0] == c && board[1][1] == c && board[2][2] == c ||
      board[2][0] == c && board[1][1] == c && board[0][2] == c)
    return true;
  return false;
}

int main()
{
  vector<string> board(3);
  while (cin >> board[0] >> board[1] >> board[2]) {
    if (board[0] == "0")
      break;

    if (solve(board, 'b'))
      cout << "b" << endl;
    else if (solve(board, 'w'))
      cout << "w" << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}
