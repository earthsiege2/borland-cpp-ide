@echo off
if /%mk%/ == // set mk=make

if exist animctl\NUL     cd animctl
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\animctl\NUL  cd ..

if exist button\NUL      cd button
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\button\NUL   cd ..

if exist checklst\NUL      cd checklst
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\checklst\NUL   cd ..

if exist cmdenabl\NUL    cd cmdenabl
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\cmdenabl\NUL cd ..

if exist colmnhdr\NUL    cd colmnhdr
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\colmnhdr\NUL cd ..

if exist color\NUL       cd color
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\color\NUL    cd ..

if exist combobox\NUL    cd combobox
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\combobox\NUL cd ..

if exist commdlg\NUL     cd commdlg
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\commdlg\NUL  cd ..

if exist ctxthelp\NUL    cd ctxthelp
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\ctxthelp\NUL cd ..

if exist dibitmap\NUL    cd dibitmap
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\dibitmap\NUL cd ..

if exist docking\NUL     cd docking
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\docking\NUL  cd ..

if exist docview\NUL     cd docview
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\docview\NUL  cd ..

if exist draglist\NUL    cd draglist
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\draglist\NUL cd ..

if exist edit\NUL        cd edit
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\edit\NUL     cd ..

if exist editsear\NUL    cd editsear
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\editsear\NUL cd ..

if exist gadgets\NUL     cd gadgets
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\gadgets\NUL  cd ..

if exist gauge\NUL       cd gauge
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\gauge\NUL    cd ..

if exist glyphbtn\NUL    cd glyphbtn
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\glyphbtn\NUL cd ..

if exist groupbox\NUL    cd groupbox
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\groupbox\NUL cd ..

if exist hotkey\NUL      cd hotkey
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\hotkey\NUL   cd ..

if exist imagelst\NUL    cd imagelst
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\imagelst\NUL cd ..

if exist layout\NUL      cd layout
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\layout\NUL   cd ..

if exist listbox\NUL     cd listbox
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\listbox\NUL  cd ..

if exist listwind\NUL    cd listwind
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\listwind\NUL cd ..

if exist mciwnd\NUL      cd mciwnd
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mciwnd\NUL   cd ..

if exist mdi\NUL         cd mdi
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mdi\NUL      cd ..

if exist metafile\NUL         cd metafile
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\metafile\NUL      cd ..

if exist mru\NUL         cd mru
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\mru\NUL      cd ..

if exist palette\NUL     cd palette
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\palette\NUL  cd ..

if exist picklist\NUL    cd picklist
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\picklist\NUL cd ..

if exist pictwnd\NUL    cd pictwnd
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\pictwnd\NUL cd ..

if exist printing\NUL    cd printing
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\printing\NUL cd ..

if exist prntprev\NUL    cd prntprev
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\prntprev\NUL cd ..

if exist propsht\NUL    cd propsht
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\propsht\NUL cd ..

if exist richedit\NUL    cd richedit
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\richedit\NUL cd ..

if exist rolldial\NUL    cd rolldial
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\rolldial\NUL cd ..

if exist scrollba\NUL    cd scrollba
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\scrollba\NUL cd ..

if exist scroller\NUL    cd scroller
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\scroller\NUL cd ..

if exist shell\NUL    cd shell
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\shell\NUL cd ..

if exist slider\NUL      cd slider
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\slider\NUL   cd ..

if exist splash\NUL      cd splash
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\splash\NUL   cd ..

if exist splitter\NUL      cd splitter
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\splitter\NUL   cd ..

if exist static\NUL      cd static
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\static\NUL   cd ..

if exist tabctrl\NUL     cd tabctrl
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\tabctrl\NUL  cd ..

if exist toolbres\NUL     cd toolbres
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\toolbres\NUL  cd ..

if exist toolbox\NUL     cd toolbox
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\toolbox\NUL  cd ..

if exist tooltip\NUL     cd tooltip
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\tooltip\NUL  cd ..

if exist treewind\NUL    cd treewind
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\treewind\NUL cd ..

if exist uiborder\NUL     cd uiborder
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\uiborder\NUL  cd ..

if exist uiface\NUL     cd uiface
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\uiface\NUL  cd ..

if exist updown\NUL      cd updown
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\updown\NUL   cd ..

if exist validate\NUL    cd validate
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\validate\NUL cd ..

if exist vbxctl\NUL      cd vbxctl
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\vbxctl\NUL   cd ..

if exist verinfo\NUL      cd verinfo
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\verinfo\NUL   cd ..

if exist winsock\NUL      cd winsock
%mk% %1 %2 %3 %4
if errorlevel 1 set err=1
if exist ..\winsock\NUL   cd ..

:end
