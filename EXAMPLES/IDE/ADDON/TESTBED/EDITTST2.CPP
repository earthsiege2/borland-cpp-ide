/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  edittst2.cpp
  Created: 03/11/95
  Copyright (c) 1996, Borland International
  $Revision:   1.2  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "edittst2.h"

//.............................................................................
EditTestC::EditTestC()
{
  _editServer = NULL;

}
//.............................................................................
EditTestC::~EditTestC()
  {
  UnInit();
  }
//.............................................................................
BOOL EditTestC::Init()
{
  if ( !_editServer )
  {
   OutStr( "EditTestC::Init()" );
   _editServer = GET_INTERFACE(IEditorServer);
   if ( _editServer == NULL )
   {
    return FALSE;
   }
  }
  bid = -1;
  return TRUE;
}
//.............................................................................
void EditTestC::UnInit()
  {
  OutStr( "EditTestC::UnInit()" );
  if ( _editServer )
   {
   _editServer->Release();
   _editServer = NULL;
   }
  }
//.............................................................................
const char * EditTestC::GetName()
  {
  return "Editor Test A";
  }
//.............................................................................
const char * EditTestC::GetTestDescription( int testNum )
  {

  switch ( testNum )
   {
   case 1:
    return "Insert some lines into a buffer";
   case 2:
    return "Insert a new line of text below current cursor position";
   case 3:
    return "Move first line of buffer to the end of the buffer";
   case 4:
    return "Insert a new line of text 3 lines below current cursor";
   default:
    return "This test not implemented.";
   }
  }
