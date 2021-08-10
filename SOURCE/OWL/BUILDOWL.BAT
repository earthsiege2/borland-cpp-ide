rem
rem ObjectWindows - (c) Copyright 1996 by Borland International
rem
@echo off

make MODEL=l  WIN16=1 %1 %2 %3 %4 %5 %6
make DLL=1    WIN16=1 OWLVER=52 OWLNAME=OWL %1 %2 %3 %4 %5 %6
make DLL=1    WIN16=1 USERDLL=1 OWLVER=52 OWLNAME=OWL %1 %2 %3 %4 %5 %6
make MODEL=f  WIN32=1 %1 %2 %3 %4 %5 %6
make DLL=1    WIN32=1 OWLVER=52 OWLNAME=OWL %1 %2 %3 %4 %5 %6
make MODEL=t  WIN32=1 %1 %2 %3 %4 %5 %6
make MODEL=t  WIN32=1 DLL=1 OWLVER=52 OWLNAME=OWL  %1 %2 %3 %4 %5 %6
