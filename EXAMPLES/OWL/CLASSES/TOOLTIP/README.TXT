ObjectWindows 
Copyright (c) 1996 Borland International

Title: TOOLTIP Example

Keywords: TTooltip;Common control

TTooltip, An Introduction
=========================
The TTooltip class encapsulates a tooltip control - a small
pop-up window that displays a single line of descriptive text
giving the purpose of tools in an application. The tools is
either a window, such as a child window or control, or an
application-defined rectangular area within a window's client
area. The tooltip control appears only when the user puts the
cursor on a tool and leaves it there for approximately one-half
second. The tooltip control appears near the cursor and
disappears when the user clicks a mouse button or move the
cursor off the tool.


Creating a TTooltip Object
==========================
The TTooltip class offers two constructor: one for creating a
brand new tooltip control and one for aliasing an existing
control. The following code fragment illustrates how to create a
tooltip control.

    void TMyWindow::SetupWindow()
    {
        TWindow::SetupWindow();

        tooltip = new TTooltip(this);
        tooltip->Create();
    }
        

Specifying Tools to the tooltip Control
======================================= 
Once you created a tooltip, you must specify the tools for which
the control must display a descriptive message. To add a new
tool you must first fill a TToolInfo which describes the tool.
Each tool must have a integer which uniquely identifies that
tool.  For example, the following code designates a rectangular
area of a window as a tool.

    void
    TMyWindow::AddTopLeftTool()
    {
        uint toolId = ID_TOPLEFT_TOOL;      // Tool ID
        TRect rect(0, 0, 20, 20);           // Tool Rectangle
        TToolInfo ti(this, rect, ID_TOPLEFT_TOOL);
        tooltip->AddTool(ti);
    }


Providing the Tooltip Text 
========================== 
When adding a tool you may provide the text to be used when
describing the tool as the last parameter to the constructor of
the TToolInfo structure. For example,

        static TToolInfo ti(this, rect, ID_TOPLEFT_TOOL, "Top Left");
        tooltip->AddTool(ti);

However, you may opt to provide the text on demand. This allows
you to customize the message display to the user. The
EV_TTN_NEEDTEXT macro allow you to specify a member function
which can provide the text at runtime. The following code
snippet illustrates:
  
    class TMyWindow : public TWindow {
        //
        // Additional definition ommitted for clarity
        //
        protected:
            void    HandleTooltipText(TTooltipText& tiTxt);
    };

    DEFINE_RESPONSE_TABLE1(TMyWindow, TWindow)
        EV_TTN_NEEDTEXT(ID_TOPLEFT_TOOL, HandleTooltipText),
    END_RESPONSE_TABLE;


    void
    TMyWindow::HandleTooltipText(TTooltipText& tiTxt)
    {
        tiTxt.CopyText("Top Left square");
    }


Additional Information
======================
1. The notification handler of the ObjectWindows TDecoratedFrame
class enhances the mechanism for specifying the tooltip text by
sending a 'TTooltipEnabler' up the command chain. This allows
the 'context' window to provide the text even if it did not
setup the tool. For example, a grid control in focus can
customize the cut, paste and copy tools to specify the data type
being manipulated. ['copy cell' instead of just 'copy'].

2. The EvCommandEnable handler of TDecoratedFrame attempts to
provide the tooltip text by looking in two locations:

(a) First the window's menu is scanned for a menuitem with an id
corresponding to that of the tool. If found, the menustring is
provided.

(b) Next, TDecoratedFrame attempts to load a string resource
with an id corresponding to that of the tool. If found, the
string is scanned for a line-feed character. If successful,
TDecoratedFrame provides the string following the line-feed as
tooltip text.

NOTE: You should structure you hint text string using the
following format:
 <string to be displayed on statusbar>\n<tooltip hint text>

See the STRING TABLE in the .RC file of this example for more
information.



