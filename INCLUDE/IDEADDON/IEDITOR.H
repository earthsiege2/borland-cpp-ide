/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

   ieditor.h
   Created: 09/18/95
   Copyright (c) 1995, Borland International
   $Header:   Y:/ADMIN/BRIDE/ADDON/DELIVER/INTERFAC/IEDITOR.H_V   1.21   15 Jan 1997 10:53:22   JDOUGLAS  $
   $Revision:   1.21  $

   IDEHOOK-style editor interface

   IDEHOOK CHANGES (overview, see individual methods for specifics)
   ---------------

      register_keyhit_handlers()
      --------------------------
      This is now obsolete. The same functionality
      can and should be implemented through script, since all key handlers,
      even those being used by the internal IDE clients, are now script-based.
      Use the IScriptServer interface to run a script or script command that
      works with the following classes and methods to set up keyboard handling:

         KeyboardManager::GetKeyboard()
         Keyboard::Assign()

      Consult the cScript reference for more information regarding keyboard
      handling.

      free_string()
      -------------
      Since we're now using IPolyString *'s, there is no longer a need for this 
      method, follow normal reference counting rules and Release() the poly
      string when you're done with it.

      New Methods
      -----------
      undo_available()
      undo()
      redo_available()
      redo()

      return values
      -------------
      Several return values have been more clearly defined to return 1 for 
      success and 0 for failure. These changes don't reflect any actual 
      difference in the return values except where specifically noted in 
      the individual method descriptions.
      
    Methods by Category
    ------------------
    Transaction Bracketing:
    	begin_edit()			  
		end_edit (void)		  

    Cursor Movement Methods
    	beginning_of_line()			
		end_of_line()					
		down()							
		goto_line()		
		goto_old_line() 
		left()							
		move_abs()
		move_rel()
		next_char()
		prev_char()
		right()
		up()	 
		top_of_buffer()
		end_of_buffer()

	Block Methods
		drop_anchor()
		raise_anchor()
		delete_block()

	Editting Methods
		backspace()
		delete_char()
		delete_line()
		delete_to_eol()
		insert()
		translate()
		undo_available()
		undo()
		redo_available()
		redo()
      
	Buffer/View Methods 
   Note: View-related results are based on and reflected in the top view of 
   the buffer set with set_buffer.
		create_buffer()
		delete_buffer()
		distance_to_tab()
		inq_buffer()
		inq_line_length()
		inq_modified()
		inq_names()
		inq_position()
		inq_views()
		next_buffer()
		read()
		read_file()
		refresh()
		save_buffer()
		search_back()
		search_fwd()
		set_buffer()
		set_top_left()
		show_buffer()
		top_of_window()
		end_of_window()
		page_down()
		page_up()  
      reload_buffer()
      

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef _IEDITOR_H_
#define _IEDITOR_H_

#include <objbase.h>
#include <ideaddon\IPolyStr.h>
#include	<ideaddon\IEditor.uid>
#include <ideaddon\common.h>

typedef DWORD BufferId;

//.............................................................................
enum MarkType
{
   MT_Normal = 1,
   MT_Column = 2,
   MT_Line = 3,
   MT_Noninclusive = 4
};


//.............................................................................
class IEditorServer : public IUnknown 
{
 public:

	//
	// Always bracket an editing "session" on a particular buffer with 
	// begin_edit() and end_edit().
   // 
   // In other words, if you are going to use one or more edit functions 
   // on one buffer inside a routine, start with begin_edit(), use any of the 
   // other functions to do what you need to do, then call end_edit() when 
   // you're done. begin_edit() and end_edit() should surround the edits
   // to a single buffer only. You should only call set_buffer() after having
   // called begin_edit().
   //
   // Here is an example of correct begin/end usage when iterating over 
   // all open buffers
   //
   //      IEditorServer * editor = GET_INTERFACE( IEditorServer ); 
   //      BufferId buf = editor->inq_buffer();
   //      BufferId firstBuf = buf;
   //      if ( buf ) {
   //         do {
   //            editor->begin_edit();
   //            editor->set_buffer( buf );
   //            //
   //            // do stuff to the edit buffer...
   //            //
   //            editor->end_edit();
   //            buf = editor->next_buffer();
   //         } while ( buf != firstBuf );
   //      }
   //      editor->Release();
   //
   // 
   
	virtual void BCWADDON_CMETHOD begin_edit (void) = 0;
	virtual void BCWADDON_CMETHOD end_edit (void) = 0;

