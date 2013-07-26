#include <stdio.h>
#include <string.h>
// There will a problem if either X or Y is called tmp.
// I'm not really sure how to fix it yet.
// Exercise 4-14
#define SWAP(T, X, Y) {T tmp = X; X = Y; Y = tmp;}

// Exerciese 4-13
void reverse_h(char s[], int bot, int top) {
  if (bot >= top) {
    return;
  }
  SWAP(char, s[bot], s[top]);
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
