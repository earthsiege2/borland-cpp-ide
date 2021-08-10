@echo off
if /%mk%/ == // set mk=make

if exist   aclock\NUL   cd aclock
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\aclock\NUL  cd ..

if exist   applaunc\NUL cd applaunc
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\applaunc\NUL cd ..

if exist   blazer\NUL   cd blazer
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\blazer\NUL  cd ..

if exist   bmpview\NUL  cd bmpview
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\bmpview\NUL cd ..

if exist   calc\NUL     cd calc
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\calc\NUL    cd ..

if exist   cursor\NUL   cd cursor
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\cursor\NUL  cd ..

if exist   draw\NUL     cd draw
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\draw\NUL    cd ..

if exist filebrow\NUL   cd filebrow
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\filebrow\NUL cd ..

if exist  gdidemo\NUL   cd gdidemo
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\gdidemo\NUL cd ..

if exist  hello\NUL     cd hello
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\hello\NUL   cd ..

if exist intldemo\NUL   cd intldemo
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\intldemo\NUL cd ..

if exist led\NUL        cd led
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\led\NUL     cd ..

if exist mdifile\NUL    cd mdifile
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mdifile\NUL cd ..

if exist mthread\NUL    cd mthread
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mthread\NUL cd ..

if exist notebook\NUL   cd notebook
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\notebook\NUL cd ..

if exist owlcmd\NUL     cd owlcmd
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\owlcmd\NUL  cd ..

if exist paint\NUL      cd paint
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\paint\NUL   cd ..

if exist peeper\NUL     cd peeper
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\peeper\NUL  cd ..

if exist scrnsave\NUL   cd scrnsave
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\scrnsave\NUL cd ..

if exist sdifile\NUL    cd sdifile
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\sdifile\NUL cd ..

:end
