#ifndef NODE
#define NODE

template <class T>
class Node
{
public:
	Node(const T& data) : m_data(data), m_next(nullptr) {}
	~Node() { }

	T& getData() { return m_data; }
    const T& getData() const { return m_data; }

	Node<T>* getNext() { return m_next; }
    const Node<T>* getNext() const { return m_next; }

	void setData(T& data) { m_data = data; }
	void setNext(Node<T>* next) { m_next = next; }

private:
	T m_data;
	Node<T>* m_next;
};
#endif
