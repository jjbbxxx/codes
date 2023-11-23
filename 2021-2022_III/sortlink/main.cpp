#include <bits/stdc++.h>
#include "link.cpp"
#include "sortlink.cpp"
using namespace std;
int main()
{
    Link *l1=new Sortlink;
    l1->init();

    cout << l1->empty() << endl;
    Node *q;
    Mydata a;
    cin >> a;
    while (a != 0)
    {
        q = new Node;
        q->data = a;
        l1->add(q);
        cin >> a;
    }
    cout<<000;
    l1->print();
    return 0;
}