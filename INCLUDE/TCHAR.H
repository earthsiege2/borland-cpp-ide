/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1995, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__TCHAR_H)
#define __TCHAR_H

#ifdef  __cplusplus
extern "C" {
#endif

#define _tWinMain       WinMain
#define _targv          _argv
#define _tenviron       _environ
#define _tfullpath      _fullpath
#define _tmakepath      _makepath
#define _tpopen         _popen
#define _tsplitpath     _splitpath
#define _tstrdate       _strdate
#define _tstrtime       _strtime
#define _taccess        access
#define _tasctime       asctime
#define _ttoi           atoi
#define _ttol           atol
#define _tchdir         chdir
#define _tchmod         chmod
#define _tcreat         creat
#define _tctime         ctime
#define _texecl         execl
#define _texecle        execle
#define _texeclp        execlp
#define _texeclpe       execlpe
#define _texecv         execv
#define _texecve        execve
#define _texecvp        execvp
#define _texecvpe       execvpe
#define _tfdopen        fdopen
#define _fgettc         fgetc
#define _fgettchar      fgetchar
#define _fgetts         fgets
#define _tfindfirst     findfirst
#define _tfindnext      findnext
#define _tfopen         fopen
#define _ftprintf       fprintf
#define _fputtc         fputc
#define _fputtchar      fputchar
#define _fputts         fputs
#define _tfreopen       freopen
#define _ftscanf        fscanf
#define _tfsopen        fsopen
#define _gettc          getc
#define _gettchar       getchar
#define _tgetcwd        getcwd
#define _tgetenv        getenv
#define _getts          gets
#define _istalnum       isalnum
#define _istalpha       isalpha
#define _istascii       isascii
#define _istcntrl       iscntrl
#define _istdigit       isdigit
#define _istgraph       isgraph
#define _istlower       islower
#define _istprint       isprint
#define _istpunct       ispunct
#define _istspace       isspace
#define _istupper       isupper
#define _istxdigit      isxdigit
#define _itot           itoa
#define _ltot           ltoa
#define _tmain          main
#define _tmkdir         mkdir
#define _tmktemp        mktemp
#define _topen          open
#define _tperror        perror
#define _tprintf        printf
#define _puttc          putc
#define _puttchar       putchar
#define _tputenv        putenv
#define _putts          puts
#define _tremove        remove
#define _trename        rename
#define _trmdir         rmdir
#define _tscanf         scanf
#define _tsetlocale     setlocale
#define _tsopen         sopen
#define _tspawnl        spawnl
#define _tspawnle       spawnle
#define _tspawnlp       spawnlp
#define _tspawnlpe      spawnlpe
#define _tspawnv        spawnv
#define _tspawnve       spawnve
#define _tspawnvp       spawnvp
#define _tspawnvpe      spawnvpe
#define _stprintf       sprintf
#define _stscanf        sscanf
#define _tstat          stat
#define _tcscat         strcat
#define _tcschr         strchr
#define _tcscmp         strcmp
#define _tcscoll        strcoll
#define _tcscpy         strcpy
#define _tcscspn        strcspn
#define _tcsdec         strdec
#define _tcsdup         strdup
#define _tcsftime       strftime
#define _tcsicmp        stricmp
#define _tcsinc         strinc
#define _tcslen         strlen
#define _tcslwr         strlwr
#define _tcsncmp        strncmp
#define _tcsnbcnt       strncnt
#define _tcsncoll       strncoll
#define _tcsncpy        strncpy
#define _tcsnextc       strnextc
#define _tcsnicmp       strnicmp
#define _tcsninc        strninc
#define _tcspbrk        strpbrk
#define _tcsrchr        strrchr
#define _tcsrev         strrev
#define _tcsset         strset
#define _tcsspn         strspn
#define _tcsspnp        strspnp
#define _tcsstr         strstr
#define _tcstod         strtod
#define _tcstok         strtok
#define _tcstol         strtol
#define _tcstoul        strtoul
#define _tcsupr         strupr
#define _tcsxfrm        strxfrm
#define _tsystem        system
#define _ttempnam       tempnam
#define _ttmpnam        tmpnam
#define _totlower       tolower
#define _totupper       toupper
#define _ultot          ultoa
#define _ungettc        ungetc
#define _tunlink        unlink
#define _tutime         utime
#define _vftprintf      vfprintf
#define _vtprintf       vprintf
#define _vstprintf      vsprintf

#define strinc(a)       ((a)+1)
#define strdec(a, b)    ((b)-1)
#define strnextc(a)     ((unsigned int) *(a))
#define strninc(a, b)   ((a)+(b))
#define strncnt(a, b)   ((strlen(a)>b) ? b : strlen(a))
#define strspnp(a, b)  ((*((a)+strspn(a,b))) ? ((a)+strspn(a,b)) : NULL)

#define _tclen(a)       (1)
#define _tccpy(a,b)     ((*(a))=(*(b)))
#define _tccmp(a,b)     ((*(a))-(*(b)))

#define _istlegal(a)    (1)
#define _istlead(a)     (0)
#define _istleadbyte(a) (0)

#if defined(_UNICODE)

#ifndef __TCHAR_DEFINED
typedef wchar_t         _TCHAR;
typedef wchar_t         _TSCHAR;
typedef wchar_t         _TUCHAR;
typedef wchar_t         _TXCHAR;
#if !defined (__BORLANDC__)  /* Borland C++ does not support 64-bit chars */
  typedef wint_t        _TINT;
#endif /* __BORLANDC__ */
#define __TCHAR_DEFINED
#endif

#define _TEOF           WEOF
#define __T(x)          L ## x

#undef  _tcslen
#undef  _tcscpy

#define _tcslen         wcslen
#define _tcscpy         wcscpy

#else

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef char            _TXCHAR;
typedef int             _TINT;
#define __TCHAR_DEFINED
#endif

#define _TEOF           EOF
#define __T(x)          x

#endif 	/* _UNICODE */

#define _TEXT(x)        __T(x)
#define _T(x)           __T(x)

#ifdef __cplusplus
}
#endif

#endif	/* __TCHAR_H */
