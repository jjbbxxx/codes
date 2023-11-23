#include <bits/stdc++.h>
#include "link.h"
using namespace std;
int Link::empty()
{
    if (h->next == h)
        return 1;
    else
        return 0;
}
Node *Link::init()
{
    h = new Node;
    h->next = h;
    h->prior = h;
    return h;
}
void Link::add(Node *p)
{
    p->next = h->next;
    p->prior = h;
    h->next->prior = p;
    h->next =p;
}
void Link::print()
{
    Node *p = h->next;
    cout << "head(" << h << ')';
    while (p != h)
    {
        cout << "->";
        cout << p << ":" << p->data;
        p = p->next;
    }
    cout << endl;
}
int Link::del(Mydata x)
{
    Node *q = h, *p = h->next;
    while (p != h)
    {
        if (p->data == x)
        {
            q->next = p->next;
            p->next->prior=q;
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
}