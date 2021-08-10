# IMPORT.MAK - build the WINDOWS 3.1 import library.

LIBDIR = ..\lib
LIBFILE = $(LIBDIR)\import.lib


all : $(LIBFILE)

!include "..\rules.mak"

.def.lib:
        implib -i -o $&.lib $&.def

IMPLIBS = \
        commdlg.def \
        ddeml.def \
        gdi.def \
        kernel.def \
        keyboard.def \
        lzexpand.def \
        mmsystem.def \
        olecli.def \
        olesvr.def \
        penwin.def \
        shell.def \
        sound.def  \
        stress.def \
        toolhelp.def \
        user.def \
        ver.def \
        win87em.def \
        winmem32.def

$(LIBFILE) : $(IMPLIBS:.def=.lib)
    if exist $< del $<
    makersp "+!s &\n" &&|
    $(IMPLIBS:.def=.lib)
    $(OBJDIR)\profc.obj
|   > $&.rsp
    $(TLIB) $< @$&.rsp, nul
    del $&.rsp
