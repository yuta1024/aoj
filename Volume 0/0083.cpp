#include <cstdio>

int main()
{
  int year, month, day;
  while (~scanf("%d %d %d", &year, &month, &day)) {
    if (year < 1868 || (year == 1868 && (month < 9 || (month == 9 && day < 8))))
      printf("pre-meiji\n");
    else if (year < 1912 || (year == 1912 && (month < 7 || (month == 7 && day < 30))))
      printf("meiji %d %d %d\n", year-1868+1, month, day);
    else if (year < 1926 || (year == 1926 && (month < 12 || (month == 12 && day < 25))))
      printf("taisho %d %d %d\n", year-1912+1, month, day);
    else if (year < 1989 || (year == 1989 && (month < 1 || (month == 1 && day < 8))))
      printf("showa %d %d %d\n", year-1926+1, month, day);
    else
      printf("heisei %d %d %d\n", year-1989+1, month, day);
  }
  return 0;
}
