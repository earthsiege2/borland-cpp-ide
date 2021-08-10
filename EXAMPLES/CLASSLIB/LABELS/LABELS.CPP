/*------------------------------------------------------------------------*/
/*                                                                        */
/*  LABELS.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1993 Borland International                              */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Classes Used: TISListImp, string, TDate, ipstream, opstream.          */
/*                                                                        */
/*  Description:                                                          */
/*                                                                        */
/*      Updates and displays the contents of a mailing list.              */
/*                                                                        */
/*  Usage:                                                                */
/*                                                                        */
/*      LABELS <master file> [<new subscription file?]                    */
/*                                                                        */
/*      Creates the master file if it does not exist. If new              */
/*      subscription file is specified, reads the file and inserts        */
/*      the new subscriptions into the master file. Prints the            */
/*      contents of the master file to standard out in label format.      */
/*                                                                        */
/*  Subscription File Format:                                             */
/*                                                                        */
/*      The format of each new subscription record is as follows:         */
/*                                                                        */
/*          <name>;<street>;<city>;<state>;<zip>;<expiration date>        */
/*                                                                        */
/*------------------------------------------------------------------------*/

#include <classlib\listimp.h>
#include <classlib\objstrm.h>
#include <classlib\date.h>
#include <cstring.h>
#include <fstream.h>

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TSubscriber                                                     */
/*                                                                        */
/*  TSubscriber holds the name and address of a subscriber.               */
/*                                                                        */
/*  TSubscriber Public Interface                                          */
/*  ----------------------------                                          */
/*                                                                        */
/*      TSubscriber();          Default constructor.                      */
/*                                                                        */
/*      TSubscriber( string name,                                         */
/*                   string address,                                      */
/*                   string city,                                         */
/*                   string state,                                        */
/*                   string zip );                                        */
/*                              Constructor.                              */
/*                                                                        */
/*      string GetName() const; Returns the name of the subscriber.       */
/*                                                                        */
/*      string GetAddress() const;                                        */
/*                                                                        */
/*                              Returns the street address of             */
/*                              the subscriber.                           */
/*                                                                        */
/*      string GetCity() const; Returns the city where the                */
/*                              subscriber lives.                         */
/*                                                                        */
/*      string GetState() const;                                          */
/*                              Returns the state where the               */
/*                              subscriber lives.                         */
/*                                                                        */
/*      string GetZip() const;  Returns the subscriber's zipcode.         */
/*                                                                        */
/*      ostream& operator << ( ostream&, const TSubscriber& );            */
/*                              Writes the subscriber's name and address, */
/*                              formatted as a mailing label, to the      */
/*                              ostream.                                  */
/*                                                                        */
/*      opstream& operator << ( opstream&, const TSubscriber& );          */
/*                              Writes the subscriber's name and address  */
/*                              to an opstream.                           */
/*                                                                        */
/*      ipstream& operator >> ( ipstream&, TSubscriber& );                */
/*                              Reads a subscriber's name and address,    */
/*                              written with the opstream inserter, from  */
/*                              an ipstream.                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TSubscriber
{

public:

    TSubscriber() {}
    TSubscriber( string name, string address,
                 string city, string state, string zip );

    friend ostream& operator << ( ostream&, const TSubscriber& );

    friend opstream& operator << ( opstream&, const TSubscriber& );
    friend ipstream& operator >> ( ipstream&, TSubscriber& );

    string GetName() const;
    string GetAddress() const;
    string GetCity() const;
    string GetState() const;
    string GetZip() const;

private:

    string Name;
    string Address;
    string City;
    string State;
    string Zip;

    enum { Version = 1 };

};

//
//  Construct a TSubscriber object from its component parts.
//

TSubscriber::TSubscriber( string name, string address,
                          string city, string state, string zip ) :
    Name(name), Address(address),
    City(city), State(state), Zip(zip)
{
}

//
//  Write a TSubscriber object to a stream in a format suitable
//  for a mailing label.
//

ostream& operator << ( ostream& out, const TSubscriber& sub )
{
    out << sub.Name << '\n'
        << sub.Address << '\n'
        << sub.City << ", " << sub.State << " " << sub.Zip << '\n'
        << endl;
    return out;
}

//
//  Write a TSubscriber object to an opstream in a format suitable
//  for reading with the extractor that follows.
//

opstream& operator << ( opstream& out, const TSubscriber& sub )
{
    out << TSubscriber::Version;
    out << sub.Name << sub.Address
        << sub.City << sub.State << sub.Zip;
    return out;
}

//
//  Read a subscriber's name and address from an ipstream created
//  with the preceding inserter.
//

ipstream& operator >> ( ipstream& in, TSubscriber& sub )
{
    int ver;
    in >> ver;
    if( ver > TSubscriber::Version )
        in.clear( ios::failbit );   // bad object version

    in >> sub.Name >> sub.Address
       >> sub.City >> sub.State >> sub.Zip;
    return in;
}

inline string TSubscriber::GetName() const
{
    return Name;
}

inline string TSubscriber::GetAddress() const
{
    return Address;
}

inline string TSubscriber::GetCity() const
{
    return City;
}

inline string TSubscriber::GetState() const
{
    return State;
}

inline string TSubscriber::GetZip() const
{
    return Zip;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TSubscriptionInfo                                               */
