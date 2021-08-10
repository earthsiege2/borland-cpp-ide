/**************************************************************************
 *
 * icecream.cpp - priority queue example program. Section 11.3.1
 *
 * $Id: icecream.cpp,v 1.5 1995/08/29 19:01:39 oberg Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

# include <vector>
# include <queue>

# include <iostream.h>
using namespace std;

//
//	class event
//	execution event in a descrete event driven simulation
//

class event {
public:
	// construct sets time of event
	event (unsigned int t) : time(t) { };
	
	// time is a public data field
	const unsigned int time;
	
	// execute event my invoking this method
	virtual void processEvent() = 0;
};

inline void destroy(event **) {}

struct eventComparison {
	bool operator () (event * left, event * right)
		{ return left->time > right->time; }
};

//
//	class simulation
//		framework for discrete event-driven simulations
//	written by Tim Budd, for Rogue Wave, 1995
//

class simulation {
public:
		// constructor
	simulation () : eventQueue(), time(0) {}
	
		// start and run simulation
	void run ();
	
		// return current time
	unsigned int time;
	
		// schedule a future event
	void  scheduleEvent (event * newEvent)
		{ eventQueue.push(newEvent); }
	
protected:
	priority_queue<event*, vector<event *>, eventComparison> eventQueue;
};

void simulation::run()
{
	while (! eventQueue.empty()) {
		event * nextEvent = eventQueue.top();
		eventQueue.pop();
		time = nextEvent->time;
		nextEvent->processEvent();
		delete nextEvent;
		}
}

//
//	ice cream store simulation
//

class storeSimulation : public simulation {
public:
	storeSimulation()
		: freeChairs(35), profit(0.0), simulation() { }
		
	bool canSeat(unsigned int numberOfPeople);
	void order(unsigned int numberOfScoops);
	void leave(unsigned int numberOfPeople);
	
		// data fields
	unsigned int freeChairs;
	double profit;	
} theSimulation;

class arriveEvent : public event {
public:
	arriveEvent (unsigned int time, unsigned int groupSize)
		: event(time), size(groupSize) { }
	virtual void processEvent();
private:
	unsigned int size;
};

class orderEvent : public event {
public:
	orderEvent (unsigned int time, unsigned int groupSize)
		: event(time), size(groupSize) { }
	virtual void processEvent();
private:
	unsigned int size;
};

class leaveEvent : public event {
public:
	leaveEvent (unsigned int time, unsigned int groupSize)
		: event(time), size(groupSize) { }
	virtual void processEvent();
private:
	unsigned int size;
};

int irand(int n)
	// return random integer between 0 and n
{ return (rand()/10) % n; }

void arriveEvent::processEvent()
{
	if (theSimulation.canSeat(size))
		theSimulation.scheduleEvent(new orderEvent(time + 1 + irand(4), size));
}

void orderEvent::processEvent()
{
		// each person orders some number of scoops
	for (int i = 0; i < size; i++)
		theSimulation.order(1 + irand(4));
		// then we schedule the leave event
	theSimulation.scheduleEvent(new leaveEvent(time + 1 + irand(10), size));
}

void leaveEvent::processEvent()
{
	theSimulation.leave(size);
}

bool storeSimulation::canSeat(unsigned int numberOfPeople)
	// if sufficient room then seat customers
{
	cout << "Time: " << time;
	cout << " group of " << numberOfPeople << " customers arrives";
	if (numberOfPeople < freeChairs) {
		cout << " is seated" << endl;
		freeChairs -= numberOfPeople;
		return true;
		}
	else {
		cout << " no room, they leave" << endl;
		return false;
		}
}

void storeSimulation::order(unsigned int numberOfScoops)
	// service icecream, compute profits
{
	cout << "Time: " << time;
	cout << " serviced order for " << numberOfScoops << endl;
	profit += 0.35 * numberOfScoops;
}

void storeSimulation::leave(unsigned int numberOfPeople)
	// people leave, free up chairs
{
	cout << "Time: " << time;
	cout << " group of size " << numberOfPeople << " leaves" << endl;
	freeChairs += numberOfPeople;
}

int main() {
	cout << "Ice Cream Store simulation from Chapter 9"  << endl;
		// load queue with some number of initial events
	unsigned int t = 0;
	while (t < 20) {
		t += irand(6);
		cout << "pumping queue with event " << t << endl;
		theSimulation.scheduleEvent(new arriveEvent(t, 1 + irand(4)));
		}
	
		// run the simulation	
	theSimulation.run();
	cout << "Total profits " << theSimulation.profit << endl;
	
	cout << "End of ice cream store simulation" << endl;
	return 0;
}
	
