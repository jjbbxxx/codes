#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout<<"input m & n:";
    cin >> m >> n;
    cout<<"input "<<m*n<<" numbers:";
    int **p = new int *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    int sum = 0, f1 = p[0][0], f2 = p[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += p[i][j];
            if (p[i][j] > f1)
                f1 = p[i][j];
            if (p[i][j] < f2)
                f2 = p[i][j];
        }
    }
    cout << "sum=" << sum << endl;
    cout << "max=" << f1 << endl;
    cout << "min=" << f2 << endl;
    for (int i = 0; i < m; i++)
        delete[] p[i];
    delete[] p;
    return 0;
}