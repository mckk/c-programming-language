#include <stdio.h>

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


int main() {
  // Testing Exercise 3-1
  int a1[] = {1, 2, 3, 4};
  int a2[] = {1, 2, 3};
  int a3[] = {1,3,4,5,6};
  printf("Should be 1, is %d\n", binarysearch(2, a1, 4));
  printf("Should be 1, is %d\n", binarysearch(2, a2, 3));
  printf("Should be -1, is %d\n", binarysearch(2, a3, 5));

  // Testing Exercise 3-2
  char s[] = "Hello\t\nJohn\t";
  char t[] = "aaaaaaaaaaaaaaaaaaaaaaa";

  printf("Before:\n");
  printf("One:\n%s\n", s);
  printf("Two:\n%s\n", t);
  
  escape(s, t);
  printf("After:\n");
  printf("One:\n%s\n", s);
  printf("Two:\n%s\n", t);
}
