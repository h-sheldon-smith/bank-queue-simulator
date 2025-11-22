#ifndef SIMULATION
#define SIMULATION

#include "Queue.h"
#include <string>

class Customer;

class Simulation
{
	public:
		Simulation() { m_maxWait = 0; m_averageWait = 0; }
		~Simulation() {};

		void processCustomers(Queue<Customer> bankCustomers);
		void printStatistics();

	private:
		int m_maxWait;
		double m_averageWait;

		std::string removeTrailingZeros(std::string avgWait);

};

#endif
