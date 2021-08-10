# CLIB.MAK
#
# To compile all changed modules and replace (or add) both old and new objects
# in an existing (or new) library, type
#
#       MAKE all
#
# To clean up (i.e., delete) all object files and temporary files, type
#
#       MAKE -DTARGET clean
#
# The memory model must be specified in one of two ways.  You can
# set the environment variable MODEL before running MAKE:
#
#       SET MODEL=x
#
# or you can use the -D command line switch:
#
#       MAKE -DMODEL=x
#
# where x is the letter s, c, m, l, or h.  Using -D overrides the
# environment variable.
#
# To make a library for Windows, use -DWINDOWS on the command line.
# To make a DLL for Windows, use -DWINDLL.
# To make an import library for Windows, use -DIMPORT.

!if $d(WINDLL)
MODEL = l
!endif

!if !$d(MODEL)
!error MODEL not defined. Use -DMODEL=x on command line, or SET MODEL=x.
!endif

!if '$(MODEL)'=='h' && $d(WINDOWS)

all :
        echo Can't make a huge model WINDOWS library

clean :
        echo Can't clean up a huge model WINDOWS library

!else

# ALL - compile changed sources and add all objects (old and new) to library

all :   compile archive

!if $d(WINDOWS)

LIBNAME = cw$(MODEL)
OBJDIR  = w$(MODEL)
TC      = $(TC) +..\winlib\turboc.cfg
TASM    = $(TASM) -D_Windows -D_WINDOWS -o
OBJECTS = lib1 lib2 lib3 lib5 lib7

!elif $d(WINDLL)

LIBNAME = crtldll
OBJDIR  = ..\winlib\d
TC      = $(TC) +..\winlib\tcdll.cfg
TASM    = $(TASM) -D_Windows -D_WINDOWS -D_BUILDRTLDLL -o
OBJECTS = lib1 lib2 lib3 lib5 lib7

!else

LIBNAME = c$(MODEL)
OBJECTS = lib1 lib2 lib3 lib4 lib5 lib6 lib7

!endif

!include "..\rules.mak"

!include "clibobj.mak"

lib1 : $(OBJS1)
lib2 : $(OBJS2)
lib3 : $(OBJS3)
lib4 : $(OBJS4)
lib5 : $(OBJS5)
lib6 : $(OBJS6)
lib7 : $(OBJS7)

!if $d(WINDOWS) || $d(WINDLL)

EXCPTBUILD = $(TC) -m$(CMODEL) -WDE -n$(OBJDIR) $?

!if '$(MODEL)'=='c' || '$(MODEL)'=='l'
append1.obj:  append1.cpp
        $(EXCPTBUILD)
append2.obj:  append2.cpp
        $(EXCPTBUILD)
append3.obj:  append3.cpp
        $(EXCPTBUILD)
assign.obj:   assign.cpp
        $(EXCPTBUILD)
clone.obj:    clone.cpp
        $(EXCPTBUILD)
compare1.obj: compare1.cpp
        $(EXCPTBUILD)
compare2.obj: compare2.cpp
        $(EXCPTBUILD)
copy1.obj:    copy1.cpp
        $(EXCPTBUILD)
copy2.obj:    copy2.cpp
        $(EXCPTBUILD)
copy3.obj:    copy3.cpp
        $(EXCPTBUILD)
ctor1.obj:    ctor1.cpp
        $(EXCPTBUILD)
ctor2.obj:    ctor2.cpp
        $(EXCPTBUILD)
ctor3.obj:    ctor3.cpp
        $(EXCPTBUILD)
ctor4.obj:    ctor4.cpp
        $(EXCPTBUILD)
ctor5.obj:    ctor5.cpp
        $(EXCPTBUILD)
ctor6.obj:    ctor6.cpp
        $(EXCPTBUILD)
ctor7.obj:    ctor7.cpp
        $(EXCPTBUILD)
find1.obj:    find1.cpp
        $(EXCPTBUILD)
find2.obj:    find2.cpp
        $(EXCPTBUILD)
find3.obj:    find3.cpp
        $(EXCPTBUILD)
find4.obj:    find4.cpp
        $(EXCPTBUILD)
fndfrst.obj:  fndfrst.cpp
        $(EXCPTBUILD)
fndfrstn.obj: fndfrstn.cpp
        $(EXCPTBUILD)
fndlast.obj:  fndlast.cpp
        $(EXCPTBUILD)
fndlastn.obj: fndlastn.cpp
        $(EXCPTBUILD)
