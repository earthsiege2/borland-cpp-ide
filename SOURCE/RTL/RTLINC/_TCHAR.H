/*------------------------------------------------------------------------
 * filename - _tchar.h
 *
 *  Definitions for RTL UNICODE helper functions.
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1996, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */


/* $Revision: 9.6.2.1 $ */

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif

#if !defined(__TCHAR_H)
#include <tchar.h>
#endif

#if !defined(_UNICODE)
#define _tstartup                            _startup
#define _tstartupd                           _startupd
#define _tsetargv                            _setargv
#define _thandle_setargv                     _handle_setargv
#define _thandle_exitargv                    _handle_exitargv
#define _tsetargv__                          _setargv__
#define _tsetenvp__                          _setenvp__
#define _tsetargv0                           _setargv0
#define _tsetargv2                           _setargv2
#define _targv0                              _argv0
#define _targv                               _argv
#define __dll_targv                          __dll_argv
#define _texitargv                           _exitargv
#define _texitargv0                          _exitargv0
#define _texitargv2                          _exitargv2
#define _taddarg                             _addarg
#define _tcopychar                           _copychar
#define _tcmdsave                            _cmdsave
#define _targv_default_expand                _argv_default_expand
#define _texpand_wild                        _expand_wild
#define _targv_expand_ptr                    _argv_expand_ptr
#define _tsetargv_ptr                        _setargv_ptr
#define _texitargv_ptr                       _exitargv_ptr
#define _tsetenv                             _setenv
#define _tsetenvp                            _setenvp
#define _tLoadProg                           _LoadProg
#define _tsearch                             _search
#define _tsearchenv                          _searchenv
#define _tmake_cmdline                       _makecmdline
#define _tmake_env                           _make_env
#define _tenv_lock                           _env_lock
#define _tlock_env                           _lock_env
#define _tunlock_env                         _unlock_env
#define _tenvsize                            _envsize
#define _texpandblock                        _expandblock
#define _tenvcpy                             _envcpy
#define _tenvcopy                            _envcopy
#define _tosenv                              _osenv
#define _toscmd                              _oscmd
#define _tC0environ                          _C0environ
#define _tC0argc                             _C0argc
#define _tC0argv                             _C0argv
#define _textenvp                            _extenvp
#define __tread                              __read
#define __fgettc                             _fgetc
#define __fputtc                             _fputc
#define __fputnt                             __fputn
#define ___topen                             __open
#define __topenfp                            __openfp
#define _lgettc                              _lgetc
#define _lputtc                              _lputc
#define _longtot                             __longtoa
#define __int64tot                           __int64toa
#define _scanttod                            _scantod
#define _scanttol                            _scantol
#define __scanttod                           __scantod
#define __scanttol                           __scantol
#define __scanttoint64                       __scantoint64
#define _utot                                __utoa
#define _scanttodptr                         _scantodptr
#define _scanrsltt                           _scanrslt
#define __scanrsltt                          __scanrslt
#define _scan_initt                          _scan_init
#define _scantrsltptr                        _scanrsltptr
#define _realcvtt                            _realcvt
#define __realcvtt                           __realcvt
#define _cvt_initt                           _cvt_init
#define _nextrealt                           _nextreal
#define __nextrealt                          __nextreal
#define _realcvttptr                         _realcvtptr
#define _nextrealtptr                        _nextrealptr
#define __xcvtt                              __xcvt
#define _turboFloatt                         _turboFloat
#define _floatconvertt                       _floatconvert
#define decimal_point_tchar                  decimal_point_char
#define _tGetVol                             GetVol
#define _tDfltZone                           _DfltZone
#define _tDfltLight                          _DfltLight
#define __tmkname                            __mkname
#define __ttmpnam                            __tmpnam
#define _tatime                              _atime
#define __isttype                            __isctype
#define _ltotlower                           _ltolower
#define _ltotupper                           _ltoupper
#define _tDosCreate                          _DosCreate
#define __vprintert                          __vprinter
#define _scannert                            _scanner
#define __Gett                               __Get
#define __UnGett                             __UnGet

