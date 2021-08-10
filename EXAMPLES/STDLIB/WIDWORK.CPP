/**************************************************************************
 *
 * widwork.cpp - widget words, from Chapter 6.3
 *
 * $Id: widwork.cpp,v 1.3 1995/08/29 19:03:58 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <list>
# include <algorithm>
# include <iostream.h>
using namespace std;

class  Widget {
public:
	int id;
	Widget(int a = 0) : id(a) { }
	void operator= (const Widget& rhs) { id = rhs.id; }
	friend ostream & operator << (ostream & out, const Widget & w)
		{ return out << "Widget " << w.id; }
	 bool operator== (const Widget & rhs)
		{ return id == rhs.id; }
	 bool operator< (const Widget & rhs)
			{ return id < rhs.id; }
};

struct WidgetTester : binary_function<Widget, int, bool> {
public:
	bool operator () (const Widget & wid, int testid) const
		{ return wid.id == testid; }
};

class inventory {
public:
	void order (int wid);	// process order for widget type wid
	void receive (int wid);	// receive widget of type wid in shipment
private:
	list<Widget> on_hand;
	list<int> on_order;
};

void inventory::order (int wid)
{
	cout << "Received order for widget type " << wid << endl;
	list<Widget>::iterator wehave = find_if(on_hand.begin(), on_hand.end(),
		bind2nd(WidgetTester(), wid));
	if (wehave != on_hand.end()) {
		cout << "Ship " << *wehave << endl;
		on_hand.erase(wehave);
		}
	else {
		cout << "Back order widget of type "  << wid  << endl;
		on_order.push_front(wid);
		}
}

void inventory::receive (int wid)
{
	cout << "Received shipment of widget type " << wid << endl;
	list<int>::iterator weneed = find(on_order.begin(), on_order.end(), wid);
	if (weneed != on_order.end()) {
		cout << "Ship " << Widget(wid) << " to fill back order" << endl;
		on_order.erase(weneed);
		}
	else
		on_hand.push_front(Widget(wid));
}

int main() {
	cout << "Widget Works test program" << endl;
	inventory stock;
	
	stock.receive(1);
	stock.receive(2);
	stock.receive(3);
	stock.order(2);
	stock.order(2);
	stock.order(3);
	stock.receive(2);
	
	cout << "End of widget words test program" << endl;
	return 0;
}
