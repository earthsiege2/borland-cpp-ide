@echo off

rem  This batch file will make the directories necessary to build the
rem  16-bit libraries.

md lib
md log
md clib
for %%m in (s m c l h d) do md clib\%%m
for %%m in (s m c l)   do md clib\w%%m
md winlib
for %%m in (s m c l d) do md winlib\%%m
md startup
md rtlinc
md iostream
for %%m in (s m c l h d) do md iostream\%%m
for %%m in (s m c l)   do md iostream\w%%m
md math
for %%m in (s m c l h d) do md math\%%m
for %%m in (s m c l  ) do md math\w%%m
md emu
md RTLSRC
