if /%mk%/ == // set mk=make

%mk% %1 %2 %3 %4
if errorlevel 1 set err=1

if exist  ole\NUL   cd ole
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ole\NUL cd ..

:end
