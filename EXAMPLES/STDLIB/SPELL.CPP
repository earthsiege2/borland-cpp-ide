/**************************************************************************
 *
 * spell.cpp -  spell checking program.  Section 8.3
 *
 * $Id: spell.cpp,v 1.4 1995/08/29 19:03:32 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <set>
# include <string>
# include <fstream.h>
using namespace std;

void spellCheck (istream & dictionary, istream & text)
{
	typedef set <string, less<string> > stringset;
	stringset words, misspellings;
	string word;
	istream_iterator<string, ptrdiff_t> dstream(dictionary), eof;

		// first read the dictionary
	copy (dstream, eof, inserter(words, words.begin()));

		// next read the text
	while (text >> word)
		if (! words.count(word))
			misspellings.insert(word);

		// finally, output all misspellings
	cout << "Misspelled words:" << endl;
	copy (misspellings.begin(), misspellings.end(),
		ostream_iterator<string>(cout, "\n"));
}

int main()
{
	cout << "Enter text:";
	ifstream words("words");
	spellCheck(words, cin);
	cout << "End of spell check program" << endl;
	return 0;
}
