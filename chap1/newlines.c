#include <stdio.h>

int main() {
  long blanks, tabs, newlines;
  blanks = 0;
  tabs = 0;
  newlines = 0;
  
  int c;
  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++blanks;
    else if (c == '\t')
      ++tabs;
    else if (c == '\n')
      ++newlines;
  }
  printf("Blanks:  %ld\n", blanks);
  printf("Tabs:    %ld\n", tabs);
  printf("Newlines: %ld\n", newlines);
}