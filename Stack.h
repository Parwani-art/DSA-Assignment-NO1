#pragma once

#define MAX_SIZE 100
class Stack
{
private:
	int data[MAX_SIZE];
	int top;
public:
	Stack();
	
	bool isFull() const;
	bool isEmpty() const;
	void Push(int value);
	int Pop();   // I used int becuase (remove, return) the top element.
	void display() const;

};