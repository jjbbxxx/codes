#include <iostream>
using namespace std;
class queue
{
private:
    int max;
    int front;
    int rear;
    bool tag;
    int *data;

public:
    queue(int size)
    {
        max = size;
        front = 0;
        rear = 0;
        tag = false;
        data = new int[size];
    }
    ~queue()
    {
        delete data;
    }
    void clear()
    {
        rear = front;
        tag = false;
    }
    bool push(int t)
    {
        if (full())
        {
            return false;
        }
        else
        {
            if (rear == front && tag == false)
                tag = true;
            data[rear] = t;
            rear++;
            if (rear >= max)
                rear -= max;
            return true;
        }
    }
    int pop()
    {
        if (rear == front && tag == false)
        {
            cout << "empty" << endl;
            return 0;
        }
        else
        {
            int t = data[front];
            front++;
            if (front >= max)
                front -= max;
            if (front == rear)
                tag = false;
            return t;
        }
    }
    int getfront()
    {
        if (rear == front && tag == false)
        {
            cout << "empty" << endl;
            return 0;
        }
        else
            return data[front];
    }
    bool full()
    {
        if (rear == front && tag == true)
            return true;
        else
            return false;
    }
};
int main()
{
    queue a(3);
    cout << a.push(1) << endl;
    cout << a.push(2) << endl;
    cout << a.push(3) << endl;
    cout << a.push(4) << endl;
    cout << a.pop() << endl;
    cout << a.getfront() << endl;
}