//.............................................................................
void EditTestC::DoTest( int testNum )
  {
  if ( !_editServer )
   {
   OutStr( "Editor Server not initialized!" );
   return;
   }
  
  switch ( testNum )
  {
   case 1:
   {
    /* This test uses an existing edit buffer or, if one doesn't exist,
      it creates one.  The buffer to be used is given focus using the
      set_buffer and show_buffer methods and then a line of text and a
      carriage return/newline are inserted at the beginning of the buffer.
      The cursor is then moved back up to the beginning of the inserted line
      of text.  At the end of this test the cursor is on the first column of
      the line in which the "This line has been..." has just been inserted.
     
     Methods used: begin_edit   end_edit   inq_buffer     create_buffer
              set_buffer    show_buffer beginning_of_line
              insert      up
    */ 
    
    IPolyString *insertString = ::MakePolyString( "This line has been inserted using the insert method.\r\n" );
    if (insertString != NULL)
    {
      _editServer->begin_edit();
      bid = _editServer->inq_buffer();
      if ( bid > 0 )
      {
        _editServer->beginning_of_line();
        _editServer->insert(insertString);
        _editServer->up();
        OutStr( FormatStr( "Text insert suceeded." ));
      }                  
      else
      {
        // There is not an edit buffer available so attempt to create one
        IPolyString *newEditFile = ::MakePolyString( "edittst2.out" );
        if (newEditFile != NULL)
        { 
          bid = _editServer->create_buffer( newEditFile, 0 );
          if ( bid > 0)
          {
            OutStr( FormatStr( "Created a Buffer.  Bid is %d", bid ));
            _editServer->set_buffer( bid );
            _editServer->show_buffer();
            _editServer->beginning_of_line();
            _editServer->insert(insertString);
            _editServer->up();
            OutStr( FormatStr( "Text insert suceeded." ));
          }
          else
            OutStr( FormatStr( "Failure to find or create an edit buffer." ));
        }
        else
          OutStr( FormatStr( "Failure to make polystr" ));
      }
      _editServer->end_edit();
    }
    else
      OutStr( FormatStr("Failure to make a polystr."));
    break;
   }

   case 2:
    /* This test uses the edit buffer that was used in Test 1. The buffer to
      be used is given focus using the set_buffer and show_buffer methods
      and then a line of text is inserted on the line immediately below
      the current cursor location and the cursor is set to the end of the
      line that has just been insterted. In order for the line of text to be
      inserted a line must already exist below the current cursor.  Otherwise
      the message "Could not go down a line." appears in the Output box of
      the BCW Add-on Tester window.
     
     Methods used: begin_edit   end_edit   set_buffer   show_buffer
              beginning_of_line      insert     down
    */ 
   {
    _editServer->begin_edit();
    if ( bid > 0 )
    {
      OutStr( FormatStr( "Test 2:  Bid is: %d.", bid) );
      _editServer->set_buffer( bid );
      _editServer->show_buffer();
      if ( _editServer->down() )
      {
        IPolyString *insertString = ::MakePolyString( 
          "This line has been inserted below the (formerly) current cursor.\r\n" );
        if (insertString != NULL)
        {
          _editServer->beginning_of_line();
          _editServer->insert(insertString);
          OutStr( FormatStr( "Text insert suceeded." ));
        }                  
        else
          OutStr( FormatStr( "Failure to make a polystr." ));
      }
      else
        OutStr( FormatStr( "Could not go down a line." ) );
    }
    else
      OutStr( FormatStr( "Failure to find the edit buffer used in Test 1." ));
    _editServer->end_edit();
   }
   break;

   case 3:
   {
    /* This test uses the edit buffer that was used in Test 1. The buffer to
      be used is given focus using the set_buffer and show_buffer methods
      and then the first line of text in the buffer is deleted and then
      inserted as the last line of the buffer. there must be at least two
      lines of text in the buffer for this test to be effective.  If there
      isn't the message "Must be at least two lines in buffer." appears in
      the Output box of the BCW Add-on Tester window.
     
     Methods used: begin_edit       end_edit         set_buffer
              show_buffer      top_of_buffer      end_of_buffer
              inq_line_length   beginning_of_line  end_of_line
              up             down           read
              delete_line      insert
    */ 
    _editServer->begin_edit();        
    if ( bid > 0 )
    {
      _editServer->set_buffer( bid );
      _editServer->show_buffer();
      _editServer->top_of_buffer();
      // We're on the first line.  Is there another line?
      if (_editServer->down())
      {
        _editServer->up();

        /* 
          The default behavior of the read method is to read up to and
          including the end-of-line characters if the number of characters
          to be read is to provided.  In this case we don't what to have
          a new line added to the end of the buffer so to get around this,
          use inq_line_length.  This method will return the number of 
          characters in the give line NOT INCLUDING the end-of-line
          characters.  Then use the value returned by inq_line_length in
          the call to the read method and you have the line without the
          end-of-line stuff.
        */
        int nLineLength = _editServer->inq_line_length();
        OutStr( FormatStr ( "nLineLength is %d.", nLineLength ));
        IPolyString *chars = _editServer->read(nLineLength);
        
        _editServer->delete_line();
        _editServer->end_of_buffer();
        // if the last line in the buffer is not blank...
        if (_editServer->inq_line_length())
        {
          _editServer->end_of_line();
          IPolyString *crNl = ::MakePolyString("\r\n");
          _editServer->insert( crNl );
        }
        _editServer->insert( chars );
      }
      else
        OutStr( FormatStr ( "Must be at lest two lines in buffer." ));
    }
    else
      OutStr( FormatStr( "Failure to find the edit buffer used in Test 1." ));
    _editServer->end_edit();
   }
   break;


   case 4:
   {
    /* This test uses the edit buffer that was used in Test 1. The buffer to
      be used is given focus using the set_buffer and show_buffer methods.
      Once the buffer has focus then the cursor is moved three lines down
      from it's current position and a new line of text is entered.
     
     Methods used: begin_edit       end_edit         set_buffer
              show_buffer      top_of_buffer      end_of_buffer
              inq_position      goto_line
    */ 

    long line;
    
    _editServer->begin_edit();

    /* Insert a new line of text 3 lines below current cursor */
    if ( bid > 0 )
    {
      _editServer->set_buffer( bid );
      _editServer->show_buffer();
      _editServer->inq_position( &line );
      // goto the beginning of the third line down
      if ( _editServer->goto_line( line + 3 ) )
      {
        IPolyString *insertString = ::MakePolyString( "This line has been inserted three lines below the (formerly) current cursor.\r\n" );
        if (insertString != NULL)
        {
          _editServer->insert(insertString);
          OutStr( FormatStr( "Text insert suceeded." ));
        }
        else
          OutStr( FormatStr( "Failure to make polystr" ));
      }
      else
        OutStr( FormatStr( "Too close to the end of the file.") );
    }
    else
      OutStr( FormatStr( "Failure to find the edit buffer used in Test 1." ));
    
    _editServer->end_edit();
    break;
   }
    
   default:
    OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
  }
}
