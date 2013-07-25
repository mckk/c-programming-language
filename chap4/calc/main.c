#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main() {
  int type;
  double op1;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '%': //Exercise 4-3
      op2 = pop();
      op1 = pop();
      if (op2 != 0.0 && floorf(op1) == op1 && floorf(op2) == op2) {
        push((int)op1 % (int)op2);
      } else {
        printf("error: wrong operand types\n");
      }
      break;

    //Exercise 4-4
    case '#':
      op1 = pop();
      push(op1);
      push(op1);
      break;
    case '$':
      op1 = pop();
      op2 = pop();
      push(op1);
      push(op2);
      break;
    case '`':
      clear();
      break;
    case '@':
      printf("\t%.8g\n", peek());
      break;

    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}
