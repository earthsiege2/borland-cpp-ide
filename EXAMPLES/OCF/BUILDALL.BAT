@echo off
@echo on
if {%mk%} == {} set mk=make

echo %1 %2 %3 %4

cd cpp

cd autocalc
%mk% %1 %2 %3 %4
if errorlevel 1 goto end
cd ..

rem cd com
rem %mk% %1 %2 %3 %4
rem if errorlevel 1 goto end
rem cd ..

rem cd hook
rem %mk% %1 %2 %3 %4
rem if errorlevel 1 goto end
rem cd ..

cd localize
%mk% MODEL=l %1 %2 %3 %4 
if errorlevel 1 goto end
cd ..

cd regtest
%mk% %1 %2 %3 %4
if errorlevel 1 goto end
cd ..

rem cd scrap
rem %mk% %1 %2 %3 %4
rem if errorlevel 1 goto end
rem cd ..

cd tutorial
%mk% %1 %2 %3 %4
if errorlevel 1 goto end
cd ..

cd ..

:end
set mk=