/*                                                                        */
/*  TSubscriptionInfo holds subscriber information and the expiration     */
/*  date for a subscription.                                              */
/*                                                                        */
/*  TSubscriptionInfo Public Interface                                    */
/*  ----------------------------------                                    */
/*                                                                        */
/*      TSubscriptionInfo();    Default constructor.                      */
/*                                                                        */
/*      TSubscriptionInfo( string name,                                   */
/*                         string address,                                */
/*                         string city,                                   */
/*                         string state,                                  */
/*                         string zip,                                    */
/*                         TDate expirationDate );                        */
/*                              Constructor.                              */
/*                                                                        */
/*      int operator == ( const TSubscriptionInfo& );                     */
/*                              Compares zip codes to determine           */
/*                              equality.                                 */
/*                                                                        */
/*      int operator <  ( const TSubscriptionInfo& );                     */
/*                              Compares zip codes to determine           */
/*                              relative order in mailing list.           */
/*                                                                        */
/*      int HasExpired()        Returns 1 to indicate that the            */
/*                              subscription has expired, 0 otherwise.    */
/*                                                                        */
/*      ostream& operator << ( ostream&, const TSubscriptionInfo& );      */
/*                              Writes the subscriber's name and address, */
/*                              formatted as a mailing label, to the      */
/*                              ostream.                                  */
/*                                                                        */
/*      opstream& operator << ( opstream&, const TSubscriber& );          */
/*                              Writes the subscription information       */
/*                              to an opstream.                           */
/*                                                                        */
/*      ipstream& operator >> ( ipstream&, TSubscriber& );                */
/*                              Reads subscription information, written   */
/*                              with the opstream inserter, from an       */
/*                              ipstream.                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TSubscriptionInfo
{
public:

    TSubscriptionInfo() {}
    TSubscriptionInfo( string name, string address,
                       string city, string state, string zip,
                       TDate expirationDate);

    int operator == ( const TSubscriptionInfo& o );
    int operator <  ( const TSubscriptionInfo& o );

    int HasExpired();

    friend ostream& operator << ( ostream&, const TSubscriptionInfo& );

    friend opstream& operator << ( opstream&, const TSubscriptionInfo& );
    friend ipstream& operator >> ( ipstream&, TSubscriptionInfo& );

private:

    TSubscriber Subscriber;
    TDate ExpirationDate;

    enum { Version = 1 };

};

TSubscriptionInfo::TSubscriptionInfo( string name, string address,
                                      string city, string state, string zip,
                                      TDate expirationDate) :
    Subscriber( name, address, city, state, zip ),
    ExpirationDate( expirationDate )
{
}

int TSubscriptionInfo::operator == ( const TSubscriptionInfo& o )
{
    return Subscriber.GetZip() == o.Subscriber.GetZip();
}

int TSubscriptionInfo::operator < ( const TSubscriptionInfo& o )
{
    return Subscriber.GetZip() < o.Subscriber.GetZip();
}

int TSubscriptionInfo::HasExpired()
{
    return ExpirationDate < TDate();
}

ostream& operator << ( ostream& out, const TSubscriptionInfo& sub )
{
    out << sub.Subscriber << endl;
    return out;
}

opstream& operator << ( opstream& out, const TSubscriptionInfo& sub )
{
    out << TSubscriptionInfo::Version;
    out << sub.Subscriber << sub.ExpirationDate;
    return out;
}

ipstream& operator >> ( ipstream& in, TSubscriptionInfo& sub )
{
    int ver;
    in >> ver;
    if( ver > TSubscriptionInfo::Version )
        in.clear( ios::failbit );   // bad object version

    in >> sub.Subscriber >> sub.ExpirationDate;
    return in;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TSubscriptionList                                               */
