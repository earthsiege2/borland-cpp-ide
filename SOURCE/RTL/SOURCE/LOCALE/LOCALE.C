/*-----------------------------------------------------------------------*
 * filename - locale.c
 *
 * function(s)
 *      _setLocale32A   - set the locale for ANSI applications
 *      _setLocale32W   - set the locale for UNICODE applications
 *      _getLocale     - get the locale name, sublanguage and codepage from
 *                       given locale name
 *      _cleanCategories - frees the memory for the used categories
 *      _setNewCategories- Allocates memory for new categories and initialize them
 *      _addCategoryName - Adds the category name to the list used by the locale
 *      _setLocaleFromString - Builds the locale from a string resulting from
 *                             a previous call to setlocale()
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1987, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.10.2.1 $        */


#include <INITCAT.H>
#include <_locale.h>
#include <time.h>

extern LPWIN32LOCALE __locale;
extern WIN32MONETARY CMonetary;
extern WIN32NUMERIC CNumeric;
extern WIN32TIME CTimeDate;
extern WIN32LOCALE CLOCALE;

int _RTLENTRY _EXPDATA __mb_cur_max = 1;

/*
  Lock for the locale if MultiThreaded __MT__
*/
LPCRITICAL_SECTION __localeLock = NULL;

/*
  get the locale name, sublanguage and codepage from the locale name specified
  in setLocale32x
*/
LCID _getLocale(LPWIN32LOCALE _locale, LPSTR LocaleName);

/*
  frees the memory for the used categories
*/
void _cleanCategories(LPWIN32LOCALE _locale);

/*
  Allocates memory for new categories and initialize them
*/
int _setNewCategories(LPWIN32LOCALE _locale, SHORT Category);

/*
  Adds the category name to the list used by the locale
*/
int _addCategoryName(LPWIN32LOCALE _locale, LPSTR category);

/*
  Prototype definition for _setmbcp()
*/

int _setmbcp ( int newCodePage );

/*
  clean the locale structure
*/

void _cleanLocale(void);

/*
  Builds the locale from a string resulting from a previous call to setlocale()
*/
LPSTR _setLocaleFromString(LPWIN32LOCALE _locale, LPCSTR LocaleName);

/*
  SetLocale32W
  Transform the LocaleName into single byte string and call setlocale32A
  return a wide string
*/

LPWSTR _setLocale32W(SHORT Category, LPCWSTR LocaleName)
{
    LPSTR localename;
    size_t len;
    _lock_locale();

    if (LocaleName)
    {
        localename = (LPSTR) malloc(4096);
        wcstombs(localename, LocaleName, 4096);
        _setLocale32A(Category, localename);
        if (__locale != &CLOCALE)
        {
            len = strlen(__locale->setLocaleReturn)*2;
            __locale->setLocaleReturnW = realloc(__locale->setLocaleReturnW, len * sizeof(wchar_t));// leak
            mbstowcs(__locale->setLocaleReturnW, __locale->setLocaleReturn, len);
        }
        free(localename);
    }
    else
        _setLocale32A(Category, 0);

    _unlock_locale();

    return __locale->setLocaleReturnW;
}


/*
  SetLocale32A
  Return: The list of open categories for the specified locale
  if an error occurs it return NULL and calls SetLastError() with the
  appropriate Error code

  If LocaleName is NULL then it returns the previous preferred locale if any
  or the System Default Locale
*/

