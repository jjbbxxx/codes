#include <iostream>
using namespace std;
class Rational
{
public:
    int test2, test1;
    Rational(int a = 1, int b = 1)
    {
        n = a;
        m = b;
        test2 = 1;
        test1 = 1;
        if (a == 0)
            test2 = 0;
        if (b == 0)
            test1 = 0;
    };                           // Constructor
    Rational R_add(Rational &A); // Addition
    Rational R_sub(Rational &A); // Subtraction
    Rational R_mul(Rational &A); // Multiplication
    Rational R_div(Rational &A); // Division
    void print();                // Contract the fraction as a simple fraction and it out
private:
    void simple(); // Contract
    int m;         // Denominator
    int n;         // Molecule
};

Rational Rational::R_add(Rational &A)
{
    int rn, rm;
    rm = m * A.m;
    rn = n * A.m + A.n * m;
    Rational n(rn, rm);
    n.simple();
    return n;
}; // Addition
Rational Rational::R_sub(Rational &A)
{
    int rn, rm;
    rm = m * A.m;
    rn = n * A.m - A.n * m;
    Rational n(rn, rm);
    n.simple();
    return n;
}; // Subtraction
Rational Rational::R_mul(Rational &A)
{
    int rn, rm;
    rm = m * A.m;
    rn = n * A.n;
    Rational n(rn, rm);
    n.simple();
    return n;
}; // Multiplication
Rational Rational::R_div(Rational &A)
{
    int rn, rm;
    rm = m * A.n;
    rn = n * A.m;
    Rational n(rn, rm);
    n.simple();
    return n;
}; // Division
void Rational::print()
{
    simple();
    if (m == 1 && n == 1)
        cout << 1 << endl;
    else if (m == 0 && n != 0)
        cout << "err!" << endl;
    else if (n == 0 && m != 0)
        cout << 0 << endl;
    else if (m == 0 && n == 0)
        cout << 0 << endl;
    else
        cout << n << '/' << m << endl;
} // Contract the fraction as a simple fraction and it out

void Rational::simple()
{
    int r, min, x = 0;
    if (n < 0)
    {
        n *= (-1);
        x = 1;
    }
    if (m < n)
        min = m;
    else
        min = n;
    for (int i = 1; i <= min; i++)
        if (n % i == 0 && m % i == 0)
            r = i;
    m /= r;
    n /= r;
    if (x == 1)
        n *= (-1);
}

int main()
{
    int n1, m1;
    Rational zero(0, 1);
    cout << "num1:";
    cin >> n1 >> m1;
    Rational num1(n1, m1);
    int n2, m2;
    cout << "num2:";
    cin >> n2 >> m2;
    Rational num2(n2, m2);
    char cal;
    if (num1.test1!=0&&num2.test1!=0)
    {
    start:
        cout << "choose calculation method:";
        cin >> cal;
        switch (cal)
        {
        case '+':
            (num1.R_add(num2)).print();
            break;
        case '-':
            (num1.R_sub(num2)).print();
            break;
        case '*':
            (num1.R_mul(num2)).print();
            break;
        case '/':
            if (num2.test2 == 0)
                cout << "err!!" << endl;
            else
                (num1.R_div(num2)).print();
            break;
        default:
            cout << "?" << endl;
            goto start;
        }
    }
    else cout<<"err!!"<<endl;
    return 0;
}