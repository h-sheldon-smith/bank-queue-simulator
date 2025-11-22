#ifndef CUSTOMER
#define CUSTOMER

#include <iostream>

class Customer
{
	public:
		Customer() : m_position(0), m_arrival(0), m_duration(0) {};
		Customer(int position, int arrival, int duration) : m_position(position), m_arrival(arrival), m_duration(duration) {};
		~Customer() {};

		friend std::ostream& operator<<(std::ostream& os, const Customer& aCustomer);
		void print();

		int getPosition() const { return m_position; }
		int getArrivalTime() const { return m_arrival; }
		int getDurationTime() const { return m_duration; }

	protected:
		void setPosition(int position) { m_position = position; }
		void setArrivalTime(int arrival) { m_arrival = arrival; }
		void setDurationTime(int duration) { m_duration = duration; }

	private:
		int m_position;
		int m_arrival;
		int m_duration;
};

#endif

