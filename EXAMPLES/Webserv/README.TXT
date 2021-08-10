//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
    WEBSERV - iservcgi.exe and iserver.dll

DESCRIPTION:
    Common Gateway Services example for Web servers.

DEMONSTRATES:
    Components used: TPageProducer,  TDataSetPageProducer, TQueryTableProducer

COMMENTS:
     CGI utilities generate html pages. The page produced by iservcgi.exe /
     iserver.dll contains links assume that you have placed IServer in
     a scripts directory below your WWW servers root directory or wherever
     your "scripts" directory is aliased.
     Start a broswer and type <yourservername>/scripts/iservgci.exe as the URL.
     You should be rewarded with a web page that offers 3 links. These links
     exercise database access, bitmap retrieval and web site redirection.
     Iserver.dll works in a similar fashion.

