#include <stdio.h>
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE]; //Storage for alloc
static char *allocp = allocbuf; //Next free position (start at 0)

char *alloc(int n) {
  if (ALLOCSIZE + allocbuf - allocp < n) {
    return NULL; //Not enough space
  }
  allocp += n;
  return allocp - n;
}

//I think this is actually quite broken, but that's the way this is in the book
//Better not request two pieces of memory and only return the first one
void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
