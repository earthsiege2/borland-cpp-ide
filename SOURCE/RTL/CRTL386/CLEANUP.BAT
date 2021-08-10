rem This batch file deletes all of the objects which are built
rem for the WIN32 386 32-bit libraries

del win32\*.fst
del win32\lib < yes.txt
del win32\log < yes.txt
call xxdel win32\obj
call xxdel win32\objx
call xxdel win32\objmt
call xxdel win32\objmtx
