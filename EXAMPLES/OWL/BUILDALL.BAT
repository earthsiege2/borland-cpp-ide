@echo off
if {%mk%} == {} set __mk=1
if {%mk%} == {} set mk=make.exe

echo Building All %1 %2 %3 %4

if exist    apps\NUL    cd apps
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\apps\NUL    cd ..

if exist   classes\NUL  cd classes
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\classes\NUL cd ..

if exist   experts\NUL  cd experts
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\experts\NUL cd ..

if exist   games\NUL    cd games
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\games\NUL   cd ..

if exist    ocf\NUL     cd ocf
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist  ..\ocf\NUL    cd ..

if exist   tasks\NUL    cd tasks
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist  ..\tasks\NUL  cd ..

if exist   tutorial\NUL cd tutorial
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\tutorial\NUL cd ..

if exist   winapi\NUL   cd winapi
call buildall %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\winapi\NUL  cd ..

:end

if {%__mk%} == {1}  set   mk=
if {%__mk%} == {1}  set __mk=
