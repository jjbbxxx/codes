#include <bits/stdc++.h>
#pragma once
typedef int Mydata;
class Node
{
public:
    Mydata data;
    Node *next;
};
class Link
{
public:
    Node *h;
    Node *init();
    int empty();
    void addbehind(Node *p);
    void print();
    int del(Mydata x);
    int getfirst(Mydata &md);
};
