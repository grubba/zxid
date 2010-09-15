/* This program, and the associated DLL and Jave files, is to test dynamic
 * linking and Java JNI loading on Windows platform, especially if MinGW
 * cross compilation environment is used.
 * 20100521, Sampo Kellomaki (sampo@iki.fi)
 *
 * testmain.c     -  Test dll at C level by calling test_third()
 * testmain.java  -  Test JNI at Java level by calling testjni.test_first(1)
 *                   and testjni.test_second("foo") at Java level
 * testjni.c      -  JNI glue, actual source code for the DLL, where
 *                   test_first(), test_second(), and test_third()
 *                   are implemented.
 * testjni.java   -  Java level interface to the DLL
 * testjniJNI.jave - Java level JNI declarations of the C functions in testjni.c
 * testjniConstants.java - Constant declarations (not relevant?)
 */

#include <stdio.h>
#include <windows.h>

void die(char* what) {
  LPVOID lpMsgBuf;
  LPVOID lpDisplayBuf;
  DWORD dw = GetLastError(); 

  FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL );
  fprintf(stderr, "ERR: %s: (%d) %s\n", what, dw, lpMsgBuf);
  fflush(stderr);
  exit(1);
}

int main() {
  HANDLE dll;
  DWORD res;
  int (*proc)(int);
  int x;
  
  fprintf(stderr, "HERE1\n");
  fflush(stderr);
  dll = LoadLibrary("testjni.dll");
  fprintf(stderr, "HERE2 dll=%p\n", dll);
  fflush(stderr);
  if (!dll)
    die("LoadLibrary");
  proc = GetProcAddress(dll,"test_third");
  fprintf(stderr, "HERE3 proc=%p\n", proc);
  fflush(stderr);
  if (!proc)
    die("GetProcAddress");
  x = proc(3);
  fprintf(stderr, "HERE4 x=%d\n", x);
  fflush(stderr);
  return 0;
}
