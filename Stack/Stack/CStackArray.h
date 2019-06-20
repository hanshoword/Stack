#pragma once
#include <iostream>
using namespace std;
#define STACK_SIZE 100

template <typename T>
class CStackArray
{
public:
	CStackArray()
	{
		top = -1;
	}
	~CStackArray()
	{
		while (top != -1)
		{
			del();
		}
	}
private:
	T stack[STACK_SIZE];
	int top;
public:
	/*Push*/
	void push(T item)
	{
		if (top >= STACK_SIZE - 1)
		{
			cout << endl << endl << " Stackis FULL" << endl;
			return;
		}
		else
		{
			stack[++top] = item;
		}
	}

	/*Pop*/
	T pop()
	{
		if (top == -1)
		{
			cout << endl << endl << " Stack is Empty" << endl;
			return 0;
		}
		else
		{
			return stack[top--];
		}
	}

	/*Delete*/
	void del()
	{
		if (top == -1)
		{
			cout << endl << endl << "Stack is Empty" << endl;
			exit(1);
		}
		else
		{
			top--;
		}
	}

	/*top 원소 검색*/
	T peek()
	{
		if (top == -1)
		{
			cout << endl << endl << "Stack is Empty" << endl;
			exit(1);
		}
		else
		{
			return stack[top];
		}
	}

	/*Stack Print*/
	void printStack()
	{
		int i;
		cout << endl << "Array Stack [ ";
		for (i = 0; i <= top; i++)
		{

			cout << stack[i] << " ";
		}
		cout << "]" << endl << endl;
	}

};

