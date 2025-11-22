#include "Customer.h"
#include <iostream>
#include <string>

using std::ostream;
using std::cout;
using std::endl;
using std::string;
using std::to_string;


/* overrides operator << to allow customers to be viewed/printed
   parameters: the os stream and a given customer
   post: if successful, the customer's position in line, arrival time, and duration time will be made available for viewing
   return: the os stream with the customer's line posiltion and timing information
*/
ostream& operator<<(ostream& os, const Customer& aCustomer)
{
	int position = aCustomer.getPosition();
	int arrival = aCustomer.getArrivalTime();
	int duration = aCustomer.getDurationTime();

	string contents = "position: " + to_string(position) + 
		" arrival: " + to_string(arrival) + " duration: " + to_string(duration);

	os << contents;

	return os;
}

/* prints the customer's data
   post: if successful, the customer's line position, arrival time, and duration time will be printed to the console
*/
void Customer::print()
{
	cout << *this << endl;
}