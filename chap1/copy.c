#include <stdio.h>

int main() {
  int c;
  printf("EOF: %d\n", EOF);
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}