   // 
   // Moves the cursor to the first character of the current line
   // Returns 1 when successful, else 0
   //
   virtual int BCWADDON_CMETHOD beginning_of_line() = 0;

   //
   // Moves the cursor to the previous character on the current line and 
   // deletes it.
   // Returns 1 when successful, else 0
   //
   virtual int BCWADDON_CMETHOD backspace() = 0;

   //
   // Creates a buffer containing an existing or new file.
   // 'system' should be set to 1 to create a system buffer
   //    - system buffers don't support undo, are not seen by the user
   //      and can't be compiled. These are handy for saving a safety
   //      a copy of a buffer before making masive changes.
   // 
   // Returns the BufferId or zero if unsuccessful.
   // 
   // IDEHOOK CHANGES:
   //    - Since 'buffer_name' was ignored, we've removed it.
   //    - the 'system' flag was not previously supported.
   //    - File name is now a IPolyString *.
   // 
   virtual BufferId BCWADDON_CMETHOD create_buffer( IPolyString * file_name, int system ) = 0;

   //
   // Deletes the marked block (if there is one) in the current buffer.
   // Returns 1 if successful, else 0.
   //
   virtual int BCWADDON_CMETHOD delete_block() = 0;

   //
   // Deletes a buffer from memory if there are no windows containing
   // views on the buffer.
   // Returns 1 if successful, else 0.
   // 
   virtual int BCWADDON_CMETHOD delete_buffer( BufferId buffer_id ) = 0;

   //
   // Deletes one or more characters at the current position.
   // Returns 1 when successful, else 0
   //
   virtual int BCWADDON_CMETHOD delete_char( int num_to_delete = 1 ) = 0;

   //
   // Deletes the current line.
   //
   virtual void BCWADDON_CMETHOD delete_line() = 0;

   //
   // Deletes from the current position to the end of the current line.
   //
   virtual void BCWADDON_CMETHOD delete_to_eol() = 0;

   //
   // Returns the number of columns between the current position and the next
   // tab stop.
   //
   virtual long BCWADDON_CMETHOD distance_to_tab() = 0;

   //
   // Moves the current position one line down.
   // Returns 1 if the position changed, else 0.
   //
   virtual int BCWADDON_CMETHOD down() = 0;

   //
   // Starts marking a block at the current position in the current buffer.
   // The mark types match the original brief mark types and are consistent
   // with IDEHOOK (see the MarkType enum above).
   //
   virtual void BCWADDON_CMETHOD drop_anchor( MarkType mark_type = (MarkType) 1 ) = 0;

   //
   // Moves to the last character in the current buffer.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD end_of_buffer() = 0;

   //
   // Moves to the last character on the current line.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD end_of_line() = 0;

   //
   // Moves to the last line of the current window.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD end_of_window() = 0;

   //
   // Moves the cursor to the beginning of a specific line.
   // Returns 1 if successful, else 0.
   //
   virtual int BCWADDON_CMETHOD goto_line( long line ) = 0;

   //
   // Moves the cursor as close as possible to a line in the original,
   // unchanged file that is associated with the current buffer.
   // Returns 1 if successful, else 0.
   // 
   // IDEHOOK_CHANGES:
   //    - The original BRIEF doc states that the return from this function
   //      will be zero or less if unsuccesful and, in fact, the return from 
   //      this method used to be -1 when unsuccesful. Since this is in-
   //      consistent with most of the other return values, it has been 
   //      changed to return 0 if unsuccessful.
   //
   virtual int BCWADDON_CMETHOD goto_old_line( long line ) = 0;

   //
   // Returns a buffer identifier associated with the current buffer,
   // in which case 'filename' should be NULL, or that of the buffer 
   // specified by 'filename'.
   // 
   // IDEHOOK CHANGES:
   //    - fileName is now a IPolyString *
   //
   virtual BufferId BCWADDON_CMETHOD inq_buffer( IPolyString * fileName = NULL ) = 0;

   //
   // Returns the length of the current line in characters.
   //
   virtual int BCWADDON_CMETHOD inq_line_length() = 0;

   //
   // Returns the modification status of the current buffer.
   // 
   // Returns values: 
   //   -1 if current buffer not found
   //    0 if not modified 
   //    1 if modified
   //
   virtual int BCWADDON_CMETHOD inq_modified() = 0;

