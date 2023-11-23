/*
顺序栈是栈的顺序实现。顺序栈是指利用顺序存储结构实现的栈。采用地址连续的存储空间（数组)依次存储栈中数据元素，
由于入栈和出栈运算都是在栈顶进行，而栈底位置是固定不变的，可以将栈底位置设置在数组空间的起始处；
栈顶位置是随入栈和出栈操作而变化的，故需用一个整型变量top来记录当前栈顶元素在数组中的位置。
*/

#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
	Stack(int max = 10);
	~Stack();
	bool isempty();
	bool isfull();
	T Top();
	Stack<T> &push(const T &x);
	Stack<T> &pop(T &x);
	void Clear();

private:
	int top;
	int tmax;
	T *stack;
};

template <class T>
Stack<T>::Stack(int max)
{
	this->top = -1;
	this->tmax = max - 1;
	stack = new T[max];
	for (int i = 0; i < max; i++)
	{
		stack[i] = 0;
	}
}

template <class T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template <class T>
bool Stack<T>::isempty()
{
	return top == -1;
}

template <class T>
bool Stack<T>::isfull()
{
	return top == tmax;
}

template <class T>
T Stack<T>::Top()
{
	if (isempty())
	{
		cout << "stack is empty." << endl;
		return 0;
	}
	else
	{
		return stack[top];
	}
}

template <class T>
Stack<T> &Stack<T>::push(const T &x)
{
	if (isfull())
	{
		cout << "stack is full." << endl;
	}
	else
	{
		top++;
		this->stack[top] = x;
	}
	return *this;
}

template <class T>
Stack<T> &Stack<T>::pop(T &x)
{
	if (isempty())
	{
		cout << "stack is empty." << endl;
	}
	else
	{
		x = stack[top--];
	}
	return *this;
}

template <class T>
void Stack<T>::Clear()
{
	top = -1;
}

int main()
{
	Stack<int> s;
	int a[11] = {7, 2, 6, 4, 1, 5, 7, 9, 0, 3, 7};
	for (int i = 0; i < 11; i++)
	{
		s.push(a[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	int x = 0;
	for (int i = 0; i < 11; i++)
	{
		s.pop(x);
		cout << x << " ";
	}
}
