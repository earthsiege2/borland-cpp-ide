@echo off
if /%mk%/ == // set mk=make

if exist comm2doc\NUL    cd comm2doc
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\comm2doc\NUL cd ..

if exist diagxprt\NUL    cd diagxprt
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\diagxprt\NUL cd ..

if exist outdeb32\NUL    cd outdeb32
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\outdeb32\NUL cd ..

if exist rdme2hlp\NUL    cd rdme2hlp
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\rdme2hlp\NUL cd ..

:end
