#include <bits/stdc++.h>
#include"point.h"
class Node
{
public:
    Node *prior;
    Mydata data;
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
    int del(Mydata x);
};