/*                                                                        */
/*  TSubscriptionList maintains a list of subscribers sorted by zip code. */
/*                                                                        */
/*  TSubscriptionList Public Interface                                    */
/*  ----------------------------------                                    */
/*                                                                        */
/*  TSubscriptionList( string fileName );                                 */
/*                              Constructor. Initializes the subscription */
/*                              list from the specified file if it        */
/*                              exists. This should be a file created by  */
/*                              a TSubscriptionList object.               */
/*                                                                        */
/*  ~TSubscriptionList();       Destructor. Writes the subscription list  */
/*                              out to the file specified in the          */
/*                              constructor. Overwrites the old data if   */
/*                              the file already exists, otherwise        */
/*                              creates a new file.                       */
/*                                                                        */
/*  int AddSubscription( const TSubscriptionInfo& );                      */
/*                              Adds a new subscription to the list.      */
/*                                                                        */
/*  void PrintLabels( ostream& );                                         */
/*                              Prints the subscription list as a series  */
/*                              of address labels to the specified        */
/*                              output stream.                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TSubscriptionList
{

public:

    TSubscriptionList( string fileName );
    ~TSubscriptionList();

    int AddSubscription( const TSubscriptionInfo& );
    void PrintLabels( ostream& );

private:

    void ReadStream( ipstream& );
    void WriteStream( opstream& );

    string FileName;
    TISListImp<TSubscriptionInfo> Subscriptions;
    static void PrintLabel( TSubscriptionInfo &i, void *arg );

    enum { Version = 1 };

};

TSubscriptionList::TSubscriptionList( string fileName ) :
    FileName(fileName)
{
    ifpstream in( FileName.c_str() );
    if( in )
        ReadStream( in );
}

TSubscriptionList::~TSubscriptionList()
{
    ofpstream out( FileName.c_str() );
    WriteStream( out );
}

int TSubscriptionList::AddSubscription( const TSubscriptionInfo& sub )
{
    return Subscriptions.Add( new TSubscriptionInfo(sub) );
}

void TSubscriptionList::PrintLabels( ostream& out )
{
    cerr << "Printing labels...\n";
    Subscriptions.ForEach( PrintLabel, &(ostream&)out );
    cerr << "Finished printing labels.\n";
}


void TSubscriptionList::PrintLabel( TSubscriptionInfo &i, void *strm )
{
    *(ostream *)strm << i;
}

void TSubscriptionList::WriteStream( opstream& out )
{
    out << Version;
    out << Subscriptions.GetItemsInContainer();
    TISListIteratorImp<TSubscriptionInfo> iter( Subscriptions );

    while( iter != 0 )
        out << *(iter++);
}

void TSubscriptionList::ReadStream( ipstream& in )
{
    int ver;
    in >> ver;
    if( ver > Version )
        in.clear( ios::failbit );   // bad object version
    else
        {
        unsigned count;

        in >> count;
        for( unsigned i = 0; i < count; i++ )
            {
            TSubscriptionInfo si;
            in >> si;
            if( si.HasExpired() )
                {
                cerr << "Subscription has expired:\n";
                cerr << si << endl;
                }
            else
                AddSubscription( si );
            }
        }
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TNewSubscribers                                                 */
/*                                                                        */
/*  TNewSubscribers parses a subscriber list from a text file and inserts */
/*  the subscriptions into a TSubscriptionList object.                    */
/*                                                                        */
/*  TNewSubscribers Public Interface                                      */
/*  --------------------------------                                      */
/*                                                                        */
/*  TNewSubscribers( string fileName, TSubscriptionList& list );          */
/*                              Constructor. Parameters are the name of   */
/*                              the text file to read from and a          */
/*                              reference to the subscriber list to add   */
/*                              subscribers to.                           */
/*                                                                        */
/*  void Update();              Add the subscribers to the subscriber     */
/*                              list.                                     */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TNewSubscribers
{

public:

    TNewSubscribers( string fileName, TSubscriptionList& list );

    void Update();

private:

    string FileName;
    TSubscriptionList& List;

};

