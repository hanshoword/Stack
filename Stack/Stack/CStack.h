#pragma once

#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
class CStackNode
{
	template<typename T>
	friend class CStackList;

private:
	CStackNode()
	{
		m_pNext = nullptr;
	}
	~CStackNode()
	{

	}

private:
	CStackNode<T>*	m_pNext;
	T				m_Data;
};

template <typename T>
class CStackList
{
public:
	CStackList()
	{
		m_pNode = nullptr;
		m_iSize = 0;
	}
	~CStackList()
	{
		clear();
	}

private:
	typedef CStackNode<T>	NODE;
	typedef CStackNode<T>*	PNODE;

private:
	PNODE	m_pNode;
	int		m_iSize;
public:
	void push(const T& data)
	{
		//货肺款 畴靛 积己
		PNODE	pNode = new NODE;
		pNode->m_Data = data;

		pNode->m_pNext = m_pNode;

		m_pNode = pNode;

		m_iSize++;
	}

	T top() const
	{
		if (empty())
		{
			assert(false);
		}

		return m_pNode->m_Data;
	}

	T pop()
	{
		if (empty())
		{
			assert(false);
		}

		PNODE	pNext = m_pNode->m_pNext;
		T		data = m_pNode->m_Data;

		delete m_pNode;
		m_pNode = pNext;
		m_iSize--;

		return data;
	}

	void clear()
	{
		PNODE	pNode = m_pNode;

		while (pNode)
		{
			PNODE pNext = pNode->m_pNext;

			delete pNode;

			pNode = pNext;
		}

		m_iSize = 0;
	}

	void printStack()
	{
		PNODE	pNode = m_pNode;

		cout << "Stack [ ";
		while (pNode)
		{
			PNODE pNext = pNode->m_pNext;

			cout << pNode->m_Data << " ";

			pNode = pNext;
		}
		cout << "]" << endl << endl;
	}

	bool empty()	const
	{
		return m_iSize == 0;
	}

	int size()		const
	{
		return m_iSize;
	}
};

