/*++

Copyright (C) 1999 Microsoft Corporation

Module Name:

    OPATHLEX.H

Abstract:

    Object Path DFA Tokens

History:

--*/

#ifndef _OPATHLEX_H_
#pragma option push -b -a8 -pc -A- /*P_O_Push*/

#define OPATH_TOK_EOF       0
#define OPATH_TOK_ERROR     1

#define OPATH_TOK_IDENT         100
#define OPATH_TOK_QSTRING       101
#define OPATH_TOK_INT           102
#define OPATH_TOK_HEXINT        103
#define OPATH_TOK_EQ            104

#define OPATH_TOK_DOT           105
#define OPATH_TOK_OPEN_PAREN    106
#define OPATH_TOK_CLOSE_PAREN   107
#define OPATH_TOK_SINGLETON_SYM 108
#define OPATH_TOK_COMMA         109

#define OPATH_TOK_BACKSLASH     110
#define OPATH_TOK_COLON         111

#define OPATH_SINGLETON_STRING  L"@"

extern LexEl OPath_LexTable[];


#pragma option pop /*P_O_Pop*/
#endif
