rem
rem ObjectWindows - (c) Copyright 1996 by Borland International
rem
@echo off

make MODEL=l  WIN16=1 %1 %2 %3 %4 %5 %6
make DLL=1    WIN16=1 %1 %2 %3 %4 %5 %6
make DLL=1    WIN16=1 USERDLL=1 OWLVER=50 OWLNAME=OWL %1 %2 %3 %4 %5 %6
make MODEL=f          %1 %2 %3 %4 %5 %6
make DLL=1    WIN32=1 OWLVER=50 OWLNAME=OWL %1 %2 %3 %4 %5 %6
make DLL=1    WIN32=1 USERDLL=1 OWLVER=50 OWLNAME=OWL %1 %2 %3 %4 %5 %6
make MODEL=t          %1 %2 %3 %4 %5 %6
make MODEL=t  DLL=1   %1 %2 %3 %4 %5 %6
