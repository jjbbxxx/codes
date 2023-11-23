#include <bits/stdc++.h>
#include"point.h"
class Node
{
public:
    Mydata data; 
    int add; // 伪地址 前后结点异或
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
