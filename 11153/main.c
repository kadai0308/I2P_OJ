# include <stdio.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
  int year = 0, month = 0, day = 0;
  int leap_year = 0;
  int result = 0;

  scanf(" %d", &year);
  scanf(" %d", &month);
  scanf(" %d", &day);

  if ((year % 4 == 0) && (year % 100 != 0)) {
    leap_year = 1;
  } else if ((year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0)) {
    leap_year = 0;
  } else if (year % 400 == 0) {
    leap_year = 1;
  } else {
    leap_year = 0;
  }

  for (int i = 1; i < month; ++i) {
    if ((i == 2) && leap_year) {
      result += 29;
    } else if ((i == 2) && !leap_year) {
      result += 28;
    }

    if (i == 1) {
      result += 31;
    } else if (i == 3) {
      result += 31;
    } else if (i == 4) {
      result += 30;
    } else if (i == 5) {
      result += 31;
    } else if (i == 6) {
      result += 30;
    } else if (i == 7) {
      result += 31;
    } else if (i == 8) {
      result += 31;
    } else if (i == 9) {
      result += 30;
    } else if (i ==  10) {
      result += 31;
    } else if (i == 11) {
      result += 30;
    } else if (i == 12) {
      result += 31;
    }
  }
  result += day;

  printf("%d", result);
  return 0;
}