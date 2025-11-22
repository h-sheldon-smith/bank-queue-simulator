# Bank Queue Simulator

## About This Project

This project is an event-driven simulation of customer arrivals and service in a bank queue. It models how customers wait in line for a teller, calculates the average and maximum wait times, and helps determine whether hiring an additional teller would improve efficiency.

## Project Goals
* Strengthen skills in C++ programming
* Implement and use custom data structures and ADTs
* Build familiarity with event driven simulations
* Practice file handling and input/output

## Structure
* Customer class: manages customer data (arrival time and service duration)
* Queue class: circular queue implemented as a template class
* Simulation class: processes customers, manages teller availability, calculates delays

## Simulation Data
* First line: the number of customers
* Following lines: pairs of numbers for arrival time and service duration

Sample data provided:
8
0 5
0 5
5 10
5 10
11 10
15 3
15 10
25 20

Outputs:
Processing Customers:
print stats...Max Wait: 28
Average Wait 15.625

## How to Run
In the command line interface, do the following:

1. Clone the repository: `git clone https://github.com/name/bank-queue-simulator.git`
2. Compile the program: `g++ -o bank_queue main.cpp`
3. Run with input file: `./bank_queue < simulation-data.txt`