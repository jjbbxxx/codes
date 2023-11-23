#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Link
{
public:
    Node *h;
    Node *init();
    int empty();
    void add(Node *p);
    void print();
    int del(int x);
};
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
    cout << "head(" << h << ')';
    while (p != h)
    {
        cout << "->";
        cout << p << ":" << p->data;
        p = p->next;
    }
    cout << endl;
}
int Link::del(int x)
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
int main()
{
    Link l1;
    l1.init();
    cout << l1.empty() << endl;
    Node *q;
    int a;
    cin >> a;
    while (a != 0)
    {
        q = new Node;
        q->data = a;
        l1.add(q);
        cin >> a;
    }
    l1.print();
    l1.del(5);
    l1.print();
    return 0;
}