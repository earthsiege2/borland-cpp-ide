# Sub-makefile for NT run-time library for BC++.
# Included by MAKEFILE when -DCLIB is specified.

OBJ1 = \
abort.obj \
abs.obj \
access.obj \
alloca.obj \
allocbuf.obj \
assert.obj \
assertf.obj \
atexit.obj \
atol.obj \
bcd1.obj \
bsearch.obj \
calloc.obj \
cfinfo.obj \
cgets.obj \
chsize.obj \
clearerr.obj \
close.obj \
closeall.obj \
color.obj \
cprintf.obj \
cputn.obj \
cputs.obj \
creat.obj \
createmp.obj \
creatnew.obj \
crotl.obj \
crotr.obj \
cscanf.obj \
ctime.obj \
ctype.obj \
cvtentry.obj \
cvtfak.obj \
cwait.obj \
deflt87.obj \
div.obj \
dtrcount.obj \
dup.obj \
dup2.obj \
eof.obj \
errno.obj \
except.obj \
execl.obj \
execle.obj \
execlp.obj \
execlpe.obj \
execv.obj \
execve.obj \
execvp.obj \
execvpe.obj \
exit.obj \
fclose.obj \
fdopen.obj \
fflush.obj \
fgetchar.obj \
fgetpos.obj \
fgets.obj \
files.obj \
files2.obj \
findfrst.obj \
flushall.obj \
fmodeptr.obj \
fnmerge.obj \
fnsplit.obj \
fopen.obj \
fprintf.obj \
fputchar.obj \
fputn.obj \
fputs.obj \
fread.obj \
freopen.obj \
fscanf.obj \
fseek.obj \
fsetpos.obj \
ftruncat.obj \
fwrite.obj \
getcwd.obj \
getenv.obj \
getftime.obj \
getmem.obj \
getpass.obj \
getpid.obj \
gets.obj \
getw.obj \
gmtime.obj \
gotoxy.obj \
gptext.obj \
heap.obj \
heapchk.obj \
heapchkf.obj \
heapchkn.obj \
heapfill.obj \
heapmin.obj \
heapset.obj \
heapwalk.obj \
insline.obj \
is.obj \
isatty.obj \
labs.obj \
lgetc.obj \
locales.obj \
lonedll.obj \
longtoa.obj \
lputc.obj \
lrotl.obj \
lrotr.obj \
lsearch.obj \
lseek.obj \
ltoa1.obj \
makepath.obj \
memccpy.obj \
memchk.obj \
memchr.obj \
memcmp.obj \
memcpy.obj \
memicmp.obj \
memmove.obj \
memset.obj \
mkname.obj \
mktemp.obj \
mktime.obj \
oheapchk.obj \
oheapwlk.obj \
open.obj \
perror.obj \
printf.obj \
putch.obj \
putenv.obj \
puts.obj \
putw.obj \
qsort.obj \
qstpcpy.obj \
qstrcat.obj \
qstrchr.obj \
qstrcmp.obj \
qstrcpy.obj \
rand.obj \
read.obj \
realloc.obj \
remove.obj \
rewind.obj \
rmtmp.obj \
rotl.obj \
rotr.obj

OBJ2 = \
scanf.obj \
scanner.obj \
scantol.obj \
setargv.obj \
setbuf.obj \
setftime.obj \
setmode.obj \
setvbuf.obj \
sopen.obj \
spawnl.obj \
spawnle.obj \
spawnlp.obj \
spawnlpe.obj \
spawnv.obj \
spawnve.obj \
spawnvp.obj \
spawnvpe.obj \
splitpth.obj \
sprintf.obj \
srchenv.obj \
srchpath.obj \
srchstr.obj \
sscanf.obj \
startup.obj \
startupd.obj \
stkavail.obj \
stpcpy.obj \
strcat.obj \
strchr.obj \
strcmp.obj \
strcoll.obj \
strcpy.obj \
strcspn.obj \
strdup.obj \
streams.obj \
strerror.obj \
strftime.obj \
stricmp.obj \
strlen.obj \
strlwr.obj \
strncat.obj \
strncmp.obj \
strncpy.obj \
strnicmp.obj \
strnset.obj \
strpbrk.obj \
strrchr.obj \
strrev.obj \
strset.obj \
strspn.obj \
strstr.obj \
strtok.obj \
strtol.obj \
strtoul.obj \
strupr.obj \
strxfrm.obj \
swab.obj \
tell.obj \
tempnam.obj \
textmode.obj \
timecvt.obj \
timedata.obj \
tmpfile.obj \
tmpnam.obj \
tolower.obj \
toupper.obj \
tzset.obj \
umask.obj \
ungetc.obj \
unlink.obj \
validxy.obj \
vfprintf.obj \
vfscanf.obj \
vidinfo.obj \
vprinter.obj \
vprintf.obj \
vscanf.obj \
wait.obj \
wherexy.obj \
wild.obj \
window.obj \
write.obj \
wscroll.obj \
xfclose.obj \
xfflush.obj

OBJ3 = \
__eof.obj \
__read.obj \
__write.obj \
_cfinfo.obj \
_creat.obj \
_fdopen.obj \
_flshall.obj \
_fputc.obj \
_fsopen.obj \
_popen.obj \
_stpcpy.obj \
_umask.obj

