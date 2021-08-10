@echo off
if /%mk%/ == // set mk=make

if exist blakjack\NUL    cd blakjack
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\blakjack\NUL cd ..

if exist blocks\NUL     cd blocks
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\blocks\NUL  cd ..

if exist chess\NUL      cd chess
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\chess\NUL   cd ..

if exist cribbage\NUL   cd cribbage
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\cribbage\NUL cd ..

if exist meteor\NUL     cd meteor
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\meteor\NUL  cd ..

if exist swat\NUL       cd swat
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\swat\NUL    cd ..

if exist ttt\NUL        cd ttt
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ttt\NUL     cd ..

if exist ttt2\NUL       cd ttt2
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ttt2\NUL    cd ..

:end
