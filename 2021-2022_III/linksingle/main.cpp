#include <bits/stdc++.h>
#include "link.cpp"
#include "point.cpp"
using namespace std;
int main()
{
    Link l1;
    l1.init();
    cout << l1.empty() << endl;
    Node *q;
    Mydata a;
    cin >> a;
    while (a != 0)
    {
        q = new Node;
        q->data = a;
        l1.add(q);
        cin >> a;
    }
    l1.print();
    cin>>a;
    l1.del(a);
    l1.print();
    return 0;
}