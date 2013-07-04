#include <stdbool.h>
#include <stdio.h>

bool in(char c, const char s[]) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (c == s[i])
      return true;
  }
  return false;
}

int any(char s1[], const char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++) {
    if (in(s1[i],s2)) {
      return i;
    }
  }
  return -1;
}

int main() {
  const char s1[] = "hell";
  char s2[] = "durham";
  char s3[] = "jimmy";
  
  printf("Letter in common should be 3: %d\n", any(s2, s1));
  printf("No letter in common: %d\n", any(s3, s1));
  
  return 0;
}