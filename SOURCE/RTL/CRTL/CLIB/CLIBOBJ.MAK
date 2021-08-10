# Lists of object files for CLIB.MAK.  The list is split into four sections
# to avoid MAKE's 4096-character limit on rules.

# Included in all libs
# Statically linked in RTLDLL
OBJS1 =         \
    _abort.obj  \
    _stpcpy.obj	\
    abort.obj   \
    abs.obj     \
    alloca.obj  \
    atexit.obj  \
    bdosptr.obj \
    biosequ.obj \
    bios_equ.obj\
    chainint.obj\
    chdir.obj   \
    chdrive.obj \
    clearerr.obj\
    clock.obj   \
    country.obj \
    crotl.obj   \
    crotr.obj   \
    ctrlbrk.obj \
    ddvt.obj    \
    del.obj     \
    delarray.obj\
    delf.obj    \
    delfarry.obj\
    divt.obj    \
    dosclose.obj\
    doscmd.obj  \
    doscmmit.obj\
    doscreat.obj\
    dosdfree.obj\
    dosenv.obj  \
    dosfattr.obj\
    dosfind.obj \
    dosgdate.obj\
    dosgdriv.obj\
    dosgftim.obj\
    doslock.obj \
    dosopen.obj \
    dosread.obj \
    dossdate.obj\
    dosseek.obj\
    dossftim.obj\
    dostimu.obj \
    dosvect.obj \
    doswrite.obj\
    dup2.obj    \
    errormsg.obj\
    exit.obj    \
    fddvt.obj   \
    ffmalloc.obj\
    fgetpos.obj \
    files.obj   \
    files2.obj  \
    fmode.obj   \
    fpstklen.obj\
    fsetpos.obj \
    f_lxmul.obj \
    f_pcmp.obj  \
    f_scopy.obj

# Included in all libs
# Statically linked in RTLDLL
OBJS2 =         \
    getcbrk.obj \
    getcurdi.obj\
    getdate.obj \
    getdisk.obj \
    getdta.obj	\
    getfat.obj  \
    getftime.obj\
    getpsp.obj  \
    getswit.obj \
    getvect.obj \
    getverf.obj \
    getw.obj    \
    heaplen.obj \
    h_ldiv.obj  \
    h_llsh.obj  \
    h_lrsh.obj  \
    h_lursh.obj \
    h_pada.obj  \
    h_padd.obj  \
    h_pina.obj  \
    h_psbh.obj  \
    h_psbp.obj  \
    h_spush.obj \
    inport.obj  \
    ioerror.obj \
    is.obj      \
    isatty.obj  \
    labs.obj    \
    longtoa.obj \
    lrotl.obj   \
    lrotr.obj   \
    lseek.obj   \
    mkdir.obj   \
    mkname.obj  \
    new.obj     \
    newarray.obj\
    newf.obj    \
    newfarry.obj\
    n_lxmul.obj \
    n_pcmp.obj  \
    n_scopy.obj \
    outport.obj \
    parsfnm.obj \
    peek.obj    \
    poke.obj    \
    pureerr.obj \
    rand.obj    \
    reada.obj   \
    remove.obj  \
    rmdir.obj   \
    rmtmp.obj   \
    rotl.obj    \
    rotr.obj    \
    scanner.obj \
    scantol.obj \
    segread.obj \
    setbuf.obj  \
    setdate.obj \
    setdta.obj  \
    setftime.obj\
    setupio.obj \
    sigdata.obj \
    sopen.obj

# Included in all libs
# Statically linked in RTLDLL
OBJS3 =         \
    srchpath.obj\
    stkavail.obj\
    stime.obj   \
    stklen.obj  \
    stpcpy.obj	\
    clocale.obj \
    clower.obj  \
    cupper.obj  \
    ctype.obj   \
    cconv.obj   \
    strxfrm.obj \
    strcoll.obj \
    tolower.obj \
    toupper.obj \
    tell.obj    \
    umask.obj   \
    unhandl.obj \
    unlink.obj  \
    vapp.obj    \
    vappv.obj   \
    vdel.obj    \
    vdelf.obj   \
    vdeln.obj   \
    vdelxf.obj  \
    vdelxn.obj  \
    vnew.obj    \
    vnewf.obj   \
    vnewn.obj   \
    vnewv.obj   \
    vnewvf.obj  \
    vnewvn.obj  \
    vprinter.obj\
    vram.obj    \
    wild.obj    \
    wscroll.obj \
    xclose.obj  \
    xxa.obj     \
    xxv.obj     \
    zapctlz.obj

