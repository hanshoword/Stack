## Stack
### Linked Stack
##### CStack.h 헤더파일
```c
#include <assert.h>
#include <iostream>
using namespace std;
```
필요한 헤더파일/namespace를 추가합니다.

##### CStackNode 클래스
```c
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
```
template <typename T>를 통해 여러 자료형들을 대응시킬수 있도록 합니다.

Stack은 Single Linked List로써 다음 노드의 주소와 T형 데이터값을 가집니다.

다음노드의 주소를 생성자에서 nullptr로 초기화 시킵니다.

##### CStackList Class
```c
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
```
CStackList 클래스는 노드와 사이즈를 멤버변수로 가지며, typedef를 통해 자료형을 사용하기쉽게 명명하였습니다. 

생성자에서 Node와 Size를 초기화 시키며, 소멸자에서는 clear()함수를 통해 모든 노드를 삭제합니다.

clear함수는 뒤에서 설명합니다.


##### push 함수 : 데이터를 넣습니다.
```c
public:
	void push(const T& data)
	{
		//새로운 노드 생성
		PNODE	pNode = new NODE;
		pNode->m_Data = data;

		pNode->m_pNext = m_pNode;

		m_pNode = pNode;

		m_iSize++;
	}
```
먼저 추가될 노드를 생성하고, 데이터를 입력합니다.

그리고 그 새로운 노드를 맨앞에 추가시킵니다.

그렇게 하기위해 새로운노드의 다음주소값을 m_pNode(초기노드)로 넣어주면 됩니다.

그리고 초기노드(일반 스택에서 top이 위치하는부분)는 새로운노드가 됩니다.

리스트 사이즈를 1증가시킵니다.

##### pop 함수 : 데이터를 추출합니다. ( 후입선출 구조 )
```c
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
```

리스트가 비어있으면 반환할 데이터가 없기때문에 에러처리를 합니다.

먼저 초기노드의 다음 노드를 미리 받아놓습니다.

그리고 초기노드의 data값을 data변수에 넣습니다.

그리고 초기노드를 삭제하고, 이제 초기노드는 미리 받아둔 다음 노드가 됩니다.

사이즈를 1줄이고, 아까 받아놓은 data를 반환하면 pop이 수행됩니다.

##### top 함수 : top에 위치한 노드의 데이터를 반환합니다.

```c
T top() const
	{
		if (empty())
		{
			assert(false);
		}

		return m_pNode->m_Data;
	}
```
empty상태이면 에러처리를하고, 그렇지않으면 초기노드(top)의 데이터를 반환합니다.


##### clear함수 : 모든 노드를 삭제
```c
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
```

pNode는 초기노드부터 시작합니다.

pNode가 존재한다면 반복문을 수행하는데, 미리 pNode의 다음노드를 받아둡니다.

그리고 초기노드를 delete하고, pNode는 미리받아둔 다음노드가 됩니다.

이제 노드가 모두 삭제됐으므로 Size를 0으로 합니다.

##### empty 함수 : 리스트가 비어있는지 체크
```c
bool empty()	const
	{
		return m_iSize == 0;
	}
```
리스트 사이즈가 0이면 true를 0이 아니라면 false를 반환해줍니다.

##### size 함수
```c
	int size()		const
	{
		return m_iSize;
	}
```

m_iSize는 private이므로 접근할수 없기때문에, 리스트의 사이즈를 반환해주는 함수가 필요합니다.




#### CStackArray Class

```c
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
```

배열을 통한 스택을 구현합니다.

#define을 통해 stack size를 지정하고, template <typename T>로 여러 자료형들에 대응할수 있도록 클래스를 구현합니다.

먼저 멤버변수는 T형 stack 배열과 top으로 이루어져 있습니다.

기본적으로 push할때는 top을 1 증가시키고 top이 배열의 인덱스 위치가되어 그지점에 데이터가 삽입됩니다.

top을 1 증가시킨 지점(데이터가 들어가야할 배열 인덱스 값)에 데이터를 삽입하므로,

top은 기본적으로 -1이 돼야 배열 처음 인덱스값인 0 부분에 데이터가 들어갈것입니다.

##### push 함수
```c
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
```
매개변수로 데이터를 받아옵니다. 

먼저 top의 위치가 Stack Size를 넘어서는지 체크하여 넘는다면 에러메시지를 출력합니다.

top을 먼저 1증가시키고 top이 배열의 index가 되며 stack 배열에 데이터를 넣습니다.

top의 초기값은 -1이며, ++top이 index가 되므로 index 0, 1, 2, 3 ... 순서로 들어가게됩니다.


##### pop 함수 : 후입선출구조로 데이터를 반환
```c
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
```
pop을 하기 위해서는 스택에 삽입된 데이터가 존재해야합니다.

따라서 빈 스택이라면 pop을 할 수 없기때문에 에러메세지를 출력합니다.

빈스택을 체크하려면 top의 초기값이 -1이므로 top이 -1인지를 체크하면 됩니다.

pop은 먼저 stack[top]에 있는 데이터를 반환하고 top을 하나 줄여줘야합니다. 따라서 top--로 index를 넣어줍니다.


##### delete 함수 : pop과 비슷하나, 데이터를 반환하지않고 삭제함
```c
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
```
pop과 구조가 동일하며 데이터를 반환하고 삭제만 수행합니다.


```c
```

```c
```

```c
```
