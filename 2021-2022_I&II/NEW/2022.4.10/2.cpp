#include <bits/stdc++.h>
using namespace std;
//
class MyArray
{
protected:
    int *alist;
    int length;

public:
    MyArray(int leng = 0);
    MyArray(const MyArray &a);
    ~MyArray();
    void input();
    void display();
    int *add() { return alist; }
    int len() { return length; }
};
MyArray::MyArray(int leng) : length(leng)
{
    alist = new int[leng];
}
MyArray::MyArray(const MyArray &a)
{
    length = a.length;
    for (int i = 0; i < length; i++)
    {
        alist[i] = a.alist[i];
    }
}
MyArray::~MyArray()
{
    delete[] alist;
}
void MyArray::input()
{
    for (int i = 0; i < length; i++)
    {
        cin >> alist[i];
    }
}
void MyArray::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << alist[i] << ' ';
    }
    cout << endl;
}
//
class AverArray : public MyArray
{
    double average;

public:
    AverArray(MyArray &a);
    double display();
};
AverArray::AverArray(MyArray &a)
{
    alist = a.add();
    length = a.len();
    double sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += alist[i];
    }
    average = (sum / (double)length);
    cout<<average<<endl;
}
double AverArray::display()
{
    return average;
}
//
class RevArray : public MyArray
{
    int *rlist;

public:
    RevArray(MyArray &a);
    void display();
};
RevArray::RevArray(MyArray &a)
{
    int *temp = a.add();
    length = a.len();
    for (int i = 0; i < length; i++)
    {
        alist[i] = temp[length - i-1];
    }
}
void RevArray::display()
{
    for (int i = 0; i < length; i++)
    {
        cout << alist[i] << ' ';
    }
    cout << endl;
}
//
int main()
{
    MyArray a(5);
    a.input();
    a.display();
    AverArray b(a);
    RevArray c(a);
    b.display();
    c.display();
    return 0;
}