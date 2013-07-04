#include <stdbool.h>
#include <stdio.h>

bool in(char c, const char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (c == s[i])
      return true;
  }
  return false;
}

void squeeze(char s1[], const char s2[]) {
  int i,j;
  
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!in(s1[i], s2)) {
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}

int main() {
  char s1[] = "hello";
  const char s2[] = "hasl";
  
  squeeze(s1, s2);
  
  printf("%s", s1);
  printf("\n");
  
  return 0;
}