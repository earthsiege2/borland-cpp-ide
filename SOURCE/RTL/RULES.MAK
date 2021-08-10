#############################################################################
# In order to make a suite, define one or more of the following             #
#                                                                           #
#    DEBUG - Used to build a debuggable version of the RTL.                 #
#                                                                           #
#      DLL - Used to build the DLL version of the RTL.                      #
#                                                                           #
#    MODEL - Used to indicate a memory model under DOS, and WIN16.  The     #
#            default is the small model.  It should be one of:              #
#              t = Tiny model     (DOS)                                     #
#              s = Small model    (DOS,WIN16)                               #
#              m = Medium model   (DOS,WIN16)                               #
#              c = Compact model  (DOS,WIN16)                               #
#              l = Large model    (DOS,DPMI16,WIN16)                        #
#              h = Huge model     (DOS)                                     #
#                                                                           #
#       MT - Used to include multiple thread support.  This is only allowed #
#            for WIN32 and OS2.                                             #
#                                                                           #
#       OS - Used to indicate the OS.  The default is DOS.  It should be    #
#            one of the following:                                          #
#              DOS    = 16 bit DOS                                          #
#              DPMI16 = 16 bit DPMI                                         #
#              WIN16  = 16 bit Windows                                      #
#              DPMI32 = 32 bit DPMI                                         #
#              WIN32S = 32 bit Windows on 16 bit Windows (Win32s)           #
#              WIN32  = 32 bit Windows on 32 bit Windows (NT,Chicago,Cairo) #
#              OS2    = 32 bit OS/2                                         #
#                                                                           #
#      PCH - Used to turn on precompiled headers                            #
#                                                                           #
#############################################################################


#############################################################################
# Setup some reasonable defaults.                                           #
#############################################################################
!if !$d(OS)
    OS = dos
!endif


BC45ROOT  = \bc45

!if !$d(RTLROOT)
    RTLROOT = $(BC45ROOT)\source\rtl
!endif

#############################################################################
# Setup some useful directories.                                            #
#############################################################################
BC45INCL  = $(BC45ROOT)\include
INCLBASE  = $(RTLROOT)
LIBDIR    = $(RTLROOT)\lib
OBJBASE   = $(RTLROOT)\obj\$(OS)
SRCBASE   = $(RTLROOT)\source
DEFDIR    = $(SRCBASE)\defs\$(OS)

#############################################################################
# Guard against illegal variable combinations and obtain the operating      #
# platform specific build rules.                                            #
#############################################################################
!if $(OS) != DOS && $(OS) != WIN16 && $(OS) != DPMI16 && \
    $(OS) != DPMI32 && $(OS) != WIN32 && $(OS) != OS2
!    error Unknown OS
!endif

!if $(OS) == DOS
!    if !$d(MODEL)
	 MODEL = s
!    elif $(MODEL) != t && $(MODEL) != s && $(MODEL) != m &&\
	  $(MODEL) != c && $(MODEL) != l && $(MODEL) != h
!        error Invalid memory model
!    endif
!elif $(OS) == DPMI16 || $(OS) == WIN16
!    if $(OS) == DPMI16
!        if !$d(MODEL)
	     MODEL = l
!        elif $(MODEL) != l
!            error Invalid MODEL
!        endif
!    else
!        if !$d(MODEL)
	     MODEL = s
!        elif $(MODEL) != s && $(MODEL) != m && $(MODEL) != c && $(MODEL) != l
!            error Invalid MODEL
!        endif
!    endif
!elif $d(MODEL)
!    error The chosen OS does not support MODEL
!endif

!if $d(MT)
!    if $(OS) != WIN32 && $(OS) != OS2
!        error The chosen OS does not support MT
!    endif
!endif

!if $(OS) == DOS && $d(DLL)
!    error The chosen OS does not support DLL
!endif

!include $(OS).mak

#############################################################################
# Configure the output paths.                                               #
#############################################################################
.PATH.lib = $(LIBDIR)
.PATH.obj = $(OBJDIR)
.PATH.res = $(OBJDIR)

#############################################################################
# Adjust switches accordingly.                                              #
#############################################################################
!if $d(DEBUG)
    CC   = $(CC) -v
    ASM  = $(ASM) -zi
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

.def.fst:
    $(IMPLIB) $&.lib $&.def
    fastlib $&.lib $&.fst
    del $&.lib

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
    if exist tasm.cfg del tasm.cfg

cfg : $(OBJDIR)\rtl.cfg

#############################################################################
# The rule for building a response file for library creation.               #
#############################################################################
librsp :
    makersp "-+$(OBJDIR:\=\\)\\%s &\n" &&|
	    $(OBJS)
|   >> $(LIBDIR)\tlib.rsp

#############################################################################
# The rule for building the static RTL.                                     #
#############################################################################
lib : librsp
    $(TLIB) $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).lib @tlib.rsp,temp.lst
    if exist $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).bak del $(LIBDIR)\$(LIBNAME)$(MTSUFFIX).bak
    del temp.lst

#############################################################################
# The rules for building response files for RTL DLL and import library      #
# creation                                                                  #
#############################################################################
dllrsp :
   makersp "$(OBJDIR:\=\\)\\!s+\n" &&|
   $(OBJS)
|  >> $(LIBDIR)\dll.rsp

importrsp :
   makersp "-+$(OBJDIR:\=\\)\\!s &\n" &&|
   $(IMPOBJS)
|  >> $(LIBDIR)\import.rsp

#############################################################################
# The rule for building the RTL DLL.                                        #
#############################################################################
dll : $(LIBDIR)\dll.rsp $(LIBDIR)\import.rsp $(OBJDIR)\version.res
    copy &&|
    $(DEFDIR)\$(DLLDEF), $(OBJDIR)\version
|   dll1.rsp
    $(LINK) @dll.rsp,$(DLLNAME),,$(IMPORT), @dll1.rsp
    implib $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).lib $(DLLNAME).dll
    fastlib $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).lib $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
    $(TLIB) $(IMPLIBNAME)-+$(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
    $(TLIB) $(IMPLIBNAME) @import.rsp,nul
    del $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).lib
    del $(LIBNAME)$(MTSUFFIX)$(DLLSUFFIX).fst
    del $(IMPLIBNAME).bak
    del dll1.rsp

#############################################################################
# The crux of the build process is to build the required response files     #
# either the static or dynamic RTLs.  As the process scans each directory,  #
# the needed objs are built and placed into $(OBJDIR).  The rule below      #
# makes this possible.                                                      #      
#############################################################################
ALL = $(OBJDIR)\rtl.cfg

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
	 ALL = $(ALL) $(IMPOBJS) importrsp
!    endif
!endif

!if $d(TASMCFG)
    ALL = tasm.cfg $(ALL) delcfg
!endif

objs : $(ALL)

