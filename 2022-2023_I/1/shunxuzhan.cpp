/*
˳��ջ��ջ��˳��ʵ�֡�˳��ջ��ָ����˳��洢�ṹʵ�ֵ�ջ�����õ�ַ�����Ĵ洢�ռ䣨����)���δ洢ջ������Ԫ�أ�
������ջ�ͳ�ջ���㶼����ջ�����У���ջ��λ���ǹ̶�����ģ����Խ�ջ��λ������������ռ����ʼ����
ջ��λ��������ջ�ͳ�ջ�������仯�ģ�������һ�����ͱ���top����¼��ǰջ��Ԫ���������е�λ�á�
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
