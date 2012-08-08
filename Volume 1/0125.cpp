#include <cstdio>

const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int ldays[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
  if (year%400 == 0 || (year%4 == 0 && year%100 != 0))
    return true;
  return false;
}

int main()
{
  int y1, m1, d1, y2, m2, d2;
  while (~scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2)) {
    if (y1 == -1 || m1 == -1 || d1 == -1 || y2 == -1 || m2 == -1 || d2 == -1)
      break;

    int start = 0, end = 0;
    for (int i = 1; i < y1; ++i) {
      if (isLeapYear(i))
	start += 366;
      else
	start += 365;
    }
    end = start;
    for (int i = y1; i < y2; ++i) {
      if (isLeapYear(i))
	end += 366;
      else
	end += 365;
    }

    for (int i = 1; i < m1; ++i) {
      if (isLeapYear(y1))
	  start += ldays[i];
      else
	start += days[i];
    }
    for (int i = 1; i < m2; ++i) {
      if (isLeapYear(y2))
	end += ldays[i];
      else
	end += days[i];
    }

    printf("%d\n", end+d2-start-d1);
  }
  return 0;
}
