#include <bits/stdc++.h>
#include "point.h"
#pragma once
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
    void add(Node *p);
    void print();
    int del(Mydata x);
    int getfirst(Mydata &md);
};
