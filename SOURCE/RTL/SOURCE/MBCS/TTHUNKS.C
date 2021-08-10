/*-----------------------------------------------------------------------*
 * filename - thunks.c
 *
 * This file contains the function thunks for tchar.h functions
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbstring.h>

/* String functions */

 char * _RTLENTRY _EXPFUNC _tcschr(const char * _s1,unsigned int _c)
 {
	return (char *)_mbschr((const unsigned char *)_s1,_c);
 }

 size_t _RTLENTRY _EXPFUNC _tcscspn(const char * _s1,const char * _s2)
 {
 	return _mbscspn((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 char * _RTLENTRY _EXPFUNC _tcsncat(char * _s1,const char * _s2,size_t _n)
 {
 	return (char *)_mbsnbcat((unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 char * _RTLENTRY _EXPFUNC _tcsncpy(char * _s1,const char * _s2,size_t _n)
 {
 	return (char *)_mbsnbcpy((unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 char * _RTLENTRY _EXPFUNC _tcspbrk(const char * _s1,const char * _s2)
 {
 	return (char *)_mbspbrk((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 char * _RTLENTRY _EXPFUNC _tcsrchr(const char * _s1,unsigned int _c)
 {
 	return (char *)_mbsrchr((const unsigned char *)_s1,_c);
 }
 
 size_t _RTLENTRY _EXPFUNC _tcsspn(const char * _s1,const char * _s2)
 {
 	return _mbsspn((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 char * _RTLENTRY _EXPFUNC _tcsstr(const char * _s1,const char * _s2)
 {
 	return (char *)_mbsstr((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 char * _RTLENTRY _EXPFUNC _tcstok(char * _s1,const char * _s2)
 {
 	return (char *)_mbstok((unsigned char *)_s1,(const unsigned char *)_s2);
 }
 

 char * _RTLENTRY _EXPFUNC _tcsnset(char * _s1,unsigned int _c,size_t _n)
 {
 	return (char *)_mbsnbset((unsigned char *)_s1,_c,_n);
 }
 
 char * _RTLENTRY _EXPFUNC _tcsrev(char * _s1)
 {
 	return (char *)_mbsrev((unsigned char *)_s1);
 }
 
 char * _RTLENTRY _EXPFUNC _tcsset(char * _s1,unsigned int _c)
 {
 	return (char *)_mbsset((unsigned char *)_s1,_c);
 }
 

 int _RTLENTRY _EXPFUNC _tcscmp(const char * _s1,const char * _s2)
 {
 	return _mbscmp((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 int _RTLENTRY _EXPFUNC _tcsicmp(const char * _s1,const char * _s2)
 {
 	return _mbsicmp((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 int _RTLENTRY _EXPFUNC _tcsnccmp(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsncmp((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 int _RTLENTRY _EXPFUNC _tcsncmp(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsnbcmp((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 int _RTLENTRY _EXPFUNC _tcsncicmp(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsnicmp((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 int _RTLENTRY _EXPFUNC _tcsnicmp(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsnbicmp((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 

 int _RTLENTRY _EXPFUNC _tcscoll(const char * _s1,const char * _s2)
 {
 	return _mbscoll((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 
 int _RTLENTRY _EXPFUNC _tcsicoll(const char * _s1,const char * _s2)
 {
 	return _mbsicoll((const unsigned char *)_s1,(const unsigned char *)_s2);
 }

 int _RTLENTRY _EXPFUNC _tcsnccoll(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsncoll((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 int _RTLENTRY _EXPFUNC _tcsncoll(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsnbcoll((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 
 int _RTLENTRY _EXPFUNC _tcsncicoll(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsnicoll((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }

 int _RTLENTRY _EXPFUNC _tcsnicoll(const char * _s1,const char * _s2,size_t _n)
 {
 	return _mbsnbicoll((const unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }

/* "logical-character" mappings */

 size_t _RTLENTRY _EXPFUNC _tcsclen(const char * _s1)
 {
 	return _mbslen((const unsigned char *)_s1);
 }

 char * _RTLENTRY _EXPFUNC _tcsnccat(char * _s1,const char * _s2,size_t _n)
 {
 	return (char *)_mbsncat((unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 char * _RTLENTRY _EXPFUNC _tcsnccpy(char * _s1,const char * _s2,size_t _n)
 {
 	return (char *)_mbsncpy((unsigned char *)_s1,(const unsigned char *)_s2,_n);
 }
 char * _RTLENTRY _EXPFUNC _tcsncset(char * _s1,unsigned int _c,size_t _n)
 {
 	return (char *)_mbsnset((unsigned char *)_s1,_c,_n);
 }

/* MBCS-specific mappings */

 char * _RTLENTRY _EXPFUNC _tcsdec(const char * _s1,const char * _s2)
 {
 	return (char *)_mbsdec((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 char * _RTLENTRY _EXPFUNC _tcsinc(const char * _s1)
 {
 	return (char *)_mbsinc((const unsigned char *)_s1);
 }
 size_t _RTLENTRY _EXPFUNC _tcsnbcnt(const char * _s1,size_t _n)
 {
 	return _mbsnbcnt((const unsigned char *)_s1,_n);
 }
 size_t _RTLENTRY _EXPFUNC _tcsnccnt(const char * _s1,size_t _n)
 {
 	return _mbsnccnt((const unsigned char *)_s1,_n);
 }
 char * _RTLENTRY _EXPFUNC _tcsninc(const char * _s1,size_t _n)
 {
 	return (char *)_mbsninc((const unsigned char *)_s1,_n);
 }
 char * _RTLENTRY _EXPFUNC _tcsspnp(const char * _s1,const char * _s2)
 {
 	return (char *)_mbsspnp((const unsigned char *)_s1,(const unsigned char *)_s2);
 }
 char * _RTLENTRY _EXPFUNC _tcslwr(char * _s1)
 {
 	return (char *)_mbslwr((unsigned char *)_s1);
 }
 char * _RTLENTRY _EXPFUNC _tcsupr(char * _s1)
 {
 	return (char *)_mbsupr((unsigned char *)_s1);
 }

 size_t _RTLENTRY _EXPFUNC _tclen(const char * _s1)
 {
 	return _mbclen((const unsigned char *)_s1);
 }
 void _RTLENTRY _EXPFUNC _tccpy(char * _s1,const char * _s2)
 {
 	_mbccpy((unsigned char *)_s1,(const unsigned char *)_s2); return;
 }
int _RTLENTRY _EXPFUNC _tccmp(const char *s1, const char *s2)
{
	return  _mbsncmp((const unsigned char *)s1,(const unsigned char *)s2,1);
}

 unsigned int _RTLENTRY _EXPFUNC _tcsnextc(const char * _s1)
 {
 	unsigned int _n=0;
   if (_ismbblead((unsigned int)*(unsigned char *)_s1))
   	 _n=((unsigned int)*_s1++)<<8;
   _n+=(unsigned int)*_s1;
   return(_n);
 }

