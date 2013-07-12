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

int main() {
  // Testing Exercise 3-1
  int a1[] = {1, 2, 3, 4};
  int a2[] = {1, 2, 3};
  int a3[] = {1,3,4,5,6};
  printf("Should be 1, is %d\n", binarysearch(2, a1, 4));
  printf("Should be 1, is %d\n", binarysearch(2, a2, 3));
  printf("Should be -1, is %d\n", binarysearch(2, a3, 5));
}
