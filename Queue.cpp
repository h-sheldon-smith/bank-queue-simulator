#include "Queue.h"
#include "Node.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <utility>

using std::iostream;
using std::fstream;
using std::string;
using std::swap;

template <class T>
Queue<T>::Queue(const Queue& other)
{
	m_lineSize = other.m_lineSize;

	Node<T>* otherPtr = other.m_headPtr;

	if (otherPtr == nullptr)
	{
		m_headPtr = m_tailPtr = nullptr;
	}
	else
	{
		m_headPtr = m_tailPtr = new Node<T>(otherPtr->getData());

		otherPtr = otherPtr->getNext();

		while (otherPtr != nullptr)
		{
			Node<T>* addNodePtr = new Node<T>(otherPtr->getData());
			m_tailPtr->setNext(addNodePtr);

			m_tailPtr = m_tailPtr->getNext();
			otherPtr = otherPtr->getNext();
		}
		m_tailPtr->setNext(nullptr);
	}
}

template<class T>
Queue<T>::~Queue()
{
	Node<T>* holdPtr = m_headPtr;
	Node<T>* deletePtr = nullptr;

	while (holdPtr != nullptr)
	{
		deletePtr = holdPtr;
		holdPtr = holdPtr->getNext();
		delete deletePtr;
	}
	m_headPtr = m_tailPtr = nullptr;
	m_lineSize = 0;
}

/* overrides operator = so that this queue can be given the values of another queue
   parameters: other the queue with the values that should be adopted
   post: if successful, this queue will have the values of the other queue
   return: this queue
*/
template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other) {
        Queue<T> temp(other);
        swap(m_headPtr, temp.m_headPtr);
        swap(m_tailPtr, temp.m_tailPtr);
        m_lineSize = temp.m_lineSize;
	}

	return *this;
}

/* reads a file in order to obtain customer data and place it in a queue.
   preconditions: the file already exists.
                  the first value will be an integer representing the queue size.
				  customer data will follow and will consist of two integers per customer. 
				  each customer will have a value for arrival and duration times in that order.
   post: if successful, the customers from the file will be added to a queue.
   return: a queue of customers.
*/
Queue<Customer> readCustomers(const string& filename)
{
    int lineSize;
	int position = 0;
	int arrival;
	int duration;

	ifstream customerLineData(filename);
	customerLineData >> lineSize;

	Queue<Customer> newCustomerLine;

	while (customerLineData >> arrival >> duration)
	{
		Customer nextCustomer(++position, arrival, duration);
		newCustomerLine.enqueue(nextCustomer);
	}
	customerLineData.close();

	return newCustomerLine;
}

/* adds a value to the back
   parameters: toAddValue the value to be added
   post: if successful, the new value will be added to the back of the queue
*/
template<class T>
void Queue<T>::enqueue(const T& toAddValue)
{
	if (!isFull()) {
		Node<T>* newNode = new Node<T>(toAddValue);

		if (m_tailPtr == nullptr)
		{
			m_headPtr = m_tailPtr = newNode;
		}
		else
		{
			m_tailPtr->setNext(newNode);
			m_tailPtr = m_tailPtr->getNext();
		}
		m_lineSize++;
	}
}

/* removes a value from the front
   pre: there is at least one value in the queue
   post: if successful, the front most value will be removed from the queue and returned
   return: the first most value
*/
template<class T>
T Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		Node<T>* removalPtr = m_headPtr;
		T removalData = removalPtr->getData();
		m_headPtr = m_headPtr->getNext();
		delete removalPtr;
        m_lineSize--;
		return removalData;
	}
	else
	{
		throw out_of_range("nobody is in line");
	}
}

/* shows the value at the front of the queue without removing it
   pre: there is at least one value in the queue
   post: if successful, the front most value will be shown and no changes will be made to the queue.
   return: the first most value
*/
template<class T>
T& Queue<T>::peek()
{
	if (!isEmpty())
	{
		return m_headPtr->getData();
	}
	else
	{
		throw out_of_range("nobody is in line");
	}
}

// prints the contents of the queue
template<class T>
void Queue<T>::print()
{

	Node<T>* checkEachCustomer = m_headPtr;

	while (checkEachCustomer != nullptr)
	{
		
		T data = checkEachCustomer->getData();
		cout << data << endl;

		checkEachCustomer = checkEachCustomer->getNext();
	}
}

template class Queue<Customer>;




