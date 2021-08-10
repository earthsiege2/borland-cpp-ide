# IOSTREAM.MAK - makefile for OS/2 2.0 IOSTREAM library for BC++.
# To compile with BCOS2, type
#       make -fiostream

# There's almost no difference between the multi-thread and single-thread
# version of iostreams, so only make one set of object files in ./bcobj

OBJ = bcobj

!include "..\rules.mak"

# List of object files.  The list is split into sections to 
# get around MAKE's annoying limit on rule length.

OBJ1 = \
fsattch.obj \
fsbattch.obj \
fsbclose.obj \
fsbctr1.obj \
fsbctr2.obj \
fsbctr3.obj \
fsbdtr.obj \
fsboflow.obj \
fsbopen.obj \
fsbsbuf.obj \
fsbskoff.obj \
fsbsync.obj \
fsbuflow.obj \
fsclose.obj \
fsctr1.obj \
fsctr2.obj \
fsctr3.obj \
fsctr4.obj \
fsdtr.obj \
fsopen.obj \
fssbuf.obj \
ifsctr1.obj \
ifsctr2.obj \
ifsctr3.obj \
ifsctr4.obj \
ifsdtr.obj \
iofsctr1.obj \
iofsctr2.obj \
iofsctr3.obj \
iofsctr4.obj \
iofsdtr.obj \
iosrctr1.obj \
iosrctr2.obj \
iosrdtr.obj \
iostasn1.obj \
iostasn2.obj \
iostctr1.obj \
iostctr2.obj \
iostctr3.obj \
iostdtr1.obj \
iostdtr2.obj \
ioststd.obj \
isrctr1.obj \
isrctr2.obj \
isrdtr.obj \
istasn1.obj \
istasn2.obj \
istctr1.obj \
istctr2.obj \
istctr3.obj \
istctr4.obj \
istdget.obj \
istdipfx.obj \
istdtr1.obj \
istdtr2.obj \
isteatwh.obj \
istebuf.obj \
istechp.obj \
istedbl.obj \
isteint.obj \
istelng.obj \
isteschr.obj \
istesh.obj \
isteuchr.obj \
isteuint.obj \
isteulng.obj \
isteush.obj \
istgbuf.obj \
istget.obj \
istgline.obj \
istgschr.obj \
istgstr.obj \
istguchr.obj \
istign.obj \
istmanip.obj \
istpback.obj \
istread.obj \
istskoff.obj \
istskpos.obj \
isttellg.obj \
istws.obj \
istx.obj \
mnrstflg.obj \
mnsbase.obj \
mnsetflg.obj \
mnsetw.obj \
mnsfill.obj \
mnsprec.obj \
ofsctr1.obj \
ofsctr2.obj \
ofsctr3.obj \
ofsctr4.obj \
ofsdtr.obj

OBJ2 = \
osrctr1.obj \
osrctr2.obj \
osrdtr.obj \
ostasn1.obj \
ostasn2.obj \
ostctr1.obj \
ostctr2.obj \
ostctr3.obj \
ostdtr1.obj \
ostdtr2.obj \
ostendl.obj \
ostends.obj \
ostfloat.obj \
ostflush.obj \
ostibuf.obj \
ostint.obj \
ostischr.obj \
ostmanip.obj \
ostmflsh.obj \
ostopfx.obj \
ostosfx.obj \
ostoutst.obj \
ostptr.obj \
ostskoff.obj \
ostskpos.obj \
osttellp.obj \
ostwrite.obj \
ostx.obj \
sdbctr.obj \
sdbdtr.obj \
sdboflow.obj \
sdbpbfl.obj \
sdbskoff.obj \
sdbsync.obj \
sdbuflow.obj \
sdctr.obj \
sddtr.obj \
srbctr1.obj \
srbctr2.obj \
srbctr3.obj \
srbctr4.obj \
srbctr5.obj \
srbdalc.obj \
srbdtr.obj \
srbfreez.obj \
srbinit.obj \
srboflow.obj \
srbsbuf.obj \
srbskoff.obj \
srbstr.obj \
srbsync.obj \
srbuflow.obj \
srctr1.obj \
srctr2.obj \
srdtr.obj \
stbalc.obj \
stbctr1.obj \
stbctr2.obj \
stbdbp.obj \
stbdnext.obj \
stbdsgtn.obj \
stbdsptn.obj \
stbdtr.obj \
stboflow.obj \
stbpbfl.obj \
stbsbuf.obj \
stbsetb.obj \
stbsetg.obj \
stbsetp.obj \
stbsgetn.obj \
stbskoff.obj \
stbskpos.obj \
stbsputn.obj \
stbstb1.obj \
stbsync.obj \
stbtalc.obj \
stbuflow.obj \
stclear.obj \
stctr1.obj \
stctr2.obj \
stdec.obj \
stdtr.obj \
stflags.obj \
sthex.obj \
stinit.obj \
stiword.obj \
stlock.obj \
stoct.obj \
stpword.obj \
stsetf1.obj \
stsetf2.obj \
stsetst.obj \
stskip.obj \
stsync.obj \
sttie.obj \
stunset.obj \
stusize.obj \
stxalc.obj

# Multi-thread object files.

!if $d(MT)
MTOBJ = isteldbm.obj istefltm.obj fsblkmt.obj
!else
MTOBJ = isteldbl.obj isteflt.obj fsblkst.obj
!endif

# Objects that cause BCOS2 to generate spurious errors.  When BCOS2 is
# fixed, these must be put back in the main list above.

BADOBJ = 

# How to build the library.

!if $d(MT)
LIBNAME = libcmt
!else
LIBNAME = libc
!endif

all : cfg $(LIB)\$(LIBNAME).lib

# Compiler configuration file

cfg :
    echo $(CFLAGS) >turboc.cfg

# Object files that make up the library

lib1 : $(OBJ1)
lib2 : $(OBJ2) $(MTOBJ)

$(LIB)\$(LIBNAME).lib : lib1 lib2 rsp
#       if exist $(LIB)\$(LIBNAME).lib del $(LIB)\(LIBNAME).lib
        lib $(LIB)\$(LIBNAME) @libcmak.rsp;
        del $(LIB)\$(LIBNAME).bak

rsp :
#       if exist make0000.$$$ rm -f make0000.$$$
#       if exist libcmak.rsp rm -f libcmak.rsp
        makersp "+$(OBJ)\\\\!s &\n" &&|
        $(OBJ1)
        $(OBJ2)
        $(MTOBJ)
|       > libcmak.rsp

# Dependencies that aren't covered by the default.

istefltm.obj : isteflt.cpp
isteldbm.obj : isteldbl.cpp
