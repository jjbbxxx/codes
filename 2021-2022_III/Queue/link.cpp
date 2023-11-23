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
void Link::addbehind(Node *p)
{
    Node *q=h;
    if(this->empty()){
        h->next=p;
        p->next=h;
    }
    else if(q->next->next==h){
        q->next->next=p;
        p->next=h;
    }
    else{
    while(q->next->next!=h){
        q=q->next;
    }
    q->next->next=p;
    p->next=h;
    }

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