/* test.c - sandbox to test C features
 * 20101123 sampo@iki.fi
 * gcc -o test test.c
 */

#include <stdio.h>

struct foo {
  char* a;
  int b[];
};

struct foo foox = { "A", {1,2,3,0}};

int main(int argc, char** argv)
{
  printf("sizeof(struct foo)=%d sizeof(foox)=%d\n", sizeof(struct foo), sizeof(foox));
  printf("a(%s) b0(%d) b1(%d) b2(%d) b3(%d)\n", foox.a,foox.b[0],foox.b[1],foox.b[2],foox.b[3]);
  return 0;
}

/* EOF - test.c */
