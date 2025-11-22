#include "Queue.h"
#include "Customer.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>

int main()
{
    Queue<Customer> bankCustomers = readCustomers("simulation-data.txt");   // Read the list of customers and arrival times from a file
    Simulation bankSimulation;
    std::cout << "Processing Customers:" << std::endl;
    bankSimulation.processCustomers(bankCustomers);     // Simulates the teller serving the customers in the queue
    bankSimulation.printStatistics();                   // Prints out the maxium delay and the average delay

    return 0;
}