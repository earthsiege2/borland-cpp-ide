#############################################################################
# In order to make a suite, define one or more of the following             #
#                                                                           #
#    DEBUG - Used to build a debuggable version of the RTL.                 #
#                                                                           #
#      DLL - Used to build the DLL version of the RTL.                      #
#                                                                           #
#       MT - Used to include multiple thread support.  This is only allowed #
#            for WIN32.                                                     #
#                                                                           #
# TARGET_OS- Used to indicate the OS.  The default is WIN32.  It should be  #
#            one of the following:                                          #
#              WIN32  = 32 bit Windows on 32 bit Windows (NT,Chicago,Cairo) #
#                                                                           #
#      PCH - Used to turn on precompiled headers                            #
#                                                                           #
#############################################################################

#############################################################################
# Setup some reasonable defaults.                                           #
#############################################################################
!if !$d(TARGET_OS)
    TARGET_OS=WIN32
!endif

!if $d(RTLSOURCE)
! if !$d(BCB)
     BCB = $(MAKEDIR)\..
! endif
! if !$d(RTLROOT)
     RTLROOT = $(BCB)\source\rtl
! endif
!else
! if !$d(RTLROOT)
!  if !$d(RTLHOME)
!   error RTLHOME is not defined!!!
!  else
     RTLROOT = $(RTLHOME)
!  endif
! endif
!endif
#############################################################################
# Setup some useful directories.                                            #
#############################################################################
SRCBASE   = $(RTLROOT)\source
OBJBASE   = $(RTLROOT)\obj\$(TARGET_OS)
LIBDIR    = $(RTLROOT)\lib
PSDKDIR   = $(LIBDIR)\psdk
!if $d(RTLSOURCE)
BCINCL    = $(BCB)\include;$(BCB)\include\vcl
INCLBASE  = $(RTLROOT)
!else
INCLBASE  = $(RTLROOT)\include
!endif
EXTDIR    = $(RTLROOT)\external

#############################################################################
# Guard against illegal variable combinations and obtain the operating      #
# platform specific build rules.                                            #
#############################################################################
!if "$(TARGET_OS)" != "WIN32"
!    error Unknown TARGET_OS
!endif

!include $(TARGET_OS).mak

#############################################################################
# Configure the output paths.                                               #
#############################################################################
.PATH.lib = $(LIBDIR)
.PATH.obj = $(OBJDIR)
.PATH.res = $(OBJDIR)
.PATH.fst = $(OBJDIR)

#############################################################################
# Adjust switches accordingly.                                              #
#############################################################################
!if $d(DEBUG)
    CC   = $(CC) -v -vi -D__DEBUG__
    ASM  = $(ASM) -zi /D__DEBUG__
    LINK = $(LINK) -v
!endif

#############################################################################
# Implicit source rules.                                                    #
#############################################################################
.asm.obj :
    $(ASM) $(ASMFLAGS) $*,$(OBJDIR)\;

.c.obj :
    $(CC) {$< }

.cas.obj :
    $(CC) {$< }

.cpp.obj :
    $(CC) {$< }

.c.i :
!if $d(JOHNS_CPP32)
    $(CPP) -Sr -P- -n. {$< }
!else
    $(CPP) -Sk -Ss -Sd -P -n. {$< }
!endif

.cpp.i :
!if $d(JOHNS_CPP32)
    $(CPP) -Sr -P- -n. {$< }
!else
    $(CPP) -Sk -Ss -Sd -P -n. {$< }
!endif

.def.fst:
    $(IMPLIB) $(OBJDIR)\$&.lib $&.def
    fastlib $(OBJDIR)\$&.lib $(OBJDIR)\$&.fst
    copy $(OBJDIR)\$&.fst $(PSDKDIR)\$&.lib
    del $(OBJDIR)\$&.lib

.rc.res :
    $(BRCC) @&&|
    -i$(INCLUDES) -fo$(OBJDIR)\$& $<
|

#############################################################################
# The rules for the compiler and assembler configuration files.             #
#############################################################################
CFG = rtl.cfg

$(OBJDIR)\rtl.cfg :
    copy &&|
	 $(CFLAGS)
|   $@

tasm.cfg :
    copy &&|
	 $(AFLAGS)
|   $@

delcfg :
!if $d(KEEP_TASM_CFG)
    @if exist tasm.cfg echo KEEP_TASM_CFG specified and TASM.CFG found.
!else
    if exist tasm.cfg del tasm.cfg
!endif

cfg : $(OBJDIR)\rtl.cfg

#############################################################################
# The rule for building a response file for library creation.               #
#############################################################################
librsp :
    makersp "-+$(OBJDIR:\=\\)\\!s &\n" &&|
	    $(OBJS)
|   >> $(LIBDIR)\tlib.rsp

#############################################################################
# The rule for building the static RTL.                                     #
#############################################################################
lib : librsp
    $(TLIB) $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).lib @tlib.rsp,temp.lst
