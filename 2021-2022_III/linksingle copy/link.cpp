#include <bits/stdc++.h>
#include "link.h"
#include "point.h"
using namespace std;
int Link::empty()
{
    if (h->add == (int)h)
        return 1;
    else
        return 0;
}
Node *Link::init()
{
    h = new Node;
    h->add = 0;
    return h;
}
void Link::add(Node *p)
{
    Node *q;
    q = (Node *)h->add;
    p->add = (int)h ^ h->add;
    h->add = (int)p;
    if (q)
        q->add = (int)p ^ ((int)h ^ q->add);
    h->add = (int)p;
}
void Link::print()
{
    Node *p = (Node *)h->add;
    Node *q=h;
    Node *r;
    cout << "head(" << h << ')';
    while (p != 0)
    {
        cout << "->";
        cout << p << ":" << p->data;
        r=p;
        p = (Node *)((int)q^p->add);
        q=r;
    }
    cout << endl;
}
/*int Link::del(Mydata x)
{
    Node *q = h, *p = h->next;
    while (p != h)
    {
        if (p->data == x)
        {
            q->next = p->next;
            delete p;
            return 1;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    return 0;
}*/