hash.obj:     hash.cpp
        $(EXCPTBUILD)
insert1.obj:  insert1.cpp
        $(EXCPTBUILD)
insert2.obj:  insert2.cpp
        $(EXCPTBUILD)
oprasgn1.obj: oprasgn1.cpp
        $(EXCPTBUILD)
oprasgn2.obj: oprasgn2.cpp
        $(EXCPTBUILD)
oprasgn3.obj: oprasgn3.cpp
        $(EXCPTBUILD)
oprcall1.obj: oprcall1.cpp
        $(EXCPTBUILD)
oprcall2.obj: oprcall2.cpp
        $(EXCPTBUILD)
oprcall3.obj: oprcall3.cpp
        $(EXCPTBUILD)
oprcall4.obj: oprcall4.cpp
        $(EXCPTBUILD)
opreql.obj:   opreql.cpp
        $(EXCPTBUILD)
oprplus.obj:  oprplus.cpp
        $(EXCPTBUILD)
prepend.obj:  prepend.cpp
        $(EXCPTBUILD)
regexp.obj: regexp.cpp
        $(EXCPTBUILD)
stremove.obj: stremove.cpp
        $(EXCPTBUILD)
replace.obj:  replace.cpp
        $(EXCPTBUILD)
reserve.obj:  reserve.cpp
        $(EXCPTBUILD)
resize.obj:   resize.cpp
        $(EXCPTBUILD)
rfind.obj:    rfind.cpp
        $(EXCPTBUILD)
status.obj:   status.cpp
        $(EXCPTBUILD)
strings.obj:  strings.cpp
        $(EXCPTBUILD)
strip.obj:    strip.cpp
        $(EXCPTBUILD)
substr1.obj:  substr1.cpp
        $(EXCPTBUILD)
substr2.obj:  substr2.cpp
        $(EXCPTBUILD)
uprlwr.obj:   uprlwr.cpp
        $(EXCPTBUILD)
stringio.obj: stringio.cpp
        $(EXCPTBUILD)
xalloc.obj: xalloc.cpp
        $(EXCPTBUILD)
xmsg.obj: xmsg.cpp
        $(EXCPTBUILD)
!endif

!endif

# gregistr.obj cannot be built in tiny model.

!if '$(MODEL)'=='s' && !$d(WINDOWS) && !$d(WINDLL)
gregistr.obj: gregistr.c
        $(TC) -ms -n$(OBJDIR) $?
!endif

# ARCHIVE - add all objects to a new library.

!if $d(WINDLL)

archive :
        makersp "!s\n" &&|
        $(OBJS5)
        $(OBJS7)
|       >> ..\winlib\dllmak.rsp
        makersp "+!s &\n" &&|
        $(OBJS1)
        $(OBJS2)
        $(OBJS3)
|       > clibmak.rsp
        if exist $(LIBDIR)\$(LIBNAME).lib del $(LIBDIR)\$(LIBNAME).lib
        cd ..\winlib\d
        $(TLIB) ..\$(LIBDIR)\$(LIBNAME) /C @..\..\clib\clibmak.rsp,nul
        if exist ..\$(LIBDIR)\*.bak del ..\$(LIBDIR)\*.bak
        cd ..\..\clib
        del *.rsp

!elif $d(WINDOWS)

archive :
        if exist $(LIBDIR)\$(LIBNAME).lib del $(LIBDIR)\$(LIBNAME).lib
        makersp "+$(OBJDIR)\\\\!s &\n" &&|
        $(OBJS1)
        $(OBJS2)
        $(OBJS3)
        $(OBJS5)
        $(OBJS7)
|       > clibmak.rsp
        $(TLIB) $(LIBDIR)\$(LIBNAME) /C @clibmak.rsp,nul
        if exist $(LIBDIR)\*.bak del $(LIBDIR)\*.bak
        del *.rsp

!else

archive :
        if exist $(LIBDIR)\$(LIBNAME).lib del $(LIBDIR)\$(LIBNAME).lib
        makersp "+$(OBJDIR)\\\\!s &\n" &&|
        $(OBJS1)
        $(OBJS2)
        $(OBJS3)
        $(OBJS4)
        $(OBJS5)
        $(OBJS6)
        $(OBJS7)
|       > clibmak.rsp
        $(TLIB) $(LIBDIR)\$(LIBNAME) /C @clibmak.rsp,nul
        if exist $(LIBDIR)\*.bak del $(LIBDIR)\*.bak
        del *.rsp

!endif          # if $d(WINDLL)

!endif          # if huge model WINDOWS
