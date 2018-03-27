#include <iostream>
#include "FixedList.cpp"

using namespace std;

int main()
{
	FixedList<int, (size_t) 10> list = FixedList<int, (size_t)10>();
	cout << "We build an empty list with capacity 10." << endl;
	for (int i = 0; i < 11; ++i)
	{
		if (list.add(i))
			cout << "Add int " << i << " inside." << endl;
		else
			cout << "Cannot add int " << i << endl;
	}
	cout << "\nSize: " << list.size() << endl;
	cout << "Capacity: " << list.capacity() << endl;
	cout << "get(5): " << list.get(5) << endl;
	cout << "[5]: " << list[5] << endl;
	cout << "Get first index of number 5: " << list.getFirstIndex(5) << endl;

	cout << "\nAll memebers in list: ";
	for (int i = 0; i < list.size(); ++i)
	{
		cout << list[i] << " ";
	}
	cout << "\nRemove number 5 in list. " << endl;
	try
	{
		list.remove(5);
	} 
	catch (int)
	{
		cerr << "The number is not exist." << endl;
	}
	cout << "\nAll memebers in list: ";
	for (int i = 0; i < list.size(); ++i)
	{
		cout << list[i] << " ";
	}
	cout << "\nSize: " << list.size() << endl;
	cout << "Capacity: " << list.capacity() << endl;

	cout << "\nGet the 10th number in list: ";
	try
	{
		cout << list.get(9);
	}
	catch (unsigned int)
	{
		cerr << "Out of size of list." << endl;
	}
	cout << "\nRemove number 5 in list. " << endl;
	try
	{
		list.remove(5);
	}
	catch (int)
	{
		cerr << "The number is not exist." << endl;
	}
	cout << "\nSize: " << list.size() << endl;
	cout << "Capacity: " << list.capacity() << endl;

	system("pause");
	return 0;
}