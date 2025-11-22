#include "Simulation.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::abs;

//prints maximum wait time and average wait time for a given simulation of bank customers.
void Simulation::printStatistics() 
{ 
	string maxWait = to_string(m_maxWait);
	string averageWait = to_string(m_averageWait);
	averageWait = removeTrailingZeros(averageWait);

	cout << "Max Wait: " + maxWait << endl;
	cout << "Average Wait: " + averageWait << endl; 
}

/* finds the averagerage wait time and maximum wait time for a queue of bank customers
   parameter: the queue of customers to be processed
   post: if successful, the simulation will store data for the average and maximum wait times.
         if there are no customer or only one customer, the wait times will be zero.
*/
void Simulation::processCustomers(Queue<Customer> bankCustomers)
{
	if (bankCustomers.size() == 1)
	{
		m_maxWait = 0;
		m_averageWait = 0;
	}
	else if (bankCustomers.size() > 1) 
	{
		Customer firstCustomer = bankCustomers.dequeue();

		int currentWait = 0;
		int maxWait = 0;
		double totalWait = 0;
		int totalDuration = firstCustomer.getDurationTime();
		int previousCustomerDuration = firstCustomer.getDurationTime();

		for (int nextInLine = 2; nextInLine <= bankCustomers.size(); nextInLine++)
		{
			Customer currentCustomer = bankCustomers.dequeue();
			currentWait = abs(currentCustomer.getArrivalTime() - totalDuration);

			totalDuration += currentCustomer.getDurationTime();
			totalWait += currentWait;

			if (currentWait > maxWait)
			{
				maxWait = currentWait;
			}

			previousCustomerDuration = currentCustomer.getDurationTime();
		}

		m_maxWait = maxWait;
		m_averageWait = totalWait / bankCustomers.size();
	}
}

/* removes the trailing zeros from a number
   parameter: a number with a decimal that has been converted to a string
   post: if successful, the trailing zeros are removed from the number.
		 if all decimal places are zeros, the "." is also removed.
   return: the updated number in string format
*/
string Simulation::removeTrailingZeros(string avgWait)
{
	int count = avgWait.length() - 1;

	while(count > 0 && avgWait.substr(avgWait.length() - 1, 1) == "0")
	{
		avgWait = avgWait.substr(0, avgWait.length() - 1);
	}

	if (avgWait.substr(avgWait.length() - 1, 1) == ".")
	{
		avgWait = avgWait.substr(0, avgWait.length() - 1);
	}

	return avgWait;
}