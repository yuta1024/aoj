#include <iostream>
#include <string>
using namespace std;

int main()
{
  const string Type[] = {"A", "B", "NA"};

  int n;
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      string snake;
      cin >> snake;

      int ans = 2;
      int length = static_cast<int>(snake.size());
      if (snake[0] == '>' && snake[length-1] == '~') {
	if (length >= 5 && snake[1] == '\'' && snake.find_first_of("#") != string::npos) {
	  int sharp = snake.find_first_of("#");
	  bool valid = true;
	  for (int j = 2; j < sharp && valid; ++j) {
	    if (snake[j] != '=')
	      valid = false;
	  }
	  for (int j = sharp+1; j < length-1 && valid; ++j) {
	    if (snake[j] != '=')
	      valid = false;
	  }

	  if (valid && sharp-2 == length-2-sharp)
	    ans = 0;
	} else if (length >= 6 && snake[1] == '^' && snake[length-2] == '~') {
	  bool valid = true;
	  for (int j = 2; j < length-2 && valid; j += 2) {
	    if (snake[j] != 'Q' || snake[j+1] != '=')
	      valid = false;
	  }

	  if (valid)
	    ans = 1;
	}
      }
      cout << Type[ans] << endl;
    }
  }
  return 0;
}