LPSTR _setLocale32A(SHORT Category, LPCSTR localeName)
{
    char codepage[7];
    BOOL restoreC = FALSE;
    char* LocaleName = NULL;
    LCID  Handle = 0;
    char* p;
    CPINFO cpinfo;

    if (localeName)
       LocaleName = strdup(localeName);

    _lock_locale();

    if (__locale == NULL || __locale == &CLOCALE)
    {
        if (__locale == &CLOCALE)
            restoreC = TRUE;
        if ((__locale = (LPWIN32LOCALE) calloc(1, sizeof(WIN32LOCALE))) == NULL)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            free(LocaleName);
            _unlock_locale();
            return NULL;
        }
    }

    if (__locale->setLocaleReturn != NULL)
    {
        free(__locale->setLocaleReturn);
        __locale->setLocaleReturn = NULL;
    }

    if (LocaleName == NULL || LocaleName[0] == 0x0)
    {
        if (LocaleName == NULL)
        {
            if (restoreC)
            {
                _cleanCategories(__locale);
                free(__locale);
                __locale = &CLOCALE;
            }
            else
            {
                if ((Category & LC_MONETARY) == LC_MONETARY)
                   _addCategoryName(__locale, "LC_MONETARY");

                if ((Category & LC_NUMERIC)  == LC_NUMERIC)
                   _addCategoryName(__locale, "LC_NUMERIC");

                if ((Category & LC_TIME)     == LC_TIME)
                   _addCategoryName(__locale, "LC_TIME");

                if ((Category & LC_COLLATE)  == LC_COLLATE)
                   _addCategoryName(__locale, "LC_COLLATE");

                if ((Category & LC_CTYPE)    == LC_CTYPE)
                   _addCategoryName(__locale, "LC_CTYPE");

                free(LocaleName);
                _llocaleconv();
                _unlock_locale();
                return __locale->setLocaleReturn;
            }
        }
        else
        {
            Handle = GetUserDefaultLCID();
            GetLocaleInfoA(Handle, LOCALE_IDEFAULTCODEPAGE, codepage, 7);
            __locale->codepage = atol(codepage);
            __locale->isCLocale = FALSE;
        }
    }
    else
    {
       if (strstr(localeName, "en_US"))
       {
          strcpy(LocaleName, "ENU");
          if ((p = strchr(localeName, '.')) != NULL)
          strcpy(&LocaleName[3], p);
       }
       else
       if (strstr(localeName, "en_GB"))
       {
          strcpy(LocaleName, "ENG");
          if ((p = strchr(localeName, '.')) != NULL)
          strcpy(&LocaleName[3], p);
       }
       else
       if (strstr(localeName, "fr_FR"))
       {
          strcpy(LocaleName, "FRA");
          if ((p = strchr(localeName, '.')) != NULL)
          strcpy(&LocaleName[3], p);
       }
       else
       if (strstr(localeName, "de_DE"))
       {
          strcpy(LocaleName, "DEU");
          if ((p = strchr(localeName, '.')) != NULL)
          strcpy(&LocaleName[3], p);
       }

        if (strcmp(localeName, "C") == 0)
        {
            _cleanCategories(__locale);
            free(__locale);
            __locale = &CLOCALE;
        }
        else
            if (LocaleName[0] == 'L' && LocaleName[1] == 'C' && LocaleName[2] == '_')
            {
                free(LocaleName);
                _unlock_locale();
                return _setLocaleFromString(__locale, localeName);
            }
            else {
                __locale->isCLocale = FALSE;

                if ((Handle = _getLocale(__locale, (LPSTR)LocaleName)) == 0)
                {
                    if (restoreC)
                    {
                       free(__locale);
                       __locale = &CLOCALE;
                    }
                    _unlock_locale();
                    free(LocaleName);
                    return NULL;
                }
            }
    }

    __locale->handle = Handle;
    free(LocaleName);
    if (!IsValidLocale(__locale->handle, LCID_INSTALLED) && !__locale->isCLocale)
    {
        SetLastError(ERROR_LOCALE_NOTINSTALLED);
        if (restoreC)
        {
            _cleanCategories(__locale);
            free(__locale);
            __locale = &CLOCALE;
        }
        _unlock_locale();
        return NULL;
    }

    /*
      SetThreadLocale will only work under NT but it's best to do it in case
      the application uses OLE2 or some other functionnality requiring a
      Locale.
      */
    SetThreadLocale(__locale->handle);

    if (!__locale->isCLocale)
    {
        _cleanCategories(__locale);
        if (_setNewCategories(__locale, Category) == 0)
        {
            SetLastError(ERROR_CATEGORY_INVALID);
            if (restoreC)
            {
               _cleanCategories(__locale);
               free(__locale);
               __locale = &CLOCALE;
            }
            _unlock_locale();
            return NULL;
        }
        if (_setmbcp(__locale->codepage) != 0 ||
            !GetCPInfo(__locale->codepage, &cpinfo))
        {
            _unlock_locale();
            SetLastError(ERROR_MBCS_CODEPAGE_INVALID);
            return NULL;
        }
        __mb_cur_max = cpinfo.MaxCharSize;
        _llocaleconv();
        _unlock_locale();
        return __locale->setLocaleReturn;
    }
    else {
        __mb_cur_max = 1;
        _llocaleconv();
        _unlock_locale();
        return __locale->setLocaleReturn;
    }
}


/*
  lock the locale
*/
void _lockLocale()
{
    EnterCriticalSection(__localeLock);
}

