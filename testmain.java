/* This program, and the associated DLL and Jave files, is to test dynamic
 * linking and Java JNI loading on Windows platform, especially if MinGW
 * cross compilation environment is used.
 * 20100521, Sampo Kellomaki (sampo@iki.fi)
 *
 * testmain.c     -  Test dll at C level by calling test_third()
 * testmain.java  -  Test JNI at Java level by calling testjni.test_first(1)
 *                   and testjni.test_second("foo") at Java level. Must be
 *                   in parent directory of zxidjava
 * testjni.c      -  JNI glue, actual source code for the DLL, where
 *                   test_first(), test_second(), and test_third()
 *                   are implemented.
 * testjni.java   -  Java level interface to the DLL
 * testjniJNI.jave - Java level JNI declarations of the C functions in testjni.c
 * testjniConstants.java - Constant declarations (not relevant?)
 */

import zxidjava.*;

public class testmain {
  public static void main(String argv[]) throws java.io.IOException
  {
    System.err.print("HERE1\n");
    System.loadLibrary("testjni");
    System.err.print("HERE2\n");
    int x = testjni.test_first(1);
    System.err.print("HERE3 x="+x+"\n");
    String s = testjni.test_second("Test");
    System.err.print("HERE4 s("+s+")\n");
  }
}  
