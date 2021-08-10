@echo off

REM -------------------------------------------------------------------------
REM  Explicitly remove environment variables which would be possibly
REM  (mis)interpreted by the MAKEFILE.GEN setup as build parameters.
REM -------------------------------------------------------------------------
set DEBUG=
set DIAGS=
set MODEL=
set SYSTEM=
set TARGET=

set BIDS_EX_ERR=

if /%MK%/ == // set MK=MAKE.EXE

cd labels
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd lookup  
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd pstream
%MK% %1 %2 %3 %4
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd queuetst
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd reverse
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd strngmax
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd testdir
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd todo
%MK% %1 %2 %3 %4
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd xref
%MK% %1 %2 %3 %4 MODEL=m
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

REM Build bidsapi examples
cd BIDSAPI

cd arrays
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd assocs
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd bags
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd bintrees
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd dates
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd deques
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd hashtbls
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd lists
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd queues
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd sets
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd stacks
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd streams
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd threads
%MK% %1 %2 %3 %4 -DCON32 MODEL=f
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

cd vectors
%MK% %1 %2 %3 %4 MODEL=l
if errorlevel 1 set BIDS_EX_ERR=1
cd ..

REM Back to examples from BIDSAPI
cd..

if /%BIDS_EX_ERR%/ == //  echo Build succeeded!
if /%BIDS_EX_ERR%/ == /1/ echo Build failed!


:END

