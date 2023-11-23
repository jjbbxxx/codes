#include<iostream>
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

public:
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

template <class T>
class reverse
{
private:
	LStack<T> *l;
	int length;

public:
	reverse(LStack<T> *x);
	LStack<T> &rev(LStack<T> *x);
};

template <class T>
reverse<T>::reverse(LStack<T> *x){
	{
		l = new LStack<T>(*x);
		length = 0;
		Node<T> *p = x->geth()->link;
		Node<T> *head = x->geth();
		while (p != head)
		{
			p = p->link;
			length++;
		}
	}

}
template <class T>
LStack<T> &reverse<T>::rev(LStack<T> *x)
{
	T *y = (T *)malloc(sizeof(T) * length); 
	for (int i = 0; (x->isempty()) != 1; i++)
	{
		T temp = 0;
		x->pop(temp);
		y[i] = temp;
	}
	for (int i = 0; i < length; i++)
	{
		x->push(y[i]);
	}
	return *x;
}

int main()
{
	int a[10] = {3,5,1,4,6,7,4,8,9,1};
	LStack<int> l;
	LStack<int> *s = new LStack<int>(l);
	for (int i = 0; i < 10; i++)
	{
		s->push(a[i]);
	}
	Node<int> *p = s->geth()->link;
	while (p != s->geth())
	{
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;

	reverse<int> r(s);
	r.rev(s);

	Node<int> *q = s->geth()->link;
	while (q != s->geth())
	{
		cout << q->data << " ";
		q = q->link;
	}
	return 0;
}
