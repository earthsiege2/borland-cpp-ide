// print.hpp
//............................................................................
#ifndef PRINT_HPP
#define PRINT_HPP

//............................................................................
// function prototypes

void EmptyFile( void );
void PrintMsg( WORD dest, LPCSTR format, ...);

// dest
#define TO_FILE	0x0001
#define TO_DBWIN	0x0002
#define TO_MSGBOX	0x0004

//............................................................................
#endif // PRINT_HPP
