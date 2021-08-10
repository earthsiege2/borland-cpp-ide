/**************************************************************************
 *
 * tele.cpp - telephone directory sample program, from section 9.3.1
 *
 * $Id: tele.cpp,v 1.4 1995/08/29 19:03:44 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <map>
# include <algorithm>
# include <vector>
# include <iostream.h>
# include <string>
using namespace std;

typedef map<string, long, less<string> > friendMap;
typedef map<long, string, less<long> >   sortedMap;

//
//	utility functions used in telephone directory
//

typedef friendMap::value_type entry_type;
typedef sortedMap::value_type sorted_entry_type;

void printEntry(const entry_type & entry)
	{ cout << entry.first << ":" << entry.second << endl; }

void printSortedEntry(const sorted_entry_type & entry)
	{ cout << entry.first << ":" << entry.second << endl; }

int prefix(const entry_type& entry)
	{ return entry.second / 10000; }

bool prefixCompare(const entry_type & a, const entry_type & b)
	{ return prefix(a) < prefix(b); }
	
class checkPrefix {
public:
	checkPrefix (int p) : testPrefix(p) { }
	int testPrefix;
	bool operator () (const entry_type& entry)
		{ return prefix(entry) == testPrefix; }
};
			
class telephoneDirectory {
public:
	void addEntry (string name, long number)
		{ database[name] = number; }
		
	void remove (string name)
		{ database.erase(name); }
	
	void update (string name, long number)
		{ remove(name); addEntry(name, number); }
		
	void displayDatabase()
		{ for_each(database.begin(), database.end(), printEntry); }
	
	void displayPrefix(int);
	
	void displayByPrefix();	
	
private:
	friendMap database;
};

void telephoneDirectory::displayPrefix(int prefix)
{
	cout << "Listing for prefix " << prefix << endl;
	map<string, long, less<string> >::iterator where;
	where = find_if(database.begin(), database.end(), checkPrefix(prefix));
	while (where != database.end()) {
		printEntry(*where);
		where = find_if(++where, database.end(), checkPrefix(prefix));
		}
	cout << "end of prefix listing" << endl;
}

void telephoneDirectory::displayByPrefix()
{
	cout << "Display by prefix" << endl;

	sortedMap sortedData;

	for (friendMap::iterator i = database.begin(); i != database.end(); i++)
		sortedData.insert(sortedMap::value_type((*i).second,
							(*i).first));

	for_each(sortedData.begin(), sortedData.end(), printSortedEntry);
	cout << "end display by prefix" << endl;
}

int main() {
	cout << "Telephone Directory sample program" << endl;
	telephoneDirectory friends;
	
	friends.addEntry("Samantha", 6342343);
	friends.addEntry("Brenda", 5436546);
	friends.addEntry("Fred", 7435423);
	friends.addEntry("Allen", 6348723);
	
	friends.displayDatabase();
	friends.displayPrefix(634);
	friends.displayByPrefix();
	
	cout << "End of telephone directory sample program" << endl;
	return 0;
}
