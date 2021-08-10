Copyright Borland International
ObjectWindows (C) 1996

Title: CMDENABL Example

Keywords: TCommandEnabler;How to enable and disable commands

The CMDENABL example illustrates how to use the TCommandEnabler class.
TCommandEnabler class allows you to enable and disable commands.
Commands are either menu items or they can be buttons on a control bar.
Starting with OWL 5, you can enable and disable controls on a dialog.


TCommandEnablers require a change in thinking about enabling and
disabling commands. Rather than explicitly putting statements in your
application to enable and disable commands, OWL will routinely ask your
application if it should enable or disable the command. In addition to
enabling and disabling commands, you can also use the command enabler to
check a menu item or set its text.