/*
  unlock the locale
*/
void _unlockLocale()
{
    LeaveCriticalSection(__localeLock);
}


/*
  Initializes locales
*/

void _initLocale()
{
#ifdef __MT__
    __localeLock = (LPCRITICAL_SECTION) malloc(sizeof(CRITICAL_SECTION));
    InitializeCriticalSection(__localeLock);
#endif  // __MT__
}
#pragma startup _initLocale 4 /* Initializes the locale system */

/*
  to be call when in the exit session of the program
*/

void _cleanLocale()
{
    _lock_locale();

    _cleanCategories(__locale);
    if (__locale != &CLOCALE)
    {
        if (__locale->setLocaleReturnW)
        {
          free(__locale->setLocaleReturnW);
          __locale->setLocaleReturnW = NULL;
        }
        if (__locale->setLocaleReturn)
        {
          free(__locale->setLocaleReturn);
          __locale->setLocaleReturn = NULL;
        }
        free(__locale);
    }

    _unlock_locale();

#ifdef __MT__
    DeleteCriticalSection(__localeLock);
#endif  // __MT__

    free(__localeLock);
}
#pragma exit _cleanLocale 4 /* Finalizes the locale system */

/*
  get locale real name
*/

LCID _getLocale(LPWIN32LOCALE _locale, LPSTR LocaleName)
{
    BOOL  found = FALSE;
    LCID  locale;
    int   res;
    int   langID = 1;
    int   subID = 1;
    int   lcid = 0;
    char  Language[64] = "none";
    char  ISO3166[4] = "000";
    char  *token;
    char  *savetoken;
    char  codepage[7];

    strlwr(LocaleName);
    while (!found && langID <= MAX_LANGID)
    {
        locale = MAKELCID(MAKELANGID(langID, SUBLANG_DEFAULT), SORT_DEFAULT);
        GetLocaleInfoA(locale, LOCALE_SENGLANGUAGE, Language, 64);
        GetLocaleInfoA(locale, LOCALE_SABBREVLANGNAME, ISO3166, 4);

        strlwr(Language);
        strlwr(ISO3166);

        if (strstr(LocaleName, Language) != NULL)
            found = TRUE;
        else
            if (strstr(LocaleName, ISO3166) == LocaleName)
            {
                found = TRUE;
            }
            else
                langID++;
    }

    // No language specified and no codepage
    if (!found && strchr(LocaleName, '_') == NULL && strchr(LocaleName, '.') == NULL)
    {
        SetLastError(ERROR_LOCALE_INVALID);
        return 0;
    }

    if (!found)
    {
        if (_locale->handle == 0)
            langID = GetSystemDefaultLangID();
        else langID = _locale->handle & 0x3FF;
    }
    // if not just a codepage lcid is now the selected language

    // get the sublanguage if any specified
    if ((token = strchr(LocaleName, '_')) != NULL)
    {
        token++;
        if ((savetoken = strchr(token, '.')) != NULL)
            *savetoken = 0x0;
        found = FALSE;
        res = 1;
        while (!found && res != 0)
        {
            res = GetLocaleInfoA(MAKELCID(MAKELANGID(langID, subID), SORT_DEFAULT),
                LOCALE_SENGCOUNTRY, Language, 64);
            strlwr(Language);
            if (strcmp(Language, token) == 0)
            {
                lcid = MAKELCID(MAKELANGID(langID, subID), SORT_DEFAULT);
                found = TRUE;
            }
            else
                subID++;
        }

        if (!found)
        {
            SetLastError(ERROR_LOCALE_INVALID);
            return 0;
        }

        if (savetoken)
            *savetoken = '.';
    }
    else
    {
        lcid = MAKELCID(MAKELANGID(langID, SUBLANG_DEFAULT), SORT_DEFAULT);
    }


    // get the codepage if any specified
    if ((token = strchr(LocaleName, '.')) == NULL)
    {
        GetLocaleInfoA(lcid, LOCALE_IDEFAULTCODEPAGE, codepage, 7);
        _locale->codepage = atol(codepage);
    }
    else {
        token++;
        _locale->codepage = atol(token);
    }
    //isValidLocale()
    return lcid;
}

