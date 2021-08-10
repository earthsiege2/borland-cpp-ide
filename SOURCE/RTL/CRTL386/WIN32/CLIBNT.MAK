# Sub-makefile for Windows NT run-time library for BC++.
# Included by MAKEFILE when -DCLIBNT is specified.

OBJ1 = \
__access.obj \
__close.obj \
__dup.obj \
__dup2.obj \
__ftrunc.obj \
__isatty.obj \
__lseek.obj \
__open.obj \
__unlink.obj \
_alloca.obj \
_chmod.obj \
_close.obj \
_cwait.obj \
_getpid.obj \
_open.obj \
_pipe.obj \
_read.obj \
_stkavl.obj \
_wherexy.obj \
_write.obj \
chdir.obj \
chdrive.obj \
chmod.obj \
clock.obj \
clreol.obj \
clrscr.obj \
crtinit.obj \
cursor.obj \
direct.obj \
dosclose.obj \
doscreat.obj \
dosdfree.obj \
dosfattr.obj \
dosfind.obj \
dosgdate.obj \
dosgdriv.obj \
dosgftim.obj \
dosopen.obj \
dosread.obj \
dossdate.obj \
dossftim.obj \
doswrite.obj \
errormsg.obj \
flength.obj \
fstat.obj \
ftime.obj \
fullpath.obj \
getch.obj \
getche.obj \
getcurdi.obj \
getdate.obj \
getdcwd.obj \
getdfree.obj \
getdisk.obj \
gp.obj \
handles.obj \
initstk.obj \
ioerror.obj \
kbhit.obj \
loadprog.obj \
lock.obj \
locking.obj \
mkdir.obj \
movecurs.obj \
movetext.obj \
oshandle.obj \
platform.obj \
rename.obj \
rmdir.obj \
scroll.obj \
setdate.obj \
setenv.obj \
setenvp.obj \
setexc.obj \
setjmp.obj \
signal.obj \
sleep.obj \
stat.obj \
statcvt.obj \
stime.obj \
strdate.obj \
system.obj \
time.obj \
tls.obj \
utime.obj \
version.obj \
virtmem.obj \
vram.obj \
wstrings.obj

!ifdef MT
OBJ2 = \
_lock.obj \
thrddata.obj \
thread.obj \
threadid.obj
!endif

# IMPOBJ lists objects that must be statically linked, and are placed
# in the import library.

IMPOBJ   = \
         libmain.obj

IMPONLY = \
         initstk.obj


# Unimplemented objects

UNIMP = \
country.obj \
dllmain.obj


OBJ3 = $(IMPOBJ)

# Objects that must be built but are not part of the libary.

!ifndef MT
MISCOBJ = $(LIB)\c0x32.obj $(LIB)\c0w32.obj $(LIB)\gp.obj $(LIB)\c0d32.obj

$(LIB)\c0x32.obj : c0nt.obj
   copy $(OBJ)\c0nt.obj $<

$(LIB)\c0w32.obj : c0ntw.obj
   copy $(OBJ)\c0ntw.obj $<

$(LIB)\c0d32.obj : c0ntd.obj
   copy $(OBJ)\c0ntd.obj $<

$(LIB)\gp.obj : gp.obj
   copy $(OBJ)\gp.obj $(LIB)
!endif

# NT import libraries

.def.fst:
    implib -i -n $&.lib $&.def
    -fastlib $&.lib $&.fst
    del $&.lib

IMPLIBS = $(LIB)\import32.lib

CONLIBS = \
        advapi32.def \
        dlcapi.def \
        kernel32.def \
        lz32.def \
        mgmtapi.def \
        mpr.def \
        netapi32.def \
        nddeapi.def \
        ntdll.def \
        rasapi32.def \
        rpcns4.def \
        rpcrt4.def \
        vdmdbg.def \
        version.def \
        winstrm.def \
        wsock32.def \
        winspool.def

GUILIBS = \
        comctl32.def \
        comdlg32.def \
        gdi32.def \
        olecli32.def \
        olesvr32.def \
        shell32.def \
        user32.def \
        winmm.def

$(LIB)\import32.lib : $(CONLIBS:.def=.fst) $(GUILIBS:.def=.fst)
    if exist $< del $<
    makersp "+!s &\n" &&|
   $(CONLIBS:.def=.fst)
   $(GUILIBS:.def=.fst)
|   > $&.rsp
    tlib $< @$&.rsp, nul

# If building the DLL, append to the linker response file containing
# the objects that will be placed in the DLL.  This file was started in
# CLIB.MAK.  Similarly, append to import.rsp the files that must be
# added to the import library.

!if $d(DLL)
DLLRSP = dllrsp importrsp

dllrsp :
   makersp "$(OBJ)\\\\!s+\n" &&|
   $(OBJ1)
   $(OBJ2)
   $(IMPOBJ)
|  >> dll.rsp

importrsp :
   makersp "+$(OBJ)\\\\!s &\n" &&|
   $(IMPOBJ)
   $(IMPONLY)
|  >> import.rsp

!endif

# Multiple dummy targets are used to get around MAKE's annoying
# limit on line length.

lib1 : $(OBJ1)
lib  : lib1 $(OBJ2) $(MISCOBJ) $(IMPLIBS) $(DLLRSP) $(IMPOBJ) $(IMPONLY)
miscobj : $(MISCOBJ) $(IMPLIBS)

# Dependencies not covered by default rules.

c0ntw.obj    : $(SRC)\c0nt.asm
c0ntd.obj    : $(SRC)\c0nt.asm