# Included in DOS libs only
OBJS4 =         \
    assert.obj  \
    allocmem.obj\
    brk.obj     \
    calloc.obj  \
    coreleft.obj\
    cputype.obj \
    dosalloc.obj\
    dosfree.obj \
    dtrcount.obj\
    farheap.obj \
    fbrk.obj    \
    fcalloc.obj \
    fcorelft.obj\
    fheapchk.obj\
    freemem.obj \
    int86.obj   \
    intdos.obj  \
    intr.obj    \
    ioctl.obj   \
    gexit.obj   \
    gfreemem.obj\
    ggetmem.obj \
    gregistr.obj\
    nearheap.obj\
    signal.obj

# Included in DOS libs and special only
OBJS6 =         \
    absread.obj \
    bioscom.obj \
    biosdisk.obj\
    bioskey.obj \
    biosprin.obj\
    bios_com.obj\
    bios_dsk.obj\
    bios_key.obj\
    bios_prn.obj\
    cgets.obj   \
    clreol.obj  \
    clrscr.obj  \
    color.obj   \
    constrea.obj\
    cprintf.obj \
    cputs.obj   \
    crtinit.obj \
    cscanf.obj  \
    cursor.obj  \
    cvtfak.obj  \
    delay.obj   \
    dossetbl.obj\
    doskeep.obj \
    exec.obj    \
    execl.obj   \
    execle.obj  \
    execlp.obj  \
    execlpe.obj \
    execv.obj   \
    execve.obj  \
    execvp.obj  \
    execvpe.obj \
    getch.obj   \
    getpass.obj \
    gotoxy.obj  \
    gptext.obj  \
    hard.obj    \
    harderr.obj \
    insline.obj \
    kbhit.obj   \
    keep.obj    \
    loadprog.obj\
    movetext.obj\
    nheapchk.obj\
    putch.obj   \
    randblk.obj \
    realcvt.obj \
    scantod.obj \
    screen.obj  \
    scroll.obj  \
    setargv.obj \
    setblock.obj\
    setenvp.obj \
    setjmp.obj  \
    sleep.obj   \
    sound.obj   \
    spawn.obj   \
    spawnl.obj  \
    spawnle.obj \
    spawnlp.obj \
    spawnlpe.obj\
    spawnv.obj  \
    spawnve.obj \
    spawnvp.obj \
    spawnvpe.obj\
    stack.obj   \
    system.obj  \
    textmode.obj\
    vidinfo.obj \
    wherexy.obj \
    window.obj