/*
  Set the new categories
  0 fails
  1 successes
*/
int _setNewCategories(LPWIN32LOCALE _locale, SHORT Category)
{
    int  Error = 1;

    if (_locale->setLocaleReturn)
        free(_locale->setLocaleReturn);
    _locale->setLocaleReturn = NULL;

    // Allocate the structures for the locale
    if ((Category & LC_MONETARY) == LC_MONETARY)
    {
        if ((_locale->monetary = (LPWIN32MONETARY) malloc(sizeof(WIN32MONETARY))) == NULL)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        Error *= _setMonetary(_locale->handle, _locale->monetary);
        if (Error != 0)
            Error *= _addCategoryName(_locale, "LC_MONETARY");
    }

    if ((Category & LC_TIME) == LC_TIME)
    {
        if ((_locale->time = (LPWIN32TIME) malloc(sizeof(WIN32TIME))) == NULL)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        Error *= _setTime(_locale->handle, _locale->time);
        if (Error != 0)
            Error *= _addCategoryName(_locale, "LC_TIME");
    }

    if ((Category & LC_NUMERIC) == LC_NUMERIC)
    {
        if ((_locale->numeric = (LPWIN32NUMERIC) malloc(sizeof(WIN32NUMERIC))) == NULL)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        Error *= _setNumeric(_locale->handle, _locale->numeric);
        if (Error != 0)
            Error *= _addCategoryName(_locale, "LC_NUMERIC");
    }

    if ((Category & LC_COLLATE) == LC_COLLATE)
    {
        if ((_locale->collate = (LPWIN32COLLATE) malloc(sizeof(WIN32COLLATE))) == NULL)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        Error *= _setCollate(_locale->handle, _locale->collate);
        if (Error != 0)
            Error *= _addCategoryName(_locale, "LC_COLLATE");
    }

    if ((Category & LC_CTYPE) == LC_CTYPE)
    {
        if ((_locale->ctype = (LPWIN32CTYPE) malloc(sizeof(WIN32CTYPE))) == NULL)
        {
            SetLastError(ERROR_OUTOFMEMORY);
            return NULL;
        }
        Error *= _setCType(_locale->handle, _locale->codepage, _locale->ctype);
        if (Error != 0)
            Error *= _addCategoryName(_locale, "LC_CTYPE");
    }
    return Error;
}

/*
  clean the categories we're going to use
*/

void _cleanCategories(LPWIN32LOCALE _locale)
{
    if (_locale->monetary != NULL && _locale->monetary != &CMonetary )
    {
        free(_locale->monetary->Decimal);
        free(_locale->monetary->ThousandSeparator);
        free(_locale->monetary->Symbol);
        free(_locale->monetary->IntlSymbol);
        free(_locale->monetary->Grouping);
        free(_locale->monetary->PositiveSign);
        free(_locale->monetary->NegativeSign);
        free(_locale->monetary->NegativeFormatString);
        free(_locale->monetary);
        _locale->monetary = NULL;
    }

    if (_locale->time != NULL && _locale->time != &CTimeDate)
    {
        free(_locale->time->DateSeparator);
        free(_locale->time->TimeSeparator);
        free(_locale->time->TimeFormat);
        free(_locale->time->ShortFormat);
        free(_locale->time->LongFormat);
        free(_locale->time->AM);
        free(_locale->time->PM);
        free(_locale->time->DayName1);
        free(_locale->time->DayName2);
        free(_locale->time->DayName3);
        free(_locale->time->DayName4);
        free(_locale->time->DayName5);
        free(_locale->time->DayName6);
        free(_locale->time->DayName7);
        free(_locale->time->AbrvDayName1);
        free(_locale->time->AbrvDayName2);
        free(_locale->time->AbrvDayName3);
        free(_locale->time->AbrvDayName4);
        free(_locale->time->AbrvDayName5);
        free(_locale->time->AbrvDayName6);
        free(_locale->time->AbrvDayName7);
        free(_locale->time->MonthName1);
        free(_locale->time->MonthName2);
        free(_locale->time->MonthName3);
        free(_locale->time->MonthName4);
        free(_locale->time->MonthName5);
        free(_locale->time->MonthName6);
        free(_locale->time->MonthName7);
        free(_locale->time->MonthName8);
        free(_locale->time->MonthName9);
        free(_locale->time->MonthName10);
        free(_locale->time->MonthName11);
        free(_locale->time->MonthName12);
        free(_locale->time->AbrvMonthName1);
        free(_locale->time->AbrvMonthName2);
        free(_locale->time->AbrvMonthName3);
        free(_locale->time->AbrvMonthName4);
        free(_locale->time->AbrvMonthName5);
        free(_locale->time->AbrvMonthName6);
        free(_locale->time->AbrvMonthName7);
        free(_locale->time->AbrvMonthName8);
        free(_locale->time->AbrvMonthName9);
        free(_locale->time->AbrvMonthName10);
        free(_locale->time->AbrvMonthName11);
        free(_locale->time->AbrvMonthName12);
        free(_locale->time);
        _locale->time = NULL;
    }

    if (_locale->numeric != NULL && _locale->numeric != &CNumeric)
    {
        free(_locale->numeric->Decimal);
        free(_locale->numeric->ThousandSeparator);
        free(_locale->numeric->Grouping);
        free(_locale->numeric->PositiveSign);
        free(_locale->numeric->NegativeSign);
        free(_locale->numeric);
        _locale->numeric = NULL;
    }

    if (_locale->collate)
    {
        free(_locale->collate);
        _locale->collate = NULL;
    }

    if (_locale->ctype)
    {
        free(_locale->ctype);
        _locale->ctype = NULL;
    }
}