# The TLIB_NO_PURGE statement is a temp. workaround for a TASM32 bug which will
# be fixed later.
    $(TLIB_NO_PURGE) $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).lib -+$(OBJDIR)\xx.obj
    $(PUBTOOL) $(EXTDIR)\$(PUBNAME) $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).lib
    if exist $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).bak del $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).bak
    del temp.lst

#############################################################################
# The rules for building response files for RTLDLL and import library       #
# creation                                                                  #
#############################################################################

#
# build the rsp file for linking the RTLDLL
#
dllrsp :
   makersp "$(OBJDIR:\=\\)\\!s+\n" &&|
   $(OBJS)
|  >> $(LIBDIR)\dll.rsp

#
# build the rsp file for CW32I and the CP32MTI version of CC32xxMT.DLL
#
importrsp :
   makersp "-+$(OBJDIR:\=\\)\\!s &\n" &&|
   $(IMPOBJS) $(IMPOBJS_P_ONLY)
|  >> $(LIBDIR)\import.rsp
#   @echo IMPOBJS = $(IMPOBJS)
#   @echo IMPOBJS_P_ONLY = $(IMPOBJS_P_ONLY)

#
# build the rsp file for the CW32MTI version of CC32xxMT.DLL
#
importrsp_w :
   makersp "-+$(OBJDIR:\=\\)\\!s &\n" &&|
   $(IMPOBJS) $(IMPOBJS_W_ONLY)
|  >> $(LIBDIR)\import_w.rsp
#   @echo IMPOBJS = $(IMPOBJS)
#   @echo IMPOBJS_W_ONLY = $(IMPOBJS_W_ONLY)


#############################################################################
# The rule for building the RTL DLL and it's import librarie(s)             #
#############################################################################
dll : $(LIBDIR)\dll.rsp $(LIBDIR)\import.rsp $(OBJDIR)\version.res
    $(LINK) $(LINKEROPTS) -j$(EXTDIR) @dll.rsp,$(DLLNAME),,$(IMPORT) $(EXTLIB),,$(OBJDIR)\version
    $(IMPLIB) $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).lib $(DLLNAME).dll
    fastlib $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).lib $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
#------------------------------------------------------------------------------
# The import libs for the RTLDLL are now created in the following order:
#   First, the IMPOBJS files are TLIBed in (so the linker will see them first)
#   Then the impdefs for the DLLs' exports are added.  This is the reverse of
#   the way they used to be inserted into the import libs prior to BCB 3.0.
    $(TLIB) $(IMPLIBNAME) @import.rsp,nul
    $(TLIB) $(IMPLIBNAME)-+$(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
#------------------------------------------------------------------------------
!if $d(MAGIC)
    $(TLIB) $(IMPLIBNAME_W) @import_w.rsp,nul
    $(TLIB) $(IMPLIBNAME_W)-+$(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
    $(PUBTOOL) $(EXTDIR)\$(PUBNAME) $(IMPLIBNAME_W).lib
!endif
#------------------------------------------------------------------------------
    $(PUBTOOL) $(EXTDIR)\$(PUBNAME) $(IMPLIBNAME).lib
    del $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).lib
    del $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
    if exist $(IMPLIBNAME).bak del $(IMPLIBNAME).bak
    if exist $(IMPLIBNAME_W).bak del $(IMPLIBNAME_W).bak

#############################################################################
# The crux of the build process is to build the required response files for #
# either the static or dynamic RTLs.  As the process scans each directory,  #
# the needed objs are built and placed into $(OBJDIR).  The rule below      #
# makes this possible.                                                      #
#############################################################################
RTLCFG = $(OBJDIR)\rtl.cfg

ALL = rtl_cfg

!if $d(OBJS)
    ALL = $(ALL) $(OBJS)
!   if $d(DLL)
	ALL = $(ALL) dllrsp
!   else
	ALL = $(ALL) librsp
!   endif
!endif

!if $d(MISC)
    ALL = $(ALL) $(MISC)
!endif

!if $d(DLL)
!    if $d(RES)
	 ALL = $(ALL) $(RES)
!    endif
!    if $d(IMPOBJS)
	 ALL = $(ALL) $(IMPOBJS)
!    endif
!    if $d(IMPOBJS_W_ONLY)
	 ALL = $(ALL) $(IMPOBJS_W_ONLY)
!    endif
!    if $d(IMPOBJS_P_ONLY)
	 ALL = $(ALL) $(IMPOBJS_P_ONLY)
!    endif
!    if $d(IMPOBJS) || $d(IMPOBJS_P_ONLY)
	 ALL = $(ALL) importrsp
!    endif
!    if $d(MAGIC)
	 ALL = $(ALL) importrsp_w
!    endif
!endif

!if $d(TASMCFG)
    ALL = tasm.cfg $(ALL) delcfg
!endif

objs : $(ALL)

rtl_cfg: $(RTLCFG)
