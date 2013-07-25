#include <stdio.h>

// Recursively converts n into string s
// return the length of the string
// Doesn't deal well with the minimum integer
int itoa(int n, char s[]) { 
  int pos = 0;
  if (n < 0) {
    n = -n;
    s[pos++] = '-';
  }
  if (n/10 > 0) {
    pos += itoa(n/10, &s[pos]);
  }
  s[pos++] = n%10 + '0';
  s[pos] = '\0';
  return pos;
}


int main(void) {
  int n1 = 123423221;
  int n2 = 0; 
  int n3 = -1234;
  char s[128];
  itoa(n1, s);
  printf("%d == %s\n", n1, s);
  itoa(n2, s);
  printf("%d == %s\n", n2, s);
  itoa(n3, s);
  printf("%d == %s\n", n3, s);
  return 1;
}
