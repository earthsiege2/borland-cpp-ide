rem
rem ObjectWindows - (C) Copyright 1992 by Borland International
rem   source\owl\buildowl.bat

rem Build OWL

rem build 16-bit static link libraries

make -DMODEL=s %1
make -DMODEL=m %1
make -DMODEL=l %1

rem build 16-bit DLL

make -DDLL %1

rem build 32-bit static link library

make -DWIN32 %1

rem build 32-bit DLL

make -DWIN32 -DDLL %1
