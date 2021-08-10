/*------------------------------------------------------------------------*/
/*                                                                        */
/*  LOOKUP.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  Hash table example file                                               */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined(SERVICES_CSTRING_H)
# include <services/cstring.h>
#endif
#if !defined(CLASSLIB_ASSOC_H)
# include <classlib/assoc.h>
#endif
#if !defined(CLASSLIB_DICT_H)
# include <classlib/dict.h>
#endif
#if !defined(__IOSTREAM_H)
# include <iostream.h>    
#endif

static char *Entries[] =
    {
   "string",           "manipulates character data",
	 "TDate",            "manipulates dates",
	 "TTime",            "manipulates times",
	 "VectorImp",        "implements a zero-based vector",
	 "CVectorImp",       "implements a zero-based counted vector",
	 "SVectorImp",       "implements a zero-based sorted vector",
	 };

#define ArraySize(n) (sizeof(n)/sizeof(*n))

class HashString : public string {
  public:
	 HashString() : string() {}
	 HashString(const char* s) : string(s) {}
	 unsigned HashValue() const { return hash(); }
};
						 
typedef TDDAssociation<HashString,HashString> ClassData;
typedef TDictionaryAsHashTable<ClassData> Dictionary;

int main( int argc, char *argv[] )
{
	 if( argc != 2 )
		  {
		  cerr << "Usage:  lookup classname\n";
		  return 1;
		  }

	 Dictionary ClassDefinitions;
	 string::set_case_sensitive(0);

	 for( int i = 0; i < ArraySize(Entries); i+=2 )
		  ClassDefinitions.Add( ClassData( Entries[i], Entries[i+1] ) );

	 ClassData *definition =
		  ClassDefinitions.Find( ClassData( argv[1], (char *)0 ) );
	 if( definition == 0 )
		  cout << "A definition for " << argv[1]
				 << " was not found in the dictionary.\n";
	 else
		  cout << definition->Key() << " : " << definition->Value() << endl;

   ClassDefinitions.Flush();
	 return 0;
}
