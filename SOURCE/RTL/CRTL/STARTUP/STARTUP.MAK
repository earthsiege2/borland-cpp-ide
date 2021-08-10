# STARTUP.MAK - makefile for startup code
#
# To build DOS startups, type
#	make -fstartup clib
#
# To build WINDOWS startups, type
#	make -fstartup winlib
#
# To make both sets of startups, type
#	make -fstartup all
#
# The default object file directory is ..\lib.  If you want to change
# this, add the following option to the MAKE command line:
#	-DOBJDIR=dir
# where dir is the directory name (without a terminating slash).

!if !$d(OBJDIR)
OBJDIR = ..\lib
!endif

TASM = $(TASM) -m -mx -q -t

all : clib winlib

clib : $(OBJDIR)\c0t.obj $(OBJDIR)\c0s.obj $(OBJDIR)\c0c.obj \
       $(OBJDIR)\c0m.obj $(OBJDIR)\c0l.obj $(OBJDIR)\c0h.obj \
       $(OBJDIR)\c0ft.obj $(OBJDIR)\c0fs.obj $(OBJDIR)\c0fc.obj \
       $(OBJDIR)\c0fm.obj $(OBJDIR)\c0fl.obj $(OBJDIR)\c0fh.obj

winlib : $(OBJDIR)\c0ws.obj $(OBJDIR)\c0wc.obj \
	 $(OBJDIR)\c0wm.obj $(OBJDIR)\c0wl.obj \
         $(OBJDIR)\c0ds.obj $(OBJDIR)\c0dc.obj \
	 $(OBJDIR)\c0dm.obj $(OBJDIR)\c0dl.obj

$(OBJDIR)\c0t.obj : c0.asm
	$(TASM) -d__TINY__    c0, $<
$(OBJDIR)\c0s.obj : c0.asm
	$(TASM) -d__SMALL__   c0, $<
$(OBJDIR)\c0c.obj : c0.asm
	$(TASM) -d__COMPACT__ c0, $<
$(OBJDIR)\c0m.obj : c0.asm
	$(TASM) -d__MEDIUM__  c0, $<
$(OBJDIR)\c0l.obj : c0.asm
	$(TASM) -d__LARGE__   c0, $<
$(OBJDIR)\c0h.obj : c0.asm
	$(TASM) -d__HUGE__    c0, $<

$(OBJDIR)\c0ft.obj : c0.asm
	$(TASM) -d__TINY__    /D_DSSTACK_ c0, $<
$(OBJDIR)\c0fs.obj : c0.asm
	$(TASM) -d__SMALL__   /D_DSSTACK_ c0, $<
$(OBJDIR)\c0fc.obj : c0.asm
	$(TASM) -d__COMPACT__ /D_DSSTACK_ c0, $<
$(OBJDIR)\c0fm.obj : c0.asm
	$(TASM) -d__MEDIUM__  /D_DSSTACK_ c0, $<
$(OBJDIR)\c0fl.obj : c0.asm
	$(TASM) -d__LARGE__   /D_DSSTACK_ c0, $<
$(OBJDIR)\c0fh.obj : c0.asm
	$(TASM) -d__HUGE__                c0, $<

$(OBJDIR)\c0ws.obj : c0w.asm
	$(TASM) -d__SMALL__   -d__WINDOWS__ c0w, $<
$(OBJDIR)\c0wc.obj : c0w.asm
	$(TASM) -d__COMPACT__ -d__WINDOWS__ c0w, $<
$(OBJDIR)\c0wm.obj : c0w.asm
	$(TASM) -d__MEDIUM__  -d__WINDOWS__ c0w, $<
$(OBJDIR)\c0wl.obj : c0w.asm
	$(TASM) -d__LARGE__   -d__WINDOWS__ c0w, $<

$(OBJDIR)\c0ds.obj : c0d.asm
	$(TASM) -d__SMALL__   -d__WINDOWS__ c0d, $<
$(OBJDIR)\c0dc.obj : c0d.asm
	$(TASM) -d__COMPACT__ -d__WINDOWS__ c0d, $<
$(OBJDIR)\c0dm.obj : c0d.asm
	$(TASM) -d__MEDIUM__  -d__WINDOWS__ c0d, $<
$(OBJDIR)\c0dl.obj : c0d.asm
	$(TASM) -d__LARGE__   -d__WINDOWS__ c0d, $<

clean :
	del $(OBJDIR)\c0*.obj
