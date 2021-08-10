Copyright Borland International
ObjectWindows (C) 1995

Title: DRAGLIST Example

Keywords: TDragList;TDragListEventHandler


This sample illustrates how to use the TDragList class which provides
the programer with a draggable listbox. The sample creates a main window 
that has five children: a static control, two draggable listboxes
and two radio buttons.  The example derives a class TExampleDragList from 
TDragList to implement its features.


The static control displays information about the program as you are
dragging items around.


The draggable listboxes contain several text items. The first item
cannot be dragged nor can it be dropped on. This is implemented by
handling the virtual functions BeginDrag(), Dragging() and Dropped in 
TExampleDragList. The items can either be moved with in the one listbox, 
copied over to the other listbox or moved to the other listbox.  There 
are two radio buttons that will toggle between moving and copying between 
the list boxes.  The cursor will change to reflect moving or copying. 
Look in the Dragging() method to see how the cursor change is done.  Look 
in the Dropped() method to see how moving and copying is done.

To drag an item, click the left mouse button on the item and while
holding the left mouse button, move the mouse to the destination. When
you let go of the left mouse button, you drop the item. To cancel a
drag, you can either click the right mouse button or press the Esc key
while still holding the left mouse button.


Although this is not implemented in this example, general UI dictates that 
a regular drag moves the object. A ctrl-drag (i.e. holding the Ctrl key 
while dragging the mouse) copies the object.  A shift-drag (i.e. holding 
the shift key while dragging the mouse) extends selection. Note that dragging 
and selecting items can be confusing to the user. Try not to mix both 
metaphors.
