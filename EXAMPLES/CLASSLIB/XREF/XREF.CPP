/*------------------------------------------------------------------------*/
/*                                                                        */
/*  XREF.CPP                                                              */
/*                                                                        */
/*  Copyright (c) 1993 Borland International                              */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  Text cross referencing example                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Containers Used: TBinarySearchTreeImp, TIBinarySearchTreeImp,         */
/*  TSVectorImp.                                                          */
/*  Other Classes: string.                                                */
/*                                                                        */
/*  Data files provided: trivial.dat and text.dat.                        */
/*------------------------------------------------------------------------*/

#include <classlib\binimp.h>
#include <classlib\vectimp.h>
#include <cstring.h>
#include <regexp.h>
#include <fstream.h>
#include <strstrea.h>
#include <iomanip.h>
#include <dir.h>

// MaxRefs is the maximum number of references that a word can have 
// before it is rejected (not put into the cross reference table).
//
const unsigned MaxRefs = 6;

// Indicates the minimum length a word must have to be a candidate to be
// put into the cross reference table.
//
const unsigned MinWordLength = 3;

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TRecord                                                         */
/*                                                                        */
/*      Keeps track of the lines that a word appears on.                  */
/*                                                                        */
/*  Public Interface:                                                     */
/*                                                                        */
/*      TRecord( string word, unsigned lineNum );                         */
/*                                                                        */
/*          Creates record with given word and line number.               */
/*                                                                        */
/*      int operator == ( const TRecord& record ) const;                  */
/*                                                                        */
/*          Returns 1 if the Words compare equal, 0 otherwise.            */
/*                                                                        */
/*      int operator < ( const TRecord& record ) const;                   */
/*                                                                        */
/*          Returns 1 if the Word in this record is lexically before the  */
/*          Word in the record parameter.                                 */
/*                                                                        */
/*      int AddLineRef( unsigned lineNum );                               */
/*                                                                        */
/*          Add given page number to word's list of line references.  If  */
/*          the number of references >= 'MaxRefs' then return 0 and       */
/*          do not enter given line number in line ref list, else         */
/*          return 1                                                      */
/*                                                                        */
/*      string GetWord() const;                                           */
/*                                                                        */
/*          Return copy of 'Word' member.                                 */
/*                                                                        */
/*  Global functions:                                                     */
/*                                                                        */
/*      ostream& operator << ( ostream&, const TRecord& );                */
/*                                                                        */
/*          Writes the record to the ostream.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TRecord
{

public:

    TRecord( const string& word, unsigned lineNum );

    int operator == ( const TRecord& record ) const;
    int operator < ( const TRecord& record ) const;
    int AddLineRef( unsigned lineNum );
    string GetWord() const;
    unsigned GetPageCount() const;
    friend ostream& operator << ( ostream&, const TRecord& );

private:

    string Word;
    TSVectorImp<unsigned> LineRef;

};

TRecord::TRecord( const string& word, unsigned lineNum ) :
    Word( word ),
    LineRef(MaxRefs)
{
    AddLineRef(lineNum);
}

inline int TRecord::operator == ( const TRecord& record ) const
{
    return Word == record.Word;
}

inline int TRecord::operator < ( const TRecord& record ) const
{
    return Word < record.Word;
}

int TRecord::AddLineRef( unsigned lineNum )
{
    if( LineRef.Count() < MaxRefs )
        {
        if( LineRef.Find( lineNum ) == UINT_MAX )
            LineRef.Add( lineNum );
        return 1;
        }
    return 0;
}

string TRecord::GetWord() const
{
    return Word;
}

unsigned TRecord::GetPageCount() const
{
    return LineRef.Count();
}

ostream& operator << ( ostream& os, const TRecord& rec )
{
    char buf[80];
    ostrstream temp( buf, sizeof(buf) );
    temp.setf( ios::left );

    temp << setw(20) << rec.Word;

    for( unsigned i = 0; i < rec.LineRef.Count()-1; i++ )
        {
        temp << rec.LineRef[i] << ',';  // write all but last line number
        }                               // followed by a comma
    temp << rec.LineRef[i] << ends;     // write last line number

    os << buf;
    return os;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TCrossRef                                                       */
