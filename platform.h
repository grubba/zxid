/*
 *  $Id: platform.h,v 1.2 2009-11-24 23:53:40 sampo Exp $
 */

#ifndef _platform_h
#define _platform_h

#ifdef MINGW
#define fdtype HANDLE
#define BADFD (INVALID_HANDLE_VALUE)
#define closefile(x) (CloseHandle(x)?0:-1)
#define openfile_ro(path) CreateFile((path), GENERIC_READ, FILE_SHARE_READ, 0 /*security*/, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)
#define geteuid() 0
#define getegid() 0
#else
#define fdtype int
#define BADFD (-1)
#define closefile(x) close(x)
#define openfile_ro(path) open((path),O_RDONLY)
#endif

#endif
