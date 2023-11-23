#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Array
{
public:
    Array(int s) : size(s)
    {
        element = new T[size];
    }; // Initialization
    virtual ~Array()
    {
        delete[] element;
    }; // Destructor
    T &operator[](int index)
    {
        if (index < 0 || index > size - 1)
        {
            cout << "out of range!" << endl;
            return element[0];
        }
        return element[index];
    }; // Access an element according to the index,
    // note: there should be a prompt for the subscript
    // access beyond the boundary
    void sort()
    {
        int f = 0;
        T temp;
        for (int i = 0; i < size; i++)
        {
            f = i;
            for (int n = i; n < size; n++)
            {
                if (element[n] < element[f])
                    f = n;
            }
            temp = element[i];
            element[i] = element[f];
            element[f] = temp;
        }

    }; // Ascending order
    T sum()
    {
        T sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum += element[i];
        }
        return sum;
    }; // Sum of array elements
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout << element[i] << ' ';
        }
        cout << endl;
    }

protected:
    int size;
    T *element;
};

int main()
{
    Array<int> a(3);
    a[0] = 5;
    a[1] = 2;
    a[2] = 3;
    a.sort();
    a.show();
    cout << a.sum() << endl;
}