LPSTR _setLocaleFromString(LPWIN32LOCALE _locale, LPCSTR LocaleName)
{
    char* p = (LPSTR) LocaleName;
    char  token[256];
    char  locale[256];
    int   tokenp;
    SHORT Category = 0;

    _lock_locale();

    memset(token, 0, sizeof(token));
    tokenp = 0;
    while (*p) {
        if (*p == '=')
        {
            if (strcmp(token, "LC_CTYPE") == 0)
                Category |= LC_CTYPE;
            if (strcmp(token, "LC_TIME") == 0)
                Category |= LC_TIME;
            if (strcmp(token, "LC_NUMERIC") == 0)
                Category |= LC_NUMERIC;
            if (strcmp(token, "LC_MONETARY") == 0)
                Category |= LC_MONETARY;
            if (strcmp(token, "LC_COLLATE") == 0)
                Category |= LC_COLLATE;
            memset(token, 0, sizeof(token));
            tokenp = 0;
        }
        else
            if (*p == '\n')
            {
                strcpy(locale, token);
                memset(token, 0, sizeof(token));
                tokenp = 0;
            }
            else
                token[tokenp++] = *p;
        p++;
    }
    _locale->handle = _getLocale(_locale, locale);

    if (!IsValidLocale(_locale->handle, LCID_INSTALLED) && !_locale->isCLocale)
    {
        SetLastError(ERROR_LOCALE_NOTINSTALLED);
        _unlock_locale();
        return NULL;
    }

    /*
      SetThreadLocale will only work for NT but it's better to do it in case the application
      uses OLE2 or some other functionnality requiring a Locale.
      */
    SetThreadLocale(__locale->handle);

    _cleanCategories(__locale);
    if (_setNewCategories(__locale, Category) == 0)
    {
        SetLastError(ERROR_CATEGORY_INVALID);
        _unlock_locale();
        return NULL;
    }

    _unlock_locale();
    return __locale->setLocaleReturn;
}

/*
  Add the category to the string
*/
int _addCategoryName(LPWIN32LOCALE _locale, LPSTR category)
{
    char LocaleName[512];

    GetLocaleInfoA(_locale->handle, LOCALE_SENGLANGUAGE, LocaleName, 512);
    strcat(LocaleName, "_");
    GetLocaleInfoA(_locale->handle, LOCALE_SENGCOUNTRY,
        &LocaleName[strlen(LocaleName)], 512-strlen(LocaleName));
    strcat(LocaleName, ".");
    ltoa(_locale->codepage, &LocaleName[strlen(LocaleName)], 10);
    if (_locale->setLocaleReturn == NULL)
    {
        _locale->setLocaleReturn = (char*) malloc(strlen(category) + strlen(LocaleName) + 3);
        if (_locale->setLocaleReturn == NULL)
            return 0;
        memset(_locale->setLocaleReturn, 0, strlen(category) +
        strlen(LocaleName) + 3);
    }
    else
    {
        _locale->setLocaleReturn = realloc(_locale->setLocaleReturn,
                                           strlen(_locale->setLocaleReturn) +
                                           strlen(category) +
                                           strlen(LocaleName) + 3);
        if (_locale->setLocaleReturn == NULL)
          return 0;
    }
    strcat(_locale->setLocaleReturn, category);
    strcat(_locale->setLocaleReturn, "=");
    strcat(_locale->setLocaleReturn, LocaleName);
    strcat(_locale->setLocaleReturn, "\n");
    return 1;
}

