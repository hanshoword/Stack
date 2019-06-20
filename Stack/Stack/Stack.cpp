#include <iostream>
#include "CStack.h"
#include "CStackArray.h"

using namespace std;

int main()
{
	CStackList<int> S;
	for (int i = 0; i < 10; i++)
	{
		S.push(i);
	}
	S.printStack();

	cout << "Pop [ ";
	for (int i = 0; i < 10; i++)
	{
		cout << S.pop() << " ";
	}
	cout << "]" << endl << endl;

	CStackArray<int> S_A;

	for (int i = 0; i < 10; i++)
	{
		S_A.push(i);
	}
	S_A.printStack();

	cout << "Pop [ ";
	for (int i = 0; i < 10; i++)
	{
		cout << S_A.pop() << " ";
	}
	cout << "]" << endl << endl;


	return 0;
}