   //
   // Returns one or more strings associated with the current buffer:
   //    full_name: File name with path and drive letter
   //    extension: only the extension part of the file name
   //    buffer_name: file name without the path
   // 
   // Pass in NULL for args you don't care to receive.
   // Otherwise, use CreatePolyString() to get a pointer to an uninitialized
   // poly string and pass a pointer to it to the arg, or pass a pointer to
   // a NULL IPolyString pointer.
   // In either case, you'll want to call Release() on the returned poly string 
   // when you're done with it.
   // 
   // IDEHOOK CHANGES:
   //    - String arguments are now all pointers to IPolyString *'s
   //
   virtual void BCWADDON_CMETHOD inq_names(    IPolyString * * full_name = NULL, 
                              IPolyString * * extension = NULL, 
                              IPolyString * * buffer_name = NULL ) = 0;

   //
   // Returns zero if the current position is not past the end-of-buffer.
   // Else, returns the number of lines between the end-of-buffer and the 
   // current position.
   // Line number and column are optionally returned in the 'line' and 'col' 
   // arguments.
   //
   virtual int BCWADDON_CMETHOD inq_position( long * line = 0, long * col = 0 ) = 0;

   //
   // Returns the number of windows that are viewing either the current
   // or specified buffer.
   //
   virtual int BCWADDON_CMETHOD inq_views( BufferId buffer_id = 0 ) = 0;

   //
   // Inserts 'string' into the current buffer
   // 
   // IDEHOOK CHANGES:
   //    - the string arg is now a IPolyString *
   //
   virtual void BCWADDON_CMETHOD insert( IPolyString * string ) = 0;


   //
   // Moves the current position one column left.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD left() = 0;

   //
   // Move to the line/column specified.
   // If zero is used for either arg, then the current position is used for
   // that argument.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD move_abs( long line = 0, long column = 0 ) = 0;

   //
   // Move to the relative line/column position specified.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD move_rel( long num_lines = 0, long num_columns = 0 ) = 0;

   //
   // Returns the BufferId for the next buffer.
   // 
   // IDEHOOK CHANGES:
   //    - the 'system_too' parameter was and will not be supported, so we've
   //      removed it. (note: verified by looking in ferengi's 
   //      ide\idecommon\ideedit.cpp implementation of this).
   //
   virtual BufferId BCWADDON_CMETHOD next_buffer() = 0;

   //
   // Moves the current position to the next character, wrapping to the
   // next line where appropriate. Optionally moves by 'num_chars' characters.
   // 
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD next_char( int num_chars = 1 ) = 0;

   //
   // Moves the cursor position down by one page.
   //
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD page_down() = 0;

   //
   // Moves the cursor position up by one page.
   //
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD page_up() = 0;

   //
   // Moves the current position to the previous character, wrapping to the
   // previous line where appropriate. Optionally moves by 'num_chars' 
   // characters.
   // 
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD prev_char( int num_chars = 1 ) = 0;

   //
   // Raises the last mark that was dropped with drop_anchor().
   //
   virtual void BCWADDON_CMETHOD raise_anchor() = 0;

   //
   // Reads characters from the current buffer.
   // If 'length' is specified, reads 'length' number of chars, including
   // end-of-line chars. Otherwise, reads from the current position through
   // the end-of-line. The current position remains unchanged.
   // 
   // IDEHOOK CHANGES:
   //    - Returns a IPolyString * instead of a char *, therefore the 'free_string()'
   //    method no longer exists and the caller should free the string using 
   //    SysFreeString().
   //
   virtual IPolyString * BCWADDON_CMETHOD read( int length = 0 ) = 0;

   //
   // Reads a copy of the file into the current buffer.
   // 
   // Returns 0 if the command failed, else 1.
   //
   // IDEHOOK CHANGES:
   //    - 'filename' is now a IPolyString * instead of a char *
   //    - Used to return -1 on failure. Changed in the interest of 
   //      consistency with other methods.
   // 
   virtual int BCWADDON_CMETHOD read_file( IPolyString * filename ) = 0;

   //
   // Redraws the current buffer
   //
   virtual void BCWADDON_CMETHOD refresh() = 0;

   //
   // Moves the current position one column to the right.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD right() = 0;

   //
   // Saves the current buffer to disk (this is a quiet save).
   // 
   // Returns zero for failure, 1 for success.
   // 
   // IDEHOOK CHANGES:
   //    - write_buffer() is now obsolete, use this instead
   //
   virtual int BCWADDON_CMETHOD save_buffer() = 0;

