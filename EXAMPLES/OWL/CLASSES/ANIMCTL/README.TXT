ObjectWindows 
Copyright (c) 1996 Borland International

Title: ANIMCTL EXAMPLE

Keywords: TAnimateCtl;Common Control

TAnimateCtrl, an Introduction
=============================
TAnimateCtrl encapsulates the animation control fo the Common
Control library. The control is a window that silently displays
an AVI (Audio Video Interleaved) clip. 
NOTE: The animation control can only play silent clips from an
uncompressed .AVI file or from an .AVI file that was compressed
using run-length encoding (RLE).


Creating a TAnimateCtrl Object
==============================
TAnimateCtrl provides two constructors:
  1. TAnimateCtrl(parent, id, x, y, w, h, module);
  2. TAnimateCtrl(parent, resourceId, module);

The first one can be used to create a brand new control. For
example, you may use the following syntax within the constructor
of a parent window:

    TClientWindow::TClientWindow(TWindow* parent) : TWindow(parent)
    {
        AnimateCtrl = new TAnimateCtrl(this, 0x100, 5, 10, 50, 60);
    };

The above snippet instruct ObjectWindows to create an animation
control with the ID of 0x100, at location (5,10), 50 pixels wide
and 60 pixels high within the client area of the TClientWindow
window.

The other constructor of the TAnimateCtrl class is used to alias
an animation control which is part of a dialog resource. The following
resource definition illustrates a dialog containing an animation
control:

IDD_ANIMATE DIALOG 45, 56, 176, 99
STYLE DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU
CAPTION "Animation Dialog"
{
 CONTROL "Sample_Avi", IDC_ANIMATE, "SysAnimate32", ACS_CENTER | ACS_TRANSPARENT | WS_CHILD | WS_VISIBLE | WS_BORDER, 16, 10, 145, 61
}

The following snippet illustrates how to alias an animation
control within a TDialog-derived class' constructor:

    TAnimDialog::TAnimDialog(TWindow* parent, TResId res) 
                :TDialog(parent, res)
    {
        AnimCtrl = new TAnimateCtrl(this, IDC_ANIMATE);
    }


Using the TAnimateCtrl Object
=============================
After creating an animation control you can invoke the 'Open'
method to open an AVI clip and load it in memory. The following
code illustrates:

  AnimateCtrl->Open(MAKEINTRESOURCE(SAMPLE_ONE));

NOTE: The parameter to the 'Open' method can contain the path to
an .AVI file or the name of an AVI resource.

The 'Play' method of TAnimateCtrl plays the current AVI clip in
the animation window. Note that the control plays the clip in
the background while the thread continues executing.

The 'Seek' method allows you to seek to a particular frame of
the current .AVI clip while the 'Stop' method stops playing any
.AVI clip.


Additional Information
======================
1. The specified caption of the control may contain the name of
an .AVI resource to be opened automatically be the control.

2. Passing '-1' as the third argument to the 'Play' method
instructs the control to replay the clip indefinitely.

