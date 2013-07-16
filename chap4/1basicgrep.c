#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getl(char line[], int max);
int strrindex(char source[], char searchfor[]);
int strindex(char source[], char searchfor[]);


int main() {
  char line[MAXLINE];
  int found = 0;
  while (getl(line, MAXLINE) > 0) {
    if (strrindex(line, "abba") >= 0) {
      printf("%s", line);
      found++;
    }
  }
  return found;
}

/* getline: get line into s, return length*/
int getl(char s[], int lim) {
  int c, i;
  i = 0;

  while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }

  if (c == '\n') {
    s[i++] = c;
  }

  s[i] = '\0';
  return i;
}

/* strrindex: return the last index where t appears in s, -1 otherwise */
int strrindex(char s[], char t[]) {
  int lent = strlen(t);
  int lens = strlen(s);
  
  if (lent <= 0)
    return -1;

  int i, j, k;

  for (i = lens - lent; i >= 0; i--) {
    for (j=i, k=0; k < lent && s[j] == t[k]; j++, k++)
      ;
    if (k == lent)
      return i;
  }

  return -1;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k>0 && t[k]=='\0')
      return i;
  }
  return -1;
}
