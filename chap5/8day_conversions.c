#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
  int i, leap;
  
  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}


int main()
{
  //Test for day_of_year nonleap
  int nonleapdoy = day_of_year(2013, 10, 1);
  printf("Non leap day of year should be %d, it is %d\n", 274, nonleapdoy);
  
  int leapdoy = day_of_year(2012, 10, 1);
  printf("Leap day of year should be %d, it is %d\n", 275, leapdoy);

  //Test for month_day
  int nonleap_month;
  int nonleap_day;
  month_day(2013, 274, &nonleap_month, &nonleap_day);
  printf("Non leap month day should be 10-1, it is %d-%d\n", nonleap_month, nonleap_day);

  int leap_month;
  int leap_day;
  month_day(2012, 274, &leap_month, &leap_day);
  printf("Leap month day should be 9-30, it is %d-%d\n", leap_month, leap_day);
}
