Copyright Borland International
ObjectWindows (C) 1995

Title: SPLASH Example

Keywords: TDib;TDibWindow;TSplashWindow

The SPLASH example illustrates how to create a splash screen. There are
several styles that can be used with TSplashWindow: None, ShrinkToFit,
MakeGauge, MakeStatic, and CaptureMouse. They can be used in any
combination. TSplashWindow's constructor also has a timeout parameter
which signifies the number of milliseconds to display the splash
window.


The ShrinkToFit refers to shrinking the splash window to fit around the
dib. It this style is on, the width and height parameters to the
constructor of TSplashWindow is ignored.

