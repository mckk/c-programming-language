#include <stdio.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(char ch) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = ch;
}

//Exercise 4-7
void ungets(char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++) {
    ungetch(s[i]);
  }
}
