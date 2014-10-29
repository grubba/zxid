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
#if 0
  int n;
  char buf[1024];
  size_t cnt = 0;
  size_t cl = -1;
  printf("t0=%d (%d < %d)\n", (0 < -1), cnt, cl);
  printf("t1=%d (%d < %d)\n", (cnt < cl), cnt, cl);
  printf("t2=%d (%d < %d)\n", ((int)cnt < (int)cl), cnt, cl);
  printf("t3=%d (%d < %d)\n", (cnt < (int)cl), cnt, cl);
  printf("t4=%d (%d < %d)\n", (cnt < -1), cnt, cl);
  printf("t5=%d (%d < %d)\n", (0 < cl), cnt, cl);
  cnt = cl;
  printf("t9=%d\n", (cnt < cl));
  printf("sizeof(struct foo)=%d sizeof(foox)=%d\n", sizeof(struct foo), sizeof(foox));
  printf("a(%s) b0(%d) b1(%d) b2(%d) b3(%d)\n", foox.a,foox.b[0],foox.b[1],foox.b[2],foox.b[3]);
 
  n = snprintf(0,0,"see%s","foo");
  printf("snprintf 0,0=%d\n", n);
  n = snprintf(buf,0,"see%s","foo");
  printf("snprintf b,0=%d\n", n);
  n = snprintf(buf,1,"see%s","foo");
  printf("snprintf b,1=%d\n", n);
  n = snprintf(buf,sizeof(buf),"see%s","foo");
  printf("snprintf b,s=%d\n", n);
#endif
#ifdef MINGW
  n = _snprintf(0,0,"see%s","foo");
  printf("_snprintf 0,0=%d\n", n);
  n = _snprintf(buf,0,"see%s","foo");
  printf("_snprintf b,0=%d\n", n);
  n = _snprintf(buf,1,"see%s","foo");
  printf("_snprintf b,1=%d\n", n);
  n = _snprintf(buf,sizeof(buf),"see%s","foo");
  printf("_snprintf b,s=%d\n", n);
#endif
  printf("c=%d\n", argc);
  return 0;
}

/* EOF - test.c */
