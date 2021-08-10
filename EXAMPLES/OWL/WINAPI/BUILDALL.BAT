@echo off
if /%mk%/ == // set mk=make

if exist ddeml\NUL  cd ddeml
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ddeml\NUL cd ..

if exist dragdrop\NUL  cd dragdrop
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\dragdrop\NUL cd ..

if exist drawedge\NUL  cd drawedge
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\drawedge\NUL cd ..

if exist drawstat\NUL  cd drawstat
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\drawstat\NUL cd ..

if exist help\NUL  cd help
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\help\NUL cd ..

if exist mcisound\NUL  cd mcisound
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mcisound\NUL cd ..

if exist mciwnd\NUL  cd mciwnd
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mciwnd\NUL cd ..

if exist progman\NUL  cd progman
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\progman\NUL cd ..

if exist syscolor\NUL  cd syscolor
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\syscolor\NUL cd ..

if exist sysinfo\NUL  cd sysinfo
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\sysinfo\NUL cd ..

if exist sysmetri\NUL  cd sysmetri
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\sysmetri\NUL cd ..

if exist truetype\NUL  cd truetype
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\truetype\NUL cd ..

:end
