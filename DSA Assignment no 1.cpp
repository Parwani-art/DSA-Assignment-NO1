#include "Stack.h"
#include <iostream>
using namespace std;
int main()
{
	Stack s;
	cout << "--- isEmpty() Test ---\n";
	cout << "Stack empty? " << endl;
	if (s.isEmpty())
	{
		cout << "Yes.\n";
	}
	else { cout << "Yes.\n"; }

	cout << "Push elements: \n";
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	s.Push(40);
	s.Push(50);
	cout << endl;

	cout << "--- display ---\n";
	s.display();
	cout << "\n";

	cout << "--- pop ---\n";
	s.Pop();
	s.Pop();
	s.Pop();
	cout << endl;

	cout << "--- Underflow Test (pop on empty Stack) ---\n";
	s.Pop();
	cout << endl;

	
	cout << "--- isFull() test (Pushing 100 elements) ---\n";
	Stack s2;
	for (int i = 1; i <= 100; i++)
	{
		s2.Push(i);
	}
	
	cout << "Stack Full?\n";
	if (s2.isFull())
	{
		cout << "Yes!" << endl;
	}
	else
	{
		cout << "NO!" << endl;
	}

	cout << "\n--- Overflow Test (push onto full stack) ---\n";
	s2.Push(999);
	

}


