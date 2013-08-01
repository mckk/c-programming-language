#include <stdio.h>
/* strcpy: copy t to s */
void mystrcpy(char *s, char *t) {
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
  /* can also be (but I think it's unreadable:
  while (*s++ = *t++)
    ;
  */
}

/* strcmp: return <0 if s<t, 0 if s == t, >0 if s>t */
int mystrcmp(char *s, char *t) {
  for ( ; *s == *t; s++, t++) {
    if (*s == '\0')
      return 0;
  }
  return *s - *t;
}

/* Exercise 5-3
 * strcat: Copies contents of source at the end of dest */
char *strcat(char *dest, const char* source) {
  char *d = dest;
  // Move to the end of dest
  while (*dest != '\0') {
    dest++;
  } // *dest is now '\0'


  while (*source != '\0') {
    *dest++ = *source++;
  }
  *dest = '\0';
  return d;
}

/* Exercise 5-4
 * strend: returns 1 if t occurs at the end of s and 0 otherwise */
int strend(char *s, char *t) {
  char *begs = s;
  char *begt = t;

  // Move to the end of s
  while (*s != '\0')
    s++;
  // Move to the end of t
  while (*t != '\0')
    t++;
  //Now both t and s are at '\0'

  while (*s == *t && s > begs && t > begt) {
    s--;
    t--;
  }

  //Success the last checked letters are equal and we're at the beginning of t;
  if (*s == *t && t == begt)
    return 1;

  return 0;
}

/* Exercise 5-5 */
/* strncpy: Copies the first n characters from src to dest
 * if src < n fill the rest with '\0' */
char *mystrncpy(char *dest, const char *src, const int n) {
  char *d = dest;

  int i;
  for (i = 0; i < n && src != '\0'; dest++, src++, i++) {
    *dest = *src;
  }
  while (i < n) {
    *dest++ = '\0';
  }

  return d;
}

int main() {
  // Test Exercise 5-3
  {
    char s1[28] = "hello";
    char s2[] = "eheheheheheh";
    printf("%s\n", strcat(s1, s2));
  }

  // Test Exercise 5-4
  {
    char s1[] = "hello";
    char s2[] = "eh"; 
    char s3[] = "johneh";
    printf("Should be 1: %d\n", strend(s3, s2));
    printf("Should be 1: %d\n", strend(s3, s3));
    printf("Should be 0: %d\n", strend(s2, s1));
    printf("Should be 0: %d\n", strend(s1, s2));
  }

  return 0;
}
