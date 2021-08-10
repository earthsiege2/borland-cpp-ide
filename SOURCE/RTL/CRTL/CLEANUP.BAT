rem  This batch file deletes the objects built for
rem  the 16-bit libraries.

del lib < yes.txt
del log < yes.txt
del clib\d < yes.txt
for %%m in (s m c l h)   do call xxdel clib\%%m
for %%m in (s m c l)     do call xxdel clib\w%%m
del winlib\*.lib < yes.txt
for %%m in (s m c l d)   do call xxdel winlib\%%m
for %%m in (s m c l h d) do del iostream\%%m < yes.txt
for %%m in (s m c l)     do del iostream\w%%m < yes.txt
for %%m in (s m c l h d) do del math\%%m < yes.txt
for %%m in (s m c l  )   do del math\w%%m < yes.txt
