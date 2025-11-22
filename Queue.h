#ifndef QUEUE
#define QUEUE

#include "QueueADT.h"
#include "Node.h"
#include <string>

class Customer;

template <class T>
class Queue : public QueueADT<T>
{
public:
    Queue() { m_headPtr = m_tailPtr = nullptr; m_lineSize = 0; }
    Queue(int size) { m_headPtr = m_tailPtr = nullptr; m_lineSize = size; }
    Queue(const Queue& other);
    ~Queue();

    Queue<T>& operator=(const Queue<T>& other);

    void enqueue(const T& aValue);
    T dequeue();                
    T& peek();                  
    
    void print();
    bool isEmpty() { return m_lineSize == 0; }
    bool isFull() { return m_lineSize == MAX_LINE; }

    int size() { return m_lineSize; }

private:
    static const int MAX_LINE = 100;
    Node<T>* m_headPtr;
    Node<T>* m_tailPtr;
    int m_lineSize;
};

Queue<Customer> readCustomers(const std::string& filename);

#endif