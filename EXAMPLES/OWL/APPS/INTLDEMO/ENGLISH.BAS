//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1996 by Borland International
//   english.bas
//----------------------------------------------------------------------------

Function IntlDemo()
    Set MyObject = CreateObject("Locale.Application")
    Set MainWindow = MyObject.Window
    MainWindow.CLocale
    MainWindow.USLocale
    MainWindow.UKLocale
    MainWindow.FrenchLocale
    MainWindow.GermanLocale
    MainWindow.EnglishLanguage
    MainWindow.FrenchLanguage
    MainWindow.GermanLanguage
    Set ClientWindow = MainWindow.Window
    ClientWindow.IsAlnum
    ClientWindow.IsAlpha
    ClientWindow.IsAscii
    ClientWindow.IsCntrl
    ClientWindow.IsDigit
    ClientWindow.IsGraph
    ClientWindow.IsLower
    ClientWindow.IsPrint
    ClientWindow.IsPunct
    ClientWindow.IsSpace
    ClientWindow.IsUpper
    ClientWindow.IsXDigit
    MyObject.Quit
End Function
