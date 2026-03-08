#pragma once
using namespace std;
#include<iostream>
#define MAX_SIZE 100

template<typename T>
class Stack
{
private:
	T data[MAX_SIZE];
	int top;
public:
	Stack()
	{
		top = -1;
	}

	bool isFull() const
	{
		return top == MAX_SIZE - 1;
	}

	bool isEmpty() const
	{
		return top == -1;
	}

	void Push(T value)
	{
		if (isFull())
		{
			return;
		}
		data[++top] = value;
	}

	T Pop()
	{
		if (isEmpty())
		{
			return T{};
		}
		return data[top--];
	}
	void display() const
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
		cout << " <--Bottom\n";
	}
};