   //
   // Searches the current buffer (back and forward methods). 
   // 
   // 'pattern': a string containing the pattern to search for
   // 'regularExp': turn regular expression searching on (non-zero) or off (0)
   // 'caseSen': turn case sensitivity on (non-zero) or off (0)
   // 'block': confine the search to the current block (non-zero)
   // 
   // Returns zero if not found, otherwise the text length
   // 
   // IDEHOOK_CHANGES:
   //    (the following don't represent any change in behavior or capabillity)
   //    - 'pattern' is now a IPolyString *
   //    - 'grep' has been dropped, and was not previously supported
   //    - 'total_length' has been dropped and is now returned, this differs
   //       from the original implementation in that (length + 1) used to be 
   //       returned unless it was greater than 65,534, etc...
   //
   virtual int BCWADDON_CMETHOD search_back(   IPolyString * pattern,
                              int regularExp = 1,
                              int caseSen = 1,
                              int block = 0 ) = 0;

   virtual int BCWADDON_CMETHOD search_fwd(    IPolyString * pattern,
                              int regularExp = 1,
                              int caseSen = 1,
                              int block = 0 )= 0;


   //
   // Makes the specified buffer current.
   // 
   // Returns the previously current BufferId.
   //
   virtual BufferId BCWADDON_CMETHOD set_buffer( BufferId buffer_id ) = 0;

   //
   // Sets the upper left corner of the current buffer to the line and/or 
   // column specfied. 
   //
   // IDEHOOK CHANGES:
   //    - 'window_id', 'line', 'col', and 'buffer_id' were all previously
   //       ignored. They have been removed in the interest of clarity.
   // 
   virtual void BCWADDON_CMETHOD set_top_left( long top_line, long left_col ) = 0;
   
   //
   // Moves an MDI window on the current buffer to the top of the window
   // stack. If no such window exists, one is created.
   //
   virtual void BCWADDON_CMETHOD show_buffer() = 0;
   
   //
   // Moves the current position to the first character in the current buffer.
   //
   // Returns 1 if the position has changed, else 0.
   // 
   virtual int BCWADDON_CMETHOD top_of_buffer() = 0;

   //
   // Moves the current position to the top line of the current window.
   // 
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD top_of_window() = 0;

   //
   // Translates occurrences of a specified pattern to a replacement string.
   //
   // 'pattern': a string containing the pattern to search for
   // 'replacement': the replacement string
   // 'global_flag': translate all (non-zero) or first-only (0) occurances
   // 'regularExp': turn regular expression searching on (non-zero) or off (0)
   // 'caseSen': turn case sensitivity on (non-zero) or off (0)
   // 'block': confine the search to the current block (non-zero)
   // 'forward': search forward (non-zero) or backward (0)
   // 
   // Returns the number of translated occurences.
   // 
   // IDEHOOK_CHANGES:
   //    - 'pattern' and 'replacement' are now IPolyString *'s
   //    - 'grep' has been dropped, and was not previously supported
   //
   virtual int BCWADDON_CMETHOD translate(  IPolyString * pattern,
                           IPolyString * replacement,
                           int global_flag,
                           int regularExp = 1,
                           int caseSen = 1,
                           int block = 0,
                           int forward = 1 ) = 0;


   //
   // Moves the current position one line up.
   // Returns 1 if the position has changed, else 0.
   //
   virtual int BCWADDON_CMETHOD up() = 0;

   //
   // Returns TRUE if the current buffer currently supports a call to undo().
   //
   virtual BOOL BCWADDON_CMETHOD undo_available() = 0;
   //
   //
   // Performs an undo on the current buffer.
   // Returns 1 for success, 0 for failure.
   //
   virtual void BCWADDON_CMETHOD undo() = 0;
   //
   //
   // Returns FALSE if the current buffer currently supports a call to redo().
   //
   virtual BOOL BCWADDON_CMETHOD redo_available() = 0;
   //
   //
   // Performs a redo on the current buffer.
   // Returns 1 for success, 0 for failure.
   //
   virtual void BCWADDON_CMETHOD redo() = 0;

};

class IEditorServer2 : public IEditorServer
{
 public:
   // Reloads a buffer from disk, without asking the user whether to
   // overwrite the currently loaded buffer.
   //
   // Returns zero for failure, 1 for success.
   //
   virtual int BCWADDON_CMETHOD reload_buffer(BufferId buffer_id) = 0;

};

#endif



