#include <stdio.h>
#include <string.h>

void reverse_h(char s[], int bot, int top) {
  if (bot >= top) {
    return;
  }
  char tmp = s[bot];
  s[bot] = s[top];
  s[top] = tmp;
  reverse_h(s, bot+1, top-1);
}

void reverse(char s[]) {
  reverse_h(s, 0, strlen(s)-1);
}

int main(void) {
  char str1[] = "";
  char str2[] = "h";
  char str3[] = "abcd";
  char str4[] = "abcde";
  reverse(str1);
  reverse(str2);
  reverse(str3);
  reverse(str4);
  printf("%s\n", str1);
  printf("%s\n", str2);
  printf("%s\n", str3);
  printf("%s\n", str4);
}