/*                                                                        */
/*      Responsible for reading a trivial word file and text file,        */
/*      then creating and printing a cross reference list of the words    */
/*      in the text file.  The trivial word file contains words that will */
/*      not be included in the cross reference.  The text file consists   */
/*      of ordinary ASCII text. The ouput is an alphabetical list of      */
/*      words in the text file and the numbers of the lines on which they */
/*      occur.                                                            */
/*                                                                        */
/*  Public Interface:                                                     */
/*                                                                        */
/*      TCrossRef( string trivialWordFileName, string textFileName );     */
/*                                                                        */
/*          Read trivial word file and store in a binary search tree.     */
/*          Then read each word in from the text file and process it.     */
/*          If either file cannot be opened or an error occurs during     */
/*          reading a TXFileReadError exception is thrown.                */
/*                                                                        */
/*      ~TCrossRef();                                                     */
/*                                                                        */
/*          Flushes the list of words in the cross reference.             */
/*                                                                        */
/*      PrintCrossReferences( ostream& );                                 */
/*                                                                        */
/*          Print each word and the lines it appears on in the text file. */
/*                                                                        */
/*      Nested class TXFileReadError.                                     */
/*                                                                        */
/*          An object of type TXFileReadError is thrown if either the     */
/*          trivial word or cross reference file could not be opened or   */
/*          read. To find out which file it was use the WhichFile()       */
/*          member function.                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TCrossRef
{

public:

    class TXFileReadError : public xmsg
    {
    public:
        TXFileReadError( const string& file )
            : xmsg( string( "Error reading file: " ) + file ), File(file) {}

        string WhichFile() const;

    private:
        string File;
    };

    TCrossRef( string trivialWordFileName, string textFileName );
    ~TCrossRef();

    void PrintCrossReferences( ostream& );

private:

    void ReadTrivialWords( string trivialWordFileName );
    void ReadWords( string bookWordFileName );
    void ProcessWord( string word, unsigned page );

    static void PrintRecord( TRecord _BIDSFAR &o, void _BIDSFAR*arg );
    void Reject( string word, string reason );

    TBinarySearchTreeImp<string> RejectedWords;
    TIBinarySearchTreeImp<TRecord> IndexOfWords;
    unsigned CurrentPage;

};

//
//  Construct a TCrossRef object, reading words from the file
//  specified by trivialWordFileName into the tree of rejected
//  words, then reading the text from the file specified by
//  testFileName and building the cross reference tree.
//
TCrossRef::TCrossRef( string trivialWordFileName, string textFileName ) :
    CurrentPage(1)
{
    ReadTrivialWords( trivialWordFileName );
    ReadWords( textFileName );
}

//
//  Clean up.
//
TCrossRef::~TCrossRef()
{
    IndexOfWords.Flush(1);
}

//
//  Read trivial words from the specified file, convert them
//  to lower case, and store them in the rejected words tree.
//
void TCrossRef::ReadTrivialWords( string trivialWordFileName )
{
    ifstream TrivialWordFile( trivialWordFileName.c_str() );
    if( !TrivialWordFile )
        throw TXFileReadError( trivialWordFileName );

    string wordFromFile;

    while( TrivialWordFile >> wordFromFile )
        {
        wordFromFile.to_lower();
        RejectedWords.Add( wordFromFile );
        }
}

//
//  Read words from the specified file and insert them into
//  the cross reference tree. Along the way, convert to lower
//  case and strip out any non-text characters and all text 
//  following any such characters within a word. (Quick and
//  dirty hack for dealing with possessives, etc.)
//
void TCrossRef::ReadWords( string textFileName )
{
    ifstream XrefFile( textFileName.c_str() );

    if( !XrefFile )
        throw TXFileReadError( textFileName );

    TRegexp WordOnly( "[a-z]+" );
    unsigned currentLine = 1;
    while( XrefFile )
        {
        char buf[128];
        XrefFile.getline( buf, sizeof(buf) );
        if( XrefFile )
            {
            string word;
            istrstream in( buf );
            while( in )
                {
                in >> word;
                if( in )
                    {
                    word.to_lower();    // store as lower case

                    // use WordOnly as filter to strip out trailing
                    // non-text characters and any characters following.
                    ProcessWord( word(WordOnly), currentLine );
                    }
                }
            currentLine++;
            }
        }
}

//
//  Figure out whether a word should be added to the cross
//  reference tree. If not, explain. If so, add it.
//
void TCrossRef::ProcessWord( string word, unsigned lineNum )
{

    if( RejectedWords.Find( word ) != 0 )
        Reject( word, "found in rejected word file" );
    else if( word.length() < MinWordLength )
        Reject( word, "too short" );
    else
        {
        TRecord *recordToUpdate = IndexOfWords.Find( &TRecord(word,lineNum) );
        if( recordToUpdate == 0 )
            {
            //  The word isn't in the tree yet. Add a
            //  new record to contain it.
            IndexOfWords.Add( new TRecord(word,lineNum) );
            }
        else if( recordToUpdate->GetPageCount() >= MaxRefs )
            {
            Reject( word, "reference count too large" );
            IndexOfWords.Detach( recordToUpdate, 1 );
            }
        else
            {
            //  The word is already in the tree. Add the
            //  additional line reference.
            recordToUpdate->AddLineRef( lineNum );
            }
        }
}

//
//  Callback for ForEach() to print a record to the stream
//  pointed to by 'arg'.
//
void TCrossRef::PrintRecord( TRecord &o, void *arg )
{
    (*(ostream*)arg) << o << endl;
}

//
//  Print the cross references to the specified stream.
//
void TCrossRef::PrintCrossReferences( ostream& os )
{
    os << "References:\n\n";
    os.setf( ios::left, ios::adjustfield );
    IndexOfWords.ForEach( PrintRecord, &os );
}

//
//  Process rejected words by adding the word to the
//  rejected words list and printing a message indicating
//  why the word was rejected.
//
void TCrossRef::Reject( string word, string reason )
{
    RejectedWords.Add( word );
    cerr << '\'' << word << "' rejected, " << reason << endl;
}

string TCrossRef::TXFileReadError::WhichFile() const
{
    return File;
}

/*------------------------------------------------------------------------*/

int main()
{
    try
        {
        string TrivialWordFile;
        string XrefFile;

        cerr << "Enter name of trivial word file: ";
        cin >> TrivialWordFile;

        cerr << "Enter name of file to cross reference: ";
        cin >> XrefFile;

        TCrossRef CrossRef( TrivialWordFile, XrefFile );
        CrossRef.PrintCrossReferences( cout );

        }
    catch( const TCrossRef::TXFileReadError& xReadError )
        {
        cout << xReadError.why() << endl;
        return 1;
        }
    return 0;
}
