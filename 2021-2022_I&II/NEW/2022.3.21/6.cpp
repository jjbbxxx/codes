#include <iostream>
using namespace std;
class Array
{
public:
    Array(int number);         // n elements . All elements are initialized to 0
    Array(const Array &other); // Copy Constructor
    ~Array();                  // Destructor
    void print();              // Print out all elements
    void input();              // Enter all array elements
    void set(int index, int value);

private:
    int *data;
    int n; // number of elements
};

Array::Array(int number)
{
    n = number;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = 0;
    }
}; // n elements . All elements are initialized to 0
Array::Array(const Array &other)
{
    data = other.data;
    n = other.n;
}; // Copy Constructor
Array::~Array()
{
    cout<<"Destructing..."<<endl;
    delete[] data;
}; // Destructor
void Array::print()
{
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;

}; // Print out all elements
void Array::input()
{
    cout << "input " << n << " number(s):";
    for (int i = 0; i < n; i++)
        cin >> data[i];
}; // Enter all array elements
void Array::set(int index, int value)
{
    *(data + index) = value;
};

int main()
{
    Array a(4);
    a.print();
    a.input();
    a.print();
    a.set(3, 10);
    a.print();
    Array b(a);
    b.print();
    return 0;
}