#include <bits/stdc++.h>
#include"point.h"
class Node
{
public:
    Mydata data; 
    int add; // α��ַ ǰ�������
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
