#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>


//Exercise 2-3
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

//Exercise 2-4

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

//Exercise 2-5

int any(char s1[], const char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++) {
    if (in(s1[i],s2)) {
      return i;
    }
  }
  return -1;
}

//Exercise 2-6
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned zeros_and_set_bits = (y & ~(~0 << n)) << (p+1-n);
  unsigned ones_and_set_bits  = ((y | (~0 << n)) << (p+1-n)) | ~(~0 << (p+1-n));
  
  return (x | zeros_and_set_bits) & ones_and_set_bits;
}

//MAIN
int main() {
  //Test 2-3
  printf("%d\n", htoi("-ff"));
  
  //Test 2-4
  char s1[] = "hello";
  const char s2[] = "hasl";
  
  squeeze(s1, s2);
  
  printf("%s", s1);
  printf("\n");
  
  //Test 2-5
  const char s3[] = "hell";
  char s4[] = "durham";
  char s5[] = "jimmy";
  
  printf("Letter in common should be 3: %d\n", any(s4, s3));
  printf("No letter in common: %d\n", any(s5, s3));
  
  
  //Test 2-6
  unsigned bits1 = 3483; //110110011011
  unsigned bits2 = 60; //111100
  
  unsigned res = setbits(bits1, 6, 4, bits2);
  unsigned should_be = 3555; //110111100011
  printf("Is: %u, should be: %u\n", res, should_be);
  
  return 0;
}