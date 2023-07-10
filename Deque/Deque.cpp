#include <iostream>
#include <cassert>

using namespace std;

#include"Deque.h"

int main() {
	Deque<int> list;
	list.push_front(12);
	list.push_front(34);
	list.push_front(6);
	list.push_rear(43);
	list.push_rear(76);
	list.push_rear(87);
	cout << list << endl;
	cout << list.getFront() << endl;
	cout << list.getRear() << endl;

	list.pop_front();
	list.pop_rear();
	cout << list << endl;
	cout << list.getFront() << endl;
	cout << list.getRear() << endl;
	cout << boolalpha << list.isEmpty() << endl;
	cout << boolalpha << list.isFull() << endl;

	list.pop_front();
	list.pop_front();
	list.pop_rear();
	list.pop_rear();
	cout << list << endl;
	cout << boolalpha << list.isEmpty() << endl;

	return 0;
}