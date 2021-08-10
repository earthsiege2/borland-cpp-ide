//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
    CORBA Automated Teller Machine demo

DESCRIPTION:
    This imaginary ATM system uses CORBA technology for transaction processing.

DEMONSTRATES:
    + VisiBroker CORBA technology and C++Builder integration.

COMMENTS:
    Make sure there is an OSAgent running on your network. You can use
    Tools|VisiBroker SmartAgent to start one from the C++Builder IDE.
    Start the ATM Client, ATM Server and the two Bank Servers. Any order
    is OK.
    Press the Start buttons on the two Banks and on the ATM Server.
    Press the List button on the ATM Client to see a list of valid ATM
    card holders. Type in a name, Personal Identification Number (PIN),
    and select a transaction type then press OK. You should see a reply
    with account information or an error message in the window.
    The Admin button on the ATM Client is used to connect to a specific
    ATM Server.
    Multiple ATM servers can run at once. You can give them unique names
    via the 'Server Name' edit box.
    XACTION.IDL provides the transaction interface for the ATM Client,
    ATM Server and the Bank Servers.
    BANKING.IDL provides the banking interface for the ATM Server and the
    Bank Servers.
