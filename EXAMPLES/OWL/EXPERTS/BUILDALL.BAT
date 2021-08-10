@echo off
if /%mk%/ == // set mk=make

if exist apxdlg\nul      cd apxdlg
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxdlg\nul   cd ..

if exist apxdlgdv\nul    cd apxdlgdv
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxdlgdv\nul cd ..

if exist apxmdi\nul      cd apxmdi
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxmdi\nul   cd ..

if exist apxmdidv\nul    cd apxmdidv
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxmdidv\nul cd ..

if exist apxole\nul      cd apxole
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxole\nul   cd ..

if exist apxsdi\nul      cd apxsdi
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxsdi\nul   cd ..

if exist apxsdidv\nul    cd apxsdidv
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apxsdidv\nul cd ..


:end
