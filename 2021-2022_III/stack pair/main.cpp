#include <bits/stdc++.h>
#include "link.cpp"
#include "point.cpp"
#include "stack.cpp"
using namespace std;
int myPair(const char *c)
{
    char x;
    Stack s1;
    int len = strlen(c);
    int i=0;
    while (i < len)
    {
        if (c[i] == '(')
            s1.push(c[i]);
        else if (c[i] == ')')
            if (s1.empty())
                return 0;
            else
                s1.pop(x);
        i++;
    }
    if (s1.empty())
        return 1;
    else
        return 0;
}
int main()
{
    char c[] = "and(ss(dd((sd)dd)d)()d)dd";
    if (myPair(c))
        cout << "success" << endl;
    else
        cout << "fail" << endl;
}