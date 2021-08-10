# List of object files for WINLIB.MAK.

# Used in all Windows libs
# Statically linked in RTLDLL
OBJS1 =         \
    cvtfak.obj  \
    easywin.obj \
    errexit.obj \
    ewconio.obj \
    ewinproc.obj\
    fperr.obj   \
    fpinit.obj  \
    h_chkstk.obj\
    libmain.obj \
    necp.obj    \
    ptable.obj  \
    sigshell.obj\
    wrealcvt.obj\
    wscantod.obj\
    setargv.obj \
    setargv0.obj\
    setenv.obj  \
    setenvrn.obj\
    setjmp.obj  \
    wcfncptr.obj\
    wep.obj     \
    winmain.obj

# Used in all Windows libs and special
# Statically linked in RTLDLL
OBJS4 =         \
    farheap.obj \
    heap.obj    \
    intr.obj    \
    intdos.obj  \
    int86.obj   \
    ioctl.obj   \
    suballoc.obj

# Used in all Windows libs
# Dynamically linked in RTLDLL
OBJS2 =         \
    asmmem.obj  \
    assert.obj  \
    fheap.obj   \
    signal.obj  \
    winmem.obj  \
    wstrings.obj\

# Used only in RTLDLL
# Dynamically linked in RTLDLL
OBJS3 =         \


