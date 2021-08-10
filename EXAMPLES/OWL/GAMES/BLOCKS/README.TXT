
Turbo Blocks is played on a 10x20 grid.  Blocks of various shapes fall from 
the top of the grid.  They stop when they hit the bottom of the grid, or
another block.  Blocks can be moved left/right (using the arrow keys),
or rotated (with the spacebar).  If an entire row of the game grid is
filled, it will disappear, and the remaining blocks will drop down to
fill in the space.  The object is to continue the game without letting
the blocks reach the top of the grid.

The following options may be set in the BLOCKS.INI file:

[blocks]
gamespeed=10
blocksize=20

GAMESPEED will adjust the speed of the game.  Smaller numbers result
in a faster game.

BLOCKSIZE will adjust the size of the game window.  This specifies the
size of each block, in pixels.


The following features were not implemented, and are left as an exercise
to the user:

  - score
  - level count
  - line count
  - display of the next block that will appear



