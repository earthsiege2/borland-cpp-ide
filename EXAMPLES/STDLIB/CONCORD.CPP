/**************************************************************************
 *
 * concord.cpp - Concordance sample program. Section 9.3.3
 *
 * $Id: concord.cpp,v 1.5 1995/08/29 19:01:16 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <map>
# include <list>
# include <iostream.h>
# include <string>
using namespace std;

	// define < for strings
bool operator < (const string & left, const string & right)
{	return left.compare(right) < 0; }


	// split a line of text into words
void split
	(const string & text, const string & separators, list<string> & words)
{
	int n = text.length();
	int start, stop;
	
	start = text.find_first_not_of(separators);
	while ((start >= 0) && (start < n)) {
		stop = text.find_first_of(separators, start);
		if ((stop < 0) || (stop > n)) stop = n;
		words.push_back (text.substr(start, stop-start));
		start = text.find_first_not_of(separators, stop+1);
		}
		
}


class concordance {
	typedef multimap<string, int, less<string> > wordDictType;
public:

	void addWord (string, int);
	void readText (istream &);
	void printConcordance (ostream &);
	
private:
	wordDictType wordMap;
};

void concordance::addWord (string word, int line)
{
		// see if word occurs in list
		// first get range of entries with same key
	wordDictType::iterator low = wordMap.lower_bound(word);
	wordDictType::iterator high = wordMap.upper_bound(word);
		// loop over entires, see if any match current line
	for ( ; low != high; ++low)
		if ((*low).second == line)
			return;
		// didn't occur, add now
	wordMap.insert(wordDictType::value_type(word, line));
}

# include <ctype.h>
void allLower (string & s)
{
	for (int i = 0; i < s.size(); i++)
		if (isupper(s[i]))
			s[i] = tolower(s[i]);
}

void concordance::readText (istream & in)
{
	string line;
	for (int i = 1; getline(in, line, '\n'); i++) {
		allLower(line);
		list<string> words;
		split(line, " ,.;:", words);
		list<string>::iterator wptr;
		for (wptr = words.begin(); wptr != words.end(); ++wptr)
			addWord(*wptr, i);
		}
}

void concordance::printConcordance (ostream & out)
{
	string lastword("");
	wordDictType::iterator pairPtr;
	wordDictType::iterator stop = wordMap.end();
	for (pairPtr = wordMap.begin(); pairPtr != stop; ++pairPtr)
			// if word is same as previous, just print line number
		if (lastword == (*pairPtr).first)
			out << " " << (*pairPtr).second;
		else {	// first entry of word
			lastword = (*pairPtr).first;
			cout << endl << lastword << ": " << (*pairPtr).second;
			}
	cout << endl; // terminate last line
}

int main() {
	cout << "Concordance sample program, from Chapter 7" << endl;
	cout << "Enter text, then end-of-file:" << endl;
	concordance words;
		
	words.readText(cin);	
	
	words.printConcordance(cout);

	cout << "End of concordance sample program" << endl;

	return 0;
}
