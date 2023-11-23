/*链式栈是一种数据存储结构，可以通过单链表的方式来实现，使用链式栈的优点在于它能够克服用数组实现的
顺序栈空间利用率不高的特点，但是需要为每个栈元素分配额外的指针空间用来存放指针域。
*/
#include <iostream>
using namespace std;
template <class T>
class Node;

template <class T>
class LStack
{
public:
	LStack();
	~LStack();
	bool isempty();
	T Top();
	LStack<T> &push(const T &x);
	LStack<T> &pop(T &x);
	void clear();
	Node<T> *geth()
	{
		return head;
	}

private:
	Node<T> *head;
};

template <class T>
class Node
{
	friend class LStack<T>;

private:
	T data;
	Node<T> *link;
};

template <class T>
LStack<T>::LStack()
{
	head = new Node<T>;
	head->link = head;
	head->data = 0;
}

template <class T>
LStack<T>::~LStack()
{
	Node<T> *next;
	Node<T> *top = head->link;
	while (top != head)
	{
		next = top->link;
		delete[] top;
		top = next;
	}
}

template <class T>
bool LStack<T>::isempty()
{
	if (head->link == head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
T LStack<T>::Top()
{
	if (isempty())
	{
		cout << "stack is empty." << endl;
	}
	return head->link->data;
}

template <class T>
LStack<T> &LStack<T>::push(const T &x)
{
	Node<T> *p = new Node<T>;
	p->data = x;
	p->link = head->link;
	head->link = p;
	return *this;
}

template <class T>
LStack<T> &LStack<T>::pop(T &x)
{
	if (isempty())
	{
		cout << "stack is empty." << endl;
	}
	else
	{
		x = Top();
		Node<T> *p = head->link;
		head->link = p->link;
		delete[] p;
	}
	return *this;
}

template <class T>
void LStack<T>::clear()
{
	Node<T> *next;
	Node<T> *top = head;
	while (top)
	{
		next = top->link;
		delete[] top;
		top = next;
	}
}
int main()
{
	LStack<int> s;
	int a[10] = {5, 4, 7, 3, 8, 9, 0, 5, 6, 3};

	for (int i = 0; i < 10; i++)
	{
		s.push(a[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int x=0;
	for (int i = 0; i < 11; i++)
	{
		s.pop(x);
			cout << x << " ";
	}
}