TNewSubscribers::TNewSubscribers( string fileName, TSubscriptionList& list ) :
    FileName(fileName),
    List(list)
{
}

void TNewSubscribers::Update()
{
    ifstream newSubscriptions( FileName.c_str() );

    cerr << "\nProcessing subscriptions...\n";
    while( newSubscriptions )
        {
        string name;
        string address;
        string city;
        string state;
        string zip;
        TDate expirationDate;

        char buf[256];

        newSubscriptions.getline( buf, sizeof(buf), ';' );
        name = buf;

        newSubscriptions.getline( buf, sizeof(buf), ';' );
        address = buf;

        newSubscriptions.getline( buf, sizeof(buf), ';' );
        city = buf;

        newSubscriptions.getline( buf, sizeof(buf), ';' );
        state = buf;

        newSubscriptions.getline( buf, sizeof(buf), ';' );
        zip = buf;

        newSubscriptions >> expirationDate;

        if( !newSubscriptions )
            cerr << "Invalid new subscription record." << endl;
        else
            {
            TSubscriptionInfo newSubscription( name,
                                               address,
                                               city,
                                               state,
                                               zip,
                                               expirationDate );

            if( newSubscription.HasExpired() )
                {
                cerr << "New subscription has expired:\n";
                cerr << newSubscription;
                }
            else
                List.AddSubscription( newSubscription );
            }
        }
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Support functions and main()                                          */
/*                                                                        */
/*  voidSignOn();               Displays the program's banner.            */
/*                                                                        */
/*  void Usage();               Displays usage instructions.              */
/*                                                                        */
/*  void ShowList( string masterFileName );                               */
/*                              Writes mailing labels from the file       */
/*                              named by masterFileName to standard out.  */
/*                                                                        */
/*  void UpdateList( string masterFileName, string newSubFileName );      */
/*                              Adds the subscriptions from               */
/*                              to the mailing list in masterFileName,    */
/*                              then writes mailing labels from           */
/*                              masterFileName to standard out.           */
/*                                                                        */
/*  int main( int argc, char *argv[] );                                   */
/*                              Parses the command line. If only one      */
/*                              parameter is given, assumes that it is    */
/*                              the name of a master file and prints      */
/*                              mailing labels from that file. If two     */
/*                              parameters are given, assumes that the    */
/*                              first is the name of a master file and    */
/*                              the second is the name of a new           */
/*                              subscription file. Updates the master     */
/*                              file from the new subscription file then  */
/*                              prints mailing labels from the master     */
/*                              file. If no parameters are given, or more */
/*                              than two are given, displays usage        */
/*                              instructions and exits.                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

void SignOn()
{
    cerr << "Mailing Labels, version 1.00\n";
}

void Usage()
{
    cerr << "\nSyntax: LABELS <master file> [<new subscription file>]\n"
         << "\tIf both files names are present, updates master file\n"
         << "\tfrom new subscription file then writes mailing labels to\n"
         << "\tstandard out. Otherwise writes mailing labels to standard out.\n";
}

void ShowList( string masterFileName )
{
    TSubscriptionList SubList( masterFileName );
    SubList.PrintLabels(cout);
}

void UpdateList( string masterFileName, string newSubFileName )
{
    TSubscriptionList SubList( masterFileName );
    TNewSubscribers NewSubs( newSubFileName, SubList );
    NewSubs.Update();
    SubList.PrintLabels(cout);
}

int main (int argc, char *argv[])
{
    SignOn();
    switch( argc )
        {
        case 2:
            ShowList( argv[1] );
            break;
        case 3:
            UpdateList( argv[1], argv[2] );
            break;
        default:
            Usage();
            break;
        }
    return 0;
}

