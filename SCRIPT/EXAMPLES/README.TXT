cSCRIPT EXAMPLES
----------------

Contents
--------
I. "Installation" of example scripts.
II. Example script descriptions.


I. "Installation" of example scripts.
-------------------------------------
You can "install" the example scripts by choosing "Script | Install/Uninstall
examples." This loads, and causes to be loaded on start-up, the Script
Manager. The Script Manager is an example script for setting up and working
with scripts. It has a default configuration designed to make it easy for
you to explore the functionality the examples provide.

Once installed, you'll find selected scripts on the "Example scripts" menu.
Choose "Example scripts | Script directory" to see all the selected examples,
including those the Script Manager knows of but does not add to the menu.

You can customize the Script Manager and maintain it as a part of your IDE,
changing the scripts, the menus they are assigned to, their autoload statuses,
etc. Or you can remove it by choosing "Script | Install/Uninstall examples"
again. For more information about the Script Manager, see the entry below and
the file headers for SPPMAN.SPP and its related files.


II. Example script descriptions.
--------------------------------
The script examples directory contains the following scripts and script
applets:

SCRIPT MANAGEMENT
-----------------
SPPMAN.SPP	Script Manager. Allows you to specify scripts for
		autoloading, and add scripts to IDE menus. Provides a script
		directory showing script names, descriptions, and autoload
		and load statuses. The directory window lets you load and
		unload scripts, edit them in the specified editor, and edit
		the Script Manager data file.

LOADLAST.SPP	Load Last Script. Loads the last-loaded script. Useful for
		frequently reloading a script under development (before it
		is assigned to a hot key, menu, or some other quick trigger).

TEST.SPP	Test harness.


EDITING AND CODING
------------------
APIEXP.SPP	API Expander. Expands current word in editor to the matching
		Windows API or C RTL signiture. Provides selection list if
		seed string has multiple matches. If the match is an RTL
		member, API Expander indicates if the corresponding header
		file needs to be added to the source file.

CODELIB.SPP	Code Library. Displays libraries of code snippets you can
		insert in the current buffer. You can also edit code library
		data files, and create library entries from selected text.
		You can create as many code libraries as you want.

EDONLY.SPP	Edit-only. Temporarily shows only those lines in the current
		buffer that contain a specified string. Useful for seeing how
		an identifier is being used, making changes without searching
		and replacing, isolating strings for spell-checking, etc.

SHIFTBLK.SPP	Shift Block. Shifts the current block right or left a column
		at a time.

OPENHDR.SPP	Open Header. Opens the .h or .hpp file corresponding to the
		current source file. Optionally creates a header file if one
		does not exist.

FILEINSR.SPP	File Insert. Inserts a file into the current buffer.

ALIGNEQ.SPP	Align at Equals. Aligns a block of assignments by
		positioning the equals operators one space after the longest
		lvalue in the current block.

REVISIT.SPP	Code Revisit Tool. Quickly lists occurrences of a 
		configurable "revisit this code" marker in all files in the
		specified directory.

LONGLINE.SPP	Long Line Finder. Searches all .C, .H, .CPP, .HPP, and .SPP
		files in the specified directory and reports all lines that
		are longer than a given threshold value to the message
		database. Double-click a message to edit the referenced file.

FINDTABS.SPP	Find Tabs. Searches all .C, .H, .CPP, .HPP, and .SPP files
		in the specified directory and reports all lines that have
		at least one tab character to the message database. Double-
		click a message to edit the referenced file. Useful for
		coding styles that don't use tab characters.

EDITSIZE.SPP	Editor Size. Allows easy customization of editor window
		size and position without changing default values in
		startup.spp. Config.spp provides a different but more
		comprehensive approach to positioning IDE windows.

COMMENT.SPP	Commenter. "Comments-out" the selected block, or
		uncomments the lines if they are already commented.

SRCHALL.SPP	Search All. Searches and replaces across files in the
		current project.


DEBUGGING
---------
EVALTIPS.SPP	Evaluation Tips. When the debugger has a process loaded,
		evaluates the item under the cursor and displays the result
		in a mouse tip.

VIEWLOCS.SPP	View Locals. Inspects local variables if the debugger has
		a process. 


PROJECT MANAGEMENT
------------------
LOADPROJ.SPP	Load Project. Opens the last project on start-up.

PRJNOTES.SPP	Project Notes. For new projects, creates a notes text file
		in the project directory and adds it to the project. The
		notes file will contain any text found in a template file.


MISCELLANEOUS
-------------
FASTOPEN.SPP	Fast Open. Opens files and projects based on a search
		path, so you don't have to navigate directories.

AUTOSAVE.SPP	Autosave. Saves files, environment, desktop, project, and/or
		messages at the specified interval.

NETHELP.SPP	Internet Help. Open an URL with Netscape Navigator by
		selecting from a list of programming pages, FTP sites,
		and newsgroups.

SOUND.SPP	Sound Enabler. Plays WAV files on specified IDE events, such
		as Build Failure.

KEYASSGN.SPP	Key Assignments. Shows what commands are assigned to a given
		key sequence.

DIRTOOL.SPP	Directory Tool. Creates a new tool called "Directory
		Listing," which takes a filespec and generates a directory
		listing in the message window.

CONFIG.SPP	Configure Windows. Resizes and positions IDE windows as
		they are created. Also maps keys in the default and classic
		keyboards for buffer manipulation.

SUPPORT CLASSES AND ROUTINES
----------------------------
SORT.SPP	Sort. Quick Sort routines.

FOREACH.SPP	For Each. Calls a function for all the nodes of the given type
		in a project.

FILE.SPP	File Classes. Includes configuration file management.

MSG.SPP		Message Class. Provides methods to simplify and standardize
		user messages. Message captions automatically indicate the
		calling module.

MISC.SPP	Miscellaneous. Miscellaneous script.


DEMONSTRATION
-------------
INTNATL.SPP	International. Demonstrates the use of FormatString() for
		localization of strings in scripts.

CRTL.SPP	C RTL. Demonstrates script access to the C RTL by writing
		Albert's words to a file.

AUTO.SPP	Automation. Demonstrates the IDE as an OLE automation
		controller and server.

LIST.SPP	List Window. Demonstrates a simple sorted list window.

POPUP.SPP	Popup Window. Demonstrates a simple popup window.

MLIST.SPP	Multi-select List Window. Demonstrates a simple multiple-
		selection list window. Also shows how to position a popup
		window in the list.

MODLIST.SPP	Module List. Demonstrates how to handle events from
		other objects to maintain the contents of a list.
		Implements some of the functionality provided by the
		"Script | Modules" dialog.
