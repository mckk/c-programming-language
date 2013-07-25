#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand
 * Negative number parsing is exercise 4-3*/
int getop(char s[]) {
  int i;
  char c1, c2;

  // Skip whitespace
  while ((s[0] = c1 = getch()) == ' ' || c1 == '\t')
    ;
  s[1] = '\0';

  if (!isdigit(c1) && c1 != '.' && c1 != '-' && c1 != '+')
    return c1;

  //If there is a sign, check if the rest starts with a number or not
  //if it does not, return the sign as an operator, if it does do nothing
  //in both cases ungetch it will be dealt with later
  if (c1 == '-' || c1 == '+') {
    c2 = getch();
    ungetch(c2);
    if (!isdigit(c2) && c2 != '.') {
      return c1;
    }
  }

  i = 0;
  if (isdigit(c1) || c1 == '-' || c1 == '+')
    while (isdigit(s[++i] = c1 = getch()))
      ;
  if (c1 == '.')
    while (isdigit(s[++i] = c1 = getch()))
      ;
  s[i] = '\0';
  if (c1 != EOF)
    ungetch(c1);
  return NUMBER;
}