# Included in all libs
# Dynamically linked in RTLDLL
OBJS5 =         \
    _access.obj \
    _ftime.obj  \
    _timecvt.obj\
    _fsopen.obj \
    _setbll.obj \
    _setcoll.obj\
    _setudef.obj\
    _setxfrm.obj\
    _srchpth.obj\
    _strcoll.obj\
    _strxfrm.obj\
    access.obj  \
    atol.obj    \
    bcd1.obj    \
    bcd2.obj    \
    bdos.obj    \
    bsearch.obj \
    castmptr.obj\
    chmod.obj   \
    chmoda.obj  \
    _chmoda.obj  \
    chsize.obj  \
    close.obj   \
    closea.obj  \
    closeall.obj\
    collate.obj \
    cplx1.obj   \
    cplx2.obj   \
    creat.obj   \
    creata.obj  \
    ctime.obj   \
    lstrftim.obj \
    direct.obj  \
    dosext.obj  \
    eof.obj     \
    fclose.obj  \
    fdopen.obj  \
    fflush.obj  \
    fgets.obj   \
    findfirs.obj\
    flength.obj \
    flushall.obj\
    fnmerge.obj \
    fnsplit.obj \
    fopen.obj   \
    fprintf.obj \
    fputs.obj   \
    fread.obj   \
    freopen.obj \
    fscanf.obj  \
    fseek.obj   \
    fstat.obj   \
    ftime.obj   \
    fullpath.obj\
    fwrite.obj  \
    getc.obj    \
    getcwd.obj  \
    getdcwd.obj \
    getenv.obj  \
    gets.obj    \
    lconv.obj   \
    ldivt.obj   \
    locale.obj  \
    lock.obj    \
    locking.obj \
    lsearch.obj \
    lsetlocl.obj \
    lstrcoll.obj \
    lstrlwr.obj \
    lstrupr.obj \
    lstrxfrm.obj\
    ltoa1.obj   \
    ltolower.obj\
    ltoupper.obj\
    makepath.obj\
    mbyte1.obj  \
    memccpy.obj \
    memchr.obj  \
    memcmp.obj  \
    memcpy.obj  \
    memicmp.obj \
    memset.obj  \
    mktemp.obj  \
    movedata.obj\
    movmem.obj  \
    open.obj    \
    opena.obj   \
    perror.obj  \
    printf.obj  \
    putc.obj    \
    putenv.obj  \
    puts.obj    \
    putw.obj    \
    qsort.obj   \
    read.obj    \
    readu.obj   \
    rename.obj  \
    rewind.obj  \
    scanf.obj   \
    srchenv.obj \
    srchstr.obj \
    setlocal.obj\
    setmode.obj \
    setvbuf.obj \
    splitpth.obj\
    sprintf.obj \
    sscanf.obj  \
    stat.obj    \
    strcat.obj  \
    strchr.obj  \
    strcmp.obj  \
    strcpy.obj  \
    strcspn.obj \
    strdate.obj \
    strdup.obj  \
    strerror.obj\
    strftime.obj \
    stricmp.obj \
    strlen.obj  \
    strlwr.obj  \
    strncat.obj \
    strncmp.obj \
    strncpy.obj \
    strnicmp.obj\
    strnset.obj \
    strpbrk.obj \
    strrchr.obj \
    strrev.obj  \
    strset.obj  \
    strspn.obj  \
    strstr.obj  \
    strtok.obj  \
    strtol.obj  \
    strtoul.obj \
    strupr.obj  \
    swab.obj    \
    tempnam.obj \
    timecvt.obj \
    tmpfile.obj \
    tmpnam.obj  \
    tzset.obj   \
    ungetc.obj  \
    utime.obj   \
    vfprintf.obj\
    vfscanf.obj \
    vprintf.obj \
    vscanf.obj  \
    write.obj   \
    writea.obj  \
    writeu.obj  \
    xalloc.obj  \
    xfclose.obj \
    xfflush.obj \
    xmsg.obj    \
    xx.obj

# From the common directory
# Included in all libs
# Dynamically linked in RTLDLL
OBJS7 =         \
    append1.obj  \
    append2.obj  \
    append3.obj  \
    assign.obj  \
    checks.obj  \
    clone.obj  \
    compare1.obj  \
    compare2.obj  \
    copy1.obj  \
    copy2.obj  \
    copy3.obj  \
    ctor1.obj  \
    ctor2.obj  \
    ctor3.obj  \
    ctor4.obj  \
    ctor5.obj  \
    ctor6.obj  \
    ctor7.obj  \
    ctor8.obj  \
    contain.obj  \
    find1.obj  \
    find2.obj  \
    find3.obj  \
    find4.obj  \
    fndfrst.obj  \
    fndfrstn.obj  \
    fndlast.obj  \
    fndlastn.obj  \
    hash.obj  \
    insert1.obj  \
    insert2.obj  \
    match.obj  \
    oprasgn1.obj  \
    oprasgn2.obj  \
    oprasgn3.obj  \
    oprcall1.obj  \
    oprcall2.obj  \
    oprcall3.obj  \
    oprcall4.obj  \
    opreql.obj  \
    oprplus.obj  \
    prepend.obj  \
    regexp.obj  \
    stremove.obj  \
    replace.obj  \
    reserve.obj  \
    resize.obj  \
    rfind.obj  \
    status.obj  \
    stringio.obj  \
    strings.obj  \
    strip.obj  \
    substr1.obj  \
    substr2.obj  \
    uprlwr.obj
