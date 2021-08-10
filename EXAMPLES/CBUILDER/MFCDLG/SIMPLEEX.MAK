# ---------------------------------------------------------------------------
VERSION = BCB.01
# ---------------------------------------------------------------------------
!ifndef BCB
BCB = $(MAKEDIR)\..
!endif
# ---------------------------------------------------------------------------
PROJECT = SimpleEx.exe
OBJFILES = SimpleEx.obj SimpleCB.obj
RESFILES = SimpleEx.res
RESDEPEN = $(RESFILES) SimpleCB.dfm
LIBFILES = 
# ---------------------------------------------------------------------------
CFLAG1 = -Od -Hc -w -k -r- -y -v -vi- -c -a4 -b- -w-par -w-inl -Vx -Ve -x -WE 
CFLAG2 = -Ic:\PROGRA~1\borland\cbuilder\include;c:\PROGRA~1\borland\cbuilder\include\vcl \
   -H=$(BCB)\lib\vcld.csm 
PFLAGS = -Uc:\PROGRA~1\borland\cbuilder\lib\obj;c:\PROGRA~1\borland\cbuilder\lib \
   -Ic:\PROGRA~1\borland\cbuilder\include;c:\PROGRA~1\borland\cbuilder\include\vcl \
   -AWinTypes=Windows;WinProcs=Windows;DbiTypes=BDE;DbiProcs=BDE;DbiErrs=BDE -v \
   -$Y -$W -$O- -JPHNV -M     
RFLAGS = -ic:\PROGRA~1\borland\cbuilder\include;c:\PROGRA~1\borland\cbuilder\include\vcl 
LFLAGS = -Lc:\PROGRA~1\borland\cbuilder\lib\obj;c:\PROGRA~1\borland\cbuilder\lib \
   -aa -Tpe -x -v -V4.0 
IFLAGS = 
LINKER = ilink32
# ---------------------------------------------------------------------------
ALLOBJ = c0w32.obj $(OBJFILES)
ALLRES = $(RESFILES)
ALLLIB = $(LIBFILES) vcl.lib import32.lib cp32mt.lib 
# ---------------------------------------------------------------------------
.autodepend

$(PROJECT): $(OBJFILES) $(RESDEPEN)
    $(BCB)\BIN\$(LINKER) @&&!
    $(LFLAGS) +
    $(ALLOBJ), +
    $(PROJECT),, +
    $(ALLLIB),, +
    $(ALLRES) 
!

.pas.hpp:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.pas.obj:
    $(BCB)\BIN\dcc32 $(PFLAGS) { $** }

.cpp.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $* 

.c.obj:
    $(BCB)\BIN\bcc32 $(CFLAG1) $(CFLAG2) -o$* $**

.rc.res:
    $(BCB)\BIN\brcc32 $(RFLAGS) $<
#-----------------------------------------------------------------------------
