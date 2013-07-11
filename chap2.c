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

//Exercise 2-7
unsigned invert(unsigned x, int p, int n) {
  unsigned inversion = ~(x >> (p+1-n));
  return setbits(x, p, n, inversion);
}

//Exercise 2-8
unsigned rightrot(unsigned x, int n) {
  for ( ; n > 0; n--) {
    if (x & 1) {
      x = (x >> 1) | ~(~0U >> 1);
    } else {
      x = (x >> 1);
    }
  }
  return x;
}

//Exercise 2-9
//If x is odd it ends in 1. x-1 is just x with the last bit set to 0. x&(x-1) is just x-1.
//If x is even x-1 sets all the right most 0 to 1 and the rightmost 1 to 0. x&(x-1) sets
//everything up to and including that 1 to 0.
int bitcount(unsigned x) {
  int b = 0;
  while (x != 0) {
    b++;
    x &= (x-1);
  }
  return b;
}

int oldbitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1) {
    if (x & 01)
      b++;

  }
  return b;
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
  
  unsigned res1 = setbits(bits1, 6, 4, bits2);
  unsigned should_be1 = 3555; //110111100011
  printf("Is: %u, should be: %u\n", res1, should_be1);
  
  //Test 2-7
  unsigned res2 = invert(bits1, 7, 4);
  unsigned should_be2 = 3435; //110101101011
  printf("Is: %u, should be: %u\n", res2, should_be2);
  
  //Test 2-8
  unsigned res3 = rightrot(bits1, 6);
  unsigned should_be3 = 1811939382;
  printf("Is: %u, should be: %u\n", res3, should_be3);
 
  //Test 2-9
  printf("Bitcount: %d, Oldbitcount: %d\n", bitcount(bits1), oldbitcount(bits1));

  return 0;
}
