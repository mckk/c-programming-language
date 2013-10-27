#include <stdio.h>
#include <assert.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int year)
{
  return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = is_leap(year);
  
  if (day > daytab[leap][month] || day <= 0
      || month <= 0 || month >= 13)
    return -1;

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap, yearlength;

  leap = is_leap(year);
  
  yearlength = leap ? 366 : 365;
  if (yearday <= 0 || yearday > yearlength)
    return -1;

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;

  return 0;
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

  //Test of day_of_year error
  printf("Should be -1, %d\n", day_of_year(2012, 13, 1));
  printf("Should be -1, %d\n", day_of_year(2012, 0, 1));
  printf("Should be -1, %d\n", day_of_year(2012, 2, -10));
  printf("Should be -1, %d\n", day_of_year(2012, 2, 30));

  //Test of month_day error
  printf("Should be 0, %d\n", month_day(2012, 366, &leap_day, &leap_month));
  printf("Should be -1, %d\n", month_day(2012, 367, &leap_day, &leap_month));
  printf("Should be 0, %d\n", month_day(2011, 365, &leap_day, &leap_month));
  printf("Should be -1, %d\n", month_day(2011, 366, &leap_day, &leap_month));
}
