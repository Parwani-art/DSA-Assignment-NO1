#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack()
{
	top = -1;
}

bool Stack::isFull() const
{
	return top == MAX_SIZE - 1;
}
bool Stack::isEmpty() const
{
	return top == -1;
}
void Stack::Push(int value)
{
	if (isFull())
	{
		cout << "Stack overflow, can't push " << value<<". Stack if full.\n";
		return;
	}
	data[++top] = value;
	cout << "[Push] " << value << " pushed onto Stack.\n";
}

int Stack::Pop()
{
	if (isEmpty())
	{
		cout << "Stack underflow, can't pop, Stack is empty.\n";
		return -1;
	}
	int removed = data[top--];
	cout << "[Pop]" << removed << " poped from Stack.\n";
	return removed;
}

void Stack::display() const
{
	if (isEmpty())
	{
		cout << "Stack is empty.\n";
		return;
	}
	cout << "[Stack] top--> ";
	for (int i = top; i >= 0; i--)
	{
		cout << data[i];
		if (i > 0) cout << " | ";
	}
	cout << "<--Bottom\n";

}