windll: bc40rtl.dll

.PATH.exe = ..\lib
.PATH.obj = d

OBJECTS =        \
    instdata.obj \
    rtldata.obj  \
    rtlmain.obj

OPTIONS = -WDE -ml -1 -D_RTLDLL -lC -ls -c-

bc40rtl.dll : $(OBJECTS)
    copy bcrtl.def $(.PATH.exe)\bc40rtl.def
    cd $(.PATH.obj)
    $(TC) @&&!
    $(OPTIONS) -e..\$(.PATH.exe)\bc40rtl.dll -L..\..\lib
    $(OBJECTS)
!   @..\dllmak.rsp ..\$(.PATH.exe)\crtldll.lib
    cd ..\..\lib
    implib temp.lib bc40rtl.dll
    brc ..\winlib\version -i..\winlib bc40rtl.dll
    $(TLIB) crtldll.lib +temp.lib
    del temp.lib
    del crtldll.bak
    del bc40rtl.def
    cd ..\winlib
    del *.rsp

.cpp.obj:
    $(TC) $(OPTIONS) -n$(.PATH.obj) -c {$< }

.c.obj:
    $(TC) $(OPTIONS) -n$(.PATH.obj) -c {$< }

.asm.obj :
    $(TASM) -D__l__ $< , $(.PATH.obj)\\
