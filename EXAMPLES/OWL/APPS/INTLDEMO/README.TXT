Copyright Borland International
ObjectWindows (C) 1996

Title: International API Demo

===========================================================================
International API
===========================================================================


                    Borland C++ provides support for international program
                    development. Currently, support is provided for the
                    Great Britain and United States English, French, and
                    German locales. Future releases of Borland C++ will
                    increase the number of locales supported.

    The LOCALE.BLL  Support for these locales is contained in the
 file is installed  LOCALE.BLL library. By default, the "C" locale is in
       in BC5\BIN   effect. However, a call to setlocale dynamically links
        directory.  the LOCALE.BLL library to your program. A locale-
                    specific module is enabled by a call to setlocale. The
                    call will also specify which character set to use with
                    the locale. (Character set is sometimes referred to as
                    "code page" or "code set.") You can query the locale
                    settings by using localeconv and setlocale functions.
                    See the Library Reference, Chapter 3, for a description
                    of these functions.

                    If the call to setlocale can be resolved, several
                    character-handling functions change their behavior.
                    Because Borland C++ 5.0 international API currently
                    supports only 8-bit characters (thereby enabling
                    recognition of as many as 256 characters), only
                    single-byte character-handling functions are affected.
                    The list of affected functions is in the Library
                    Reference, Chapter 1.

                    In your code, you must #define _ _USELOCALES_ _to have
                    the locale-sensitive functions available. Otherwise,
                    only the "C" locale macros will be used.


 The international  =======================================================
API sample program
                    To illustrate the effects of selecting different
                    locales, Borland C++ provides a sample program. The
                    sample program (named INTLDEMO.EXE) is an ObjectWindows
                    application. All source code and a project file for the
                    sample are provided. The sample program INTLDEMO (in
                    BC5\EXAMPLES\OWL\APPS\INTLDEMO) demonstrates how the
                    setlocale function can produce an "internationally
                    aware" Windows application. You can switch the inter-
                    face language at run time between English, French, and
                    German.


                                                                          1


                    INTLDEMO displays all of the Windows ANSI character set
                    (also referred to as the WIN 1252 character set) in a
                    16-by-16 character grid. A number of characters are
                    highlighted according to the selections under the
                    "Locale" and the "Classification" menus. When you
                    execute INTLDEMO, the screen shows the default "C"
                    locale, and the default classification is isalpha. The
                    highlighted characters are therefore the characters A
                    to Z  and a to z. By selecting another locale (for
                    example, French) the accented versions of the
                    characters (for example ‚) are also highlighted.
                    Various combinations of locale and classification can
                    be illustrated by selecting the appropriate menu items.

                    The results of calling the localeconv function for the
                    current locale are illustrated by selecting
                    "Conventions|Show". For example, with the French locale
                    selected, the international currency symbol becomes FRF
                    and the currency symbol becomes F. Note that this
                    window can remain open while either the language or
                    locale is changed and the values are updated
                    accordingly.

                    The "File|List" menu produces a dialog box that
                    demonstrates the effects of the locale on collation
                    sequences and on date and time functions. The files in
                    the current directory are shown sorted according to the
                    current locale, and with date and times displayed
                    according to the conventions and in the language of the
                    selected locale. File names can be switched between
                    upper/lower case to demonstrate the effects of the
                    toupper and tolower functions in the current locale.
                    The dialog also illustrates the effects of the
                    BWCCIntlInit function on the Ok, Cancel and Help
                    buttons of the dialog. Any file can be selected to be
                    viewed and its contents similarly sorted according to
                    the current locale collation sequence.

                    The "Language" menu allows the language of the UI to be
                    changed "on the fly." This feature uses ObjectWindow's
                    ability to associate windows interface elements to a
                    module, in this case a .DLL that contains the resources
                    in a particular language. When the language is changed,
                    a new language .DLL is loaded and the interface
                    elements are reloaded from that .DLL. Note that the
                    date and times in the File List dialog are not affected
                    by the change in language, but by the choice of locale.

                    The 'Classification' menu shows a list of the locale-
                    sensitive isxxx() functions. Selecting one of these
                    items will cause the characters that return true for
                    this function in the current locale to be highlighted
                    in the main window.


                    INTLDEMO also supports multi-lingual OLE automation. 
                    Commands are exposed which allow a controller to select
                      1. the locale, 
                      2. the language of the UI, 
                      3. the classification function. 

                    These commands are available in English, French and 
                    German. A controller program, CALLDEMO, is provided, 
                    which illustrates this process.

                    By default, the type library will be generated according
                    to the current Control Panel settings. For example,
                    running INTLDEMO with the -Typelib switch under French
                    settings will generate intldemo.olb in French.

                    To generate the type library in a given language, use
                    the -Language switch. For example,
                      intldemo.exe -Language=7 -Typelib=german.olb
                    will generate a German type library called german.olb.

                    Some localized BASIC scripts are also provided. These 
                    scripts can be run from a VBA apllication, such as Excel.
                    In order to run the French or German scripts in the US 
                    version of Excel, it is necessary to load the appropriate
                    localized object libraries. This process is fully 
                    explained	in the description of the AUTOCALC example 
                    program.

                    In addition, Excel can be used to browse the type library 
                    information. For example, browsing the German version of
                    the type library displays localized names of methods and 
                    properties, as well as brief descriptions. Localized 
                    help text can also be invoked.

 

