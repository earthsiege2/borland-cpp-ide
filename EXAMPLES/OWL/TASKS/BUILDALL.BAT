@echo off
if /%mk%/ == // set mk=make

if exist colordlg\NUL    cd colordlg
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\colordlg\NUL cd ..

if exist dllhello\NUL    cd dllhello
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\dllhello\NUL cd ..

if exist dynamenu\NUL    cd dynamenu
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\dynamenu\NUL cd ..

if exist instance\NUL    cd instance
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\instance\NUL cd ..

if exist mdidlg\NUL     cd mdidlg
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mdidlg\NUL  cd ..

if exist mdistrm\NUL     cd mdistrm
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mdistrm\NUL  cd ..

if exist modalwin\NUL    cd modalwin
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\modalwin\NUL cd ..

if exist notify\NUL      cd notify
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\notify\NUL   cd ..

if exist ownerdra\NUL    cd ownerdra
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ownerdra\NUL cd ..

if exist popup\NUL       cd popup
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\popup\NUL    cd ..

if exist simbor\NUL      cd simbor
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\simbor\NUL   cd ..

if exist tbexpert\NUL    cd tbexpert
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\tbexpert\NUL cd ..

if exist transfer\NUL    cd transfer
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\transfer\NUL cd ..

:end
