/*
 *  $Id: platform.h,v 1.2 2009-11-24 23:53:40 sampo Exp $
 */

#ifndef _platform_h
#define _platform_h

#ifdef MINGW

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

#define fdstdout (GetStdHandle(STD_OUTPUT_HANDLE))
/*#define fdtype HANDLE   see zxid.h */
#define BADFD (INVALID_HANDLE_VALUE)
#define closefile(x) (CloseHandle(x)?0:-1)
#define openfile_ro(path) CreateFile((path), GENERIC_READ, FILE_SHARE_READ, 0 /*security*/, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0)
#define geteuid() 0
#define getegid() 0

#ifdef WIN32CL
/* The directory handling is quite different on Windows. The following
 * posix wrappers are implemented in zxdirent.c */
typedef struct DIR DIR;
struct dirent {
  char* d_name;
};
#define opendir zx_win23_opendir
#define readdir zx_win23_readdir
#define closedir zx_win23_closedir
#define rewinddir zx_win23_rewinddir
DIR* zx_win23_opendir(char*);
struct dirent* zx_win23_readdir(DIR*);
int zx_win23_closedir(DIR*);
void zx_win23_rewinddir(DIR*);

typedef struct stack_st STACK;  /* MSVC seems to have some problem with openssl/stack.h */

#define snprintf _snprintf
#define va_copy(ap2, ap) ap2 = ap
#define symlink(a,b) ( ERR("symlink(2) (%s => %s) not supported by Win32", (a),(b)), -1 )
#define unlink(a)    ( ERR("unlink(2) (%s) not supported by Win32", (a)), -1 )
#define rmdir(a)     ( ERR("rmdir(2) (%s) not supported by Win32", (a)), -1 )
#define close(fd)    ( ERR("close(2) (%s) not supported by Win32. Leaking descriptor.", (a)), -1 )
#define getpid()  0
#define geteuid() 0
#define getegid() 0

#else
#include <dirent.h>
#endif

/* Windows thread identification is a mess:
 * - thread ID returned by GetCurrentThreadId() is like POSIX thread ID except
 *   that almost none of the windows thread API functions accept it as argument.
 *   They need a handle instead.
 * - Handle can not be obtained easily. Instead GetCurrentThread() returns a
 *   pseudohandle (-1) that has only limited usability.
 * - It is not clear what _beginthread() returns. Presumably a handle.
 * In the end we adopt keeping around the thread ID and using OpenThread(0,0,tid)
 * to resolve it to a real thread handle when needed. */
#define pthread_t DWORD    /* what pthread_self() returns, or GetCurrentThreadId() */
#define pthread_self() GetCurrentThreadId()  /* Returns an ID, not a handle */

/* Win32 CRITICAL SECTION based solution (supposedly faster when mutex is only used
 * in one process, especially on uniprocessor machines). */
/*#define pthread_mutex_t CRITICAL_SECTION  see zxid.h */
#define PTHREAD_MUTEX_INITIALIZER     (0) /* All instances of MUTEX_INITIALIZER must be converted to call to pthread_mutex_init() early in main() (zxidmeta.c) */
#define pthread_mutex_init(mutex, ma) (InitializeCriticalSection(mutex),0) /* dsvmcall.c, dsconfig.c, io.c, dsmem.c */
#define pthread_mutex_destroy(mutex)  (DeleteCriticalSection(mutex),0) /* dsvmcall.c */
#define pthread_mutex_trylock(mutex)  (TryEnterCriticalSection(mutex)?0:-1) /* dsvm.c */
#define pthread_mutex_lock(mutex)     (EnterCriticalSection(mutex), 0) /* dsdbilib.c, api_mutex.c, pool.c, sg.c, io.c, shuffler.c EnterCriticalSection() */
#define pthread_mutex_unlock(mutex)   (LeaveCriticalSection(mutex), 0) /* dsvm.c, api_mutex.c, pool.c, sg.c, io.c, shuffler.c LeaveCriticalSection() */

#ifdef __cplusplus
} // extern "C"
#endif

#else

/* NOT MINGW nor WIN32CL (i.e. its Unix) */

#include <dirent.h>

#ifdef __cplusplus
extern "C" {
#endif

#define fdstdout 1
/*#define fdtype int   see zxid.h */
#define BADFD (-1)
#define closefile(x) close(x)
#define openfile_ro(path) open((path),O_RDONLY)

#ifndef _UNISTD_H
/* We do not want to include unistd.h because it does not exist on Win32.
 * So define these here, but protect by ifndef, because unistd.h may get
 * indirectly included. */
int symlink(const char *oldpath, const char *newpath);
int unlink(const char *pathname);
int rmdir(const char *pathname);
int getpid(void);
int geteuid(void);
int getegid(void);
int close(int);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif

#endif
