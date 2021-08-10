Copyright Borland International
ObjectWindows (C) 1995

Title: Button Example

Keywords: TButton;TRadioButton;TCheckBox;TGroupBox notifications

The BUTTON sample application illustrates how to create PushButtons,
CheckBoxes, RadioButtons and GroupBoxes at runtime. The sample also
illustrates an enhancement provided by the ObjectWindows Library:
GroupBox notifications. The following sections describe the BUTTON
sample and GroupBox notifications.


[Sample Overview]

The BUTTON sample is a simple SDI application. The client window,
derived from TWindow creates several controls and provides message
handlers to handle notifications from the controls.


[GroupBox Notifications]

GroupBoxes provide a visual interface for grouping controls such as
CheckBoxes or RadioButtons. From a programming standpoint, however,
the individual controls within a groupbox communicate directly to
their parent window via notification messages. This requires that a
program provides handlers for each control within the GroupBox.
ObjectWindows allows you to provide a single handler which is
notified whenever the state of a CheckBox or RadioButton within the
GroupBox changes.


If a GroupBox pointer is specified when creating a CheckBox or
RadioButton object (i.e. TCheckBox or TRadioButton), the latter will
invoke the 'SelectionChanged' method of the TGroupBox when its state
changes. In turn, the 'SelectionChanged' method of the Groupbox sends
a notification message to the parent window. This mechanism allows an
application to detect changes in checkboxes or radiobuttons by simply
handling the notification relayed by the GroupBox. The BUTTON sample
illustrates this technique with the EV_CHILD_NOTIFY_ALL_CODES macro
and the 'HandleGroupBoxMsg' handler.
