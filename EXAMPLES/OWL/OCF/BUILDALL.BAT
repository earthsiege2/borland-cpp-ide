@echo off
if {%mk%} == {} set mk=make

if exist mdiole\NUL   cd mdiole
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mdiole\NUL cd ..

if exist ocxdlg\NUL   cd ocxdlg
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ocxdlg\NUL cd ..

if exist sdiole\NUL   cd sdiole
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\sdiole\NUL cd ..

if exist ttt\NUL      cd ttt
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ttt\NUL   cd ..

:end
