#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "input the number of student(s):";
    cin >> n;
    float s = 1;
    for (int i = 0; i < n; i++)
    {
        s *= (365 - i);
        s /= 365;
    }
    srand(time(0));
    long double a = 0.0, x;
    int i;
    cout << "input stimulate number:";
    cin >> x;
    for (int j = 0; j < x; j++)
    {
        int *p = new int[365 + 1];
        for (i = 0; i < 365; i++)
            p[i] = 0;
        for (i = 1; i < n; i++)
        {
            int m;
            m = rand() % 365 + 1;
            if (!p[m])
                p[m] = 1;
            else
                break;
        }
        if (i == n)
            a++;
        delete[] p;
    }
    long double res = a / x;
    cout << s << endl;
    cout.precision(10);
    cout <<a * 1.000000000 / x << endl;
    return 0;
}