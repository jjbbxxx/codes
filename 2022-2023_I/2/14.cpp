#include <bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    int num;
    queue<int> q[10];
    while ((c = getchar()) != '\n')
    {
        if (c < '0' || c > '9')
        {
            cout << "error" << endl;
            return 0;
        }
        else
        {
            num = c - '0';
            q[num].push(num);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        while (!q[i].empty())
        {
            cout << q[i].front() << ' ';
            q[i].pop();
        }
    }
    cout << endl;
    return 0;
}