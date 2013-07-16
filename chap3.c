#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

// Util

void reverse(char s[]) {
  int len = strlen(s);
  int i;

  for (i = 0; i < len/2; i++) {
    char tmp = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = tmp;
  }
}

// Exercise 3-1
int binarysearch(int x, int v[], int n) {
  int low, high, mid;
  
  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low+high) / 2;
    if (x <= v[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return (v[high] == x) ? high : -1;
}

// Exercise 3-2
char getEscapedChar(char c) {
  switch (c) {
  case '\t':
    return 't';
  case '\n':
    return 'n';
  }
  return 0;
}

void escape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  while (s[i] != '\0') {
    switch (s[i]) {
    case '\t':
    case '\n':
      t[j++] = '\\';
      t[j++] = getEscapedChar(s[i]);
      break;
    default:
      t[j++] = s[i];
      break;
    }
    i++;
  }
  t[j] = '\0';
}

char getDescapedChar(char c) {
  switch (c) {
  case 't':
    return '\t';
  case 'n':
    return '\n';
  }
  return '\\';
}

void descape(char s[], char t[]) {
  int i = 0;
  int j = 0;
  char c;
  while (s[i] != '\0') {
    switch (s[i]) {
    case '\\':
      c = getDescapedChar(s[i+1]);
      switch (c) {
      case '\\':
        t[j++] = '\\';
        break;
      default:
        t[j++] = c;
        i++;
        break;
      }
      break;
    default:
      t[j++] = s[i];
      break;
    }
    i++;
  }
  t[j] = '\0';
}


// Exercise 3-3
int insertrange(char from, char to, char s[]) {
  if (!isalnum(from) || !isalnum(to)) {
    return 0;
  }

  int i = 0;
  char c;
  for (c = from+1; c < to; c++) {
    s[i++] = c;
  }
  return i;
}

void expand(char s1[], char s2[]) {
  int i;
  int j = 0;
  for (i=0; s1[i] != '\0'; i++) {
    if (s1[i] == '-' && (i-1) > 0) {
      j += insertrange(s1[i-1], s1[i+1], &s2[j]);
    } else {
      s2[j++] = s1[i];
    } 
  }
  s2[j] = '\0';
}

// Exercise 3-4
void itoa(int n, char s[]) {
  int i, sign;

  sign = (n < 0) ? -1 : 1;
 
  i = 0;
  do {
    s[i++] = sign*(n % (sign*10)) + '0';
    n = sign*(n / (sign*10));
  } while (n != 0);

  if (sign < 0) {
    s[i++] = '-';  
  }

  s[i] = '\0';

  reverse(s);
}

// Exercise 3-5

char tochar(int n) {
  if (n < 10) {
    return '0' + n;
  }
  return 'A' + (n-10);
}

void itob(int n, char s[], int b) {
  int i, sign;

  if (n < 0) {
    sign = -1;
  } else {
    sign = 1;
  }
 
  i = 0;
  do {
    int num =  sign*(n % (sign*b)); 
    s[i++] = tochar(num);
    n = sign*(n / (sign*b));
  } while (n != 0);

  if (sign < 0) {
    s[i++] = '-';  
  }

  s[i] = '\0';

  reverse(s);
}

// Exercise 3-6
void itoapad(int n, char s[], int pad) {
  int i, sign;

  if (n < 0) {
    sign = -1;
  } else {
    sign = 1;
  }
 
  i = 0;
  do {
    s[i++] = sign*(n % (sign*10)) + '0';
    n = sign*(n / (sign*10));
  } while (n != 0);


  if (sign < 0) {
    pad = pad - i - 1;
  } else {
    pad = pad - i;
  }

  if (sign < 0) {
    s[i++] = '-';  
  }

  while (pad > 0) {
    s[i++] = '_';
    pad--;
  }

  s[i] = '\0';

  reverse(s);
}

int main() {
  // Testing Exercise 3-1
  int a1[] = {1, 2, 3, 4};
  int a2[] = {1, 2, 3};
  int a3[] = {1,3,4,5,6};
  printf("Should be 1, is %d\n", binarysearch(2, a1, 4));
  printf("Should be 1, is %d\n", binarysearch(2, a2, 3));
  printf("Should be -1, is %d\n", binarysearch(2, a3, 5));

  // Testing Exercise 3-2
  char s[] = "Hi\\ello\t\nJohn\t";
  char t[] = "aaaaaaaaaaaaaaaaaaaaaaa";

  printf("Before:\n");
  printf("One:\n%s\n", s);
  printf("Two:\n%s\n", t);
  
  escape(s, t);
  printf("After:\n");
  printf("One:\n%s\n", s);
  printf("Two:\n%s\n", t);

  descape(t,s);
  printf("Descaped:\n%s\n", s);

  // Testing Exercise 3-3
  char expandable[] = "-a-z0-9";
  char another[128]; 

  expand(expandable, another);

  printf("%s\n", another);

  // Testing Exercise 3-4
  char snum[128];

  itoa(INT_MIN, snum);
  printf("%s\n", snum);

  // Testing Exercise 3-5 
  itob(-30250, snum, 16);
  printf("%s\n", snum);

  // Testing Exercise 3-6 
  itoapad(-3025, snum, 10);
  printf("%s\n", snum);
}
