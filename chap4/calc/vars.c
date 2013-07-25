#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define MAXNUM 26


//Exercise 4-6
static double map[MAXNUM];

double get(char key) {
  key = tolower(key) - 'a';
  if (key < 0 || key >= MAXNUM) {
    printf("error: variable does not exist");
    return 0.0;
  }
  return map[key];
}

void put(char key, double val) {
  key = tolower(key) - 'a';
  if (key < 0 || key >= MAXNUM) {
    printf("error: variable does not exist");
  } else {
    map[key] = val;
  }
}
