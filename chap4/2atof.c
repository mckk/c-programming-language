#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

double matof(char s[]) {
  double val, power;
  int i, sign, expsign, exp;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power /= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E')
    i++;
  
  /* Get exponent could be done using atoi
  expsign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '-' || s[i] == '+')
    i++;
  
  for (exp = 0; isdigit(s[i]); i++)
    exp = exp * 10 + (s[i] - '0'); 
  
  if (expsign < 0)
    for (i = 0; i < exp; i++)
      power /= 10.0;
  else
    for (i = 0; i < exp; i++)
      power *= 10.0;*/

  exp = atoi(&s[i]);
  if (exp < 0)
    for (i = 0; i > exp; i--)
      power /= 10.0;
  else
    for (i = 0; i < exp; i++)
      power *= 10.0;

  return sign * val * power;
}

int main() {
  char s[] = "123.45e-6";
  printf("%f\n", matof(s));
  return 0;
}
