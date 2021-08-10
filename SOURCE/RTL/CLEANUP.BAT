rem  This batch file deletes the all of the objects built for
rem  the 16-bit and 32-bit libraries.

cd crtl
call cleanup
cd ..\crtl386
call cleanup
cd ..