#else  //UNICODE

#define _tstartup                            _wstartup
#define _tstartupd                           _wstartupd
#define _tsetargv                            _wsetargv
#define _thandle_setargv                     _handle_wsetargv
#define _thandle_exitargv                    _handle_wexitargv
#define _tsetargv__                          _wsetargv__
#define _tsetenvp__                          _wsetenvp__
#define _tsetargv0                           _wsetargv0
#define _tsetargv2                           _wsetargv2
#define _targv0                              _wargv0
#define _targv                               _wargv
#define __dll_targv                          __dll_wargv
#define _texitargv                           _wexitargv
#define _texitargv0                          _wexitargv0
#define _texitargv2                          _wexitargv2
#define _taddarg                             _waddarg
#define _tcopychar                           _wcopychar
#define _tcmdsave                            _wcmdsave
#define _targv_default_expand                _wargv_default_expand
#define _texpand_wild                        _wexpand_wild
#define _targv_expand_ptr                    _wargv_expand_ptr
#define _tsetargv_ptr                        _wsetargv_ptr
#define _texitargv_ptr                       _wexitargv_ptr
#define _tsetenv                             _wsetenv
#define _tsetenvp                            _wsetenvp
#define _tLoadProg                           _wLoadProg
#define _tsearch                             _wsearch
#define _tsearchenv                          _wsearchenv
#define _tmake_cmdline                       _wmakecmdline
#define _tmake_env                           _wmake_env
#define _tenv_lock                           _wenv_lock
#define _tlock_env                           _wlock_env
#define _tunlock_env                         _wunlock_env
#define _tenvsize                            _wenvsize
#define _texpandblock                        _wexpandblock
#define _tenvcpy                             _wenvcpy
#define _tenvcopy                            _wenvcopy
#define _tosenv                              _wosenv
#define _toscmd                              _woscmd
#define _tC0environ                          _wC0environ
#define _tC0argc                             _wC0argc
#define _tC0argv                             _wC0argv
#define _textenvp                            _wextenvp
#define __tread                              __wread
#define __fgettc                             _fgetwc
#define __fputtc                             _fputwc
#define __fputnt                             __fputnw
#define ___topen                             ___wopen
#define __topenfp                            __wopenfp
#define _lgettc                              _lgetwc
#define _lputtc                              _lputwc
#define _longtot                             __longtow
#define __int64tot                           __int64tow
#define _scanttod                            _scanwtod
#define _scanttol                            _scanwtol
#define __scanttod                           __scanwtod
#define __scanttol                           __scanwtol
#define __scanttoint64                       __scanwtoint64
#define _utot                                __utow
#define _scanttodptr                         _scanwtodptr
#define _scanrsltt                           _scanrsltw
#define __scanrsltt                          __scanrsltw
#define _scan_initt                          _scan_initw
#define _scantrsltptr                        _scanwrsltptr
#define _realcvtt                            _realcvtw
#define __realcvtt                           __realcvtw
#define _nextrealt                           _nextrealw
#define __nextrealt                          __nextrealw
#define _cvt_initt                           _cvt_initw
#define _realcvttptr                         _realcvtwptr
#define _nextrealtptr                        _nextrealwptr
#define __xcvtt                              __xcvtw
#define _turboFloatt                         _turboFloatw
#define _floatconvertt                       _floatconvertw
#define decimal_point_tchar                  decimal_point_wchar_t
#define _tGetVol                             _wGetVol
#define _tDfltZone                           _wDfltZone
#define _tDfltLight                          _wDfltLight
#define __tmkname                            __wmkname
#define __ttmpnam                            __wtmpnam
#define _tatime                              _watime
#define __isttype                            __iswctype
#define _ltotlower                           _ltowlower
#define _ltotupper                           _ltowupper
#define _tDosCreate                          _wDosCreate
#define __vprintert                          __vprinterw
#define _scannert                            _scannerw
#define __Gett                               __Getw
#define __UnGett                             __UnGetw
#endif

#if !defined(_UNICODE)
int _expandblock (void);
#else
int _wexpandblock (void);
#endif