OBJ4 = \
8087.obj \
_matherl.obj \
_matherr.obj \
_pow10.obj \
_setbll.obj \
_setcoll.obj \
_setudef.obj \
_setxfrm.obj \
_strcoll.obj \
_strxfrm.obj \
acosasin.obj \
acossinl.obj \
atan.obj \
atan2.obj \
atan2l.obj \
atanl.obj \
atof.obj \
atold.obj \
ceil.obj \
ceill.obj \
clear87.obj \
clocale.obj \
cconv.obj \
clower.obj \
cupper.obj \
collate.obj \
cos.obj \
cosh.obj \
coshl.obj \
cosl.obj \
ctrl87.obj \
difftime.obj \
efcvt.obj \
exp.obj \
expl.obj \
expld.obj \
f87atan.obj \
f87exp.obj \
f87log.obj \
f87sine.obj \
fabs.obj \
fabsl.obj \
fbstp.obj \
fildq.obj \
fistq.obj \
floor.obj \
floorl.obj \
fmod.obj \
fmodl.obj \
fpreset.obj \
frexp.obj \
frexpl.obj \
ftol.obj \
fuildq.obj \
fuistq.obj \
fxam.obj \
gcvt.obj \
hugeval.obj \
hypot.obj \
hypotl.obj \
initcvt.obj \
ldexp.obj \
ldexpl.obj \
ldtrunc.obj \
locale.obj \
log.obj \
log10.obj \
log10l.obj \
logl.obj \
lsetlocl.obj \
lconv.obj \
lstrftim.obj \
lstrcoll.obj \
lstrlwr.obj \
lstrupr.obj \
lstrxfrm.obj \
ltolower.obj \
ltoupper.obj \
mathptr.obj \
mathwhy.obj \
mbyte1.obj \
modf.obj \
modfl.obj \
poly.obj \
polyl.obj \
pow.obj \
pow10d.obj \
pow10l.obj \
powl.obj \
qdiv10.obj \
qmul10.obj \
realcvt.obj \
round.obj \
scantod.obj \
setlocal.obj \
sin.obj \
sinh.obj \
sinhl.obj \
sinl.obj \
sqrt.obj \
sqrtl.obj \
stat87.obj \
strtod.obj \
tan.obj \
tanh.obj \
tanhl.obj \
tanl.obj \
xcvt.obj

CPPOBJ = \
bcd2.obj \
castmptr.obj \
constrea.obj \
cplx1.obj \
cplx2.obj \
del.obj \
delarray.obj \
new.obj \
newarray.obj \
ta.obj \
vapp.obj \
vappv.obj \
vdel.obj \
vdelx.obj \
vnew.obj \
vnewv.obj \
xalloc.obj \
xmsg.obj \
xx.obj

STROBJ = \
append1.obj \
append2.obj \
append3.obj \
assign.obj \
checks.obj \
clone.obj \
compare1.obj \
compare2.obj \
copy1.obj \
copy2.obj \
copy3.obj \
ctor1.obj \
ctor2.obj \
ctor3.obj \
ctor4.obj \
ctor5.obj \
ctor6.obj \
ctor7.obj \
ctor8.obj \
contain.obj \
find1.obj \
find2.obj \
find3.obj \
find4.obj \
fndfrst.obj \
fndfrstn.obj \
fndlast.obj \
fndlastn.obj \
hash.obj \
insert1.obj \
insert2.obj \
match.obj \
oprasgn1.obj \
oprasgn2.obj \
oprasgn3.obj \
oprcall1.obj \
oprcall2.obj \
oprcall3.obj \
oprcall4.obj \
opreql.obj \
oprplus.obj \
prepend.obj \
regexp.obj \
stremove.obj \
replace.obj \
reserve.obj \
resize.obj \
rfind.obj \
status.obj \
stringio.obj \
strings.obj \
strip.obj \
substr1.obj \
substr2.obj \
uprlwr.obj \

!ifdef MT
MTOBJ = \
fgetc.obj \
fputc.obj \
thrdbuf.obj
!endif


# IMPOBJ lists objects that must be statically linked, and are placed
# in the import library.

IMPOBJ = \
__memchr.obj \
__strchr.obj \
__strrch.obj \
__strpbr.obj \
__strstr.obj \
chkstk.obj \
ddvt.obj \
fmode.obj \
matherr.obj \
matherrl.obj \
nowild.obj \
pureerr.obj \
setargv2.obj \
xxa.obj \
xxv.obj


OBJ5 = $(CPPOBJ) $(MTOBJ) $(IMPOBJ) $(STROBJ)

# Objects that must be built but are not part of the libary.

!ifndef MT
MISCOBJ = $(LIB)\wildargs.obj $(LIB)\fileinfo.obj

$(LIB)\wildargs.obj : wildargs.obj
   copy $(OBJ)\wildargs.obj $(LIB)

$(LIB)\fileinfo.obj : fileinfo.obj
   copy $(OBJ)\fileinfo.obj $(LIB)
!endif

# If building the DLL, start building the linker response file containing
# the objects that will be placed in the DLL, and the librarian response
# file that will be used to add the statically linked objects to the
# import library.

!if $d(DLL)
DLLRSP = dllrsp importrsp

dllrsp :
   echo $(LIB)\\\\c0d32.obj+ >dll.rsp
   makersp "$(OBJ)\\\\!s+\n" &&|
   $(OBJ1)
   $(OBJ2)
   $(OBJ3)
   $(OBJ4)
   $(OBJ5)
|  >> dll.rsp

importrsp :
   makersp "+$(OBJ)\\\\!s &\n" &&|
   $(IMPOBJ)
|  > import.rsp

!endif

# Multiple dummy targets are used to get around MAKE's annoying
# limit on line length.

lib1 : $(OBJ1)
lib2 : $(OBJ2)
lib3 : $(OBJ3)
lib4 : $(OBJ4)
lib5 : $(OBJ5)

lib : lib1 lib2 lib3 lib4 lib5 $(MISCOBJ) $(DLLRSP)

# Dependencies not covered by default rules.

wild.obj     : $(SRC)\setargv.c $(SRC)\setargv2.c
