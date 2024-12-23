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
    return h;
}
void Link::add(Node *p)
{
    p->next = h->next;
    h->next = p;
}
void Link::print()
{
    Node *p = h->next;
    while (p != h)
    {
        cout <<p->data;
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
int Link::getfirst(Mydata &md)
{
    if (empty())
        return 0;
    else
    {
        md = h->next->data;
        return 1;
    }
}
Mydata Link::get(int n){
    Mydata a;
    Node *p=h->next;
    for(int i=0;i<n;i++){
        p=p->next;
    }
    a=p->data;
    return a;
}