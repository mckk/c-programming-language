#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool ishexdigit(char c) {
  c = tolower(c);
  return isdigit(c) || (c >= 'a' && c <= 'f');
}

int hdtoi(char c) {
  if (isdigit(c))
    return c - '0';
  c = tolower(c);
  return (c - 'a') + 10;
  
}

int htoip(const char s[]) {
  int n, i;
  n = 0;
  
  for (i = 0; ishexdigit(s[i]); i++) {
    n = 16*n + hdtoi(s[i]);
  }
  return n;
}

int htoi(const char s[]) {
  if (s[0] == '-')
    return - htoip(&s[1]);
  return htoip(s);  
}

int main() {
  printf("%d\n", htoi("-ff"));
  return 0;
}