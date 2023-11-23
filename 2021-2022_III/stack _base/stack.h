#include "link.h"
class Stack{
    Link sdata;
    long int len;
    public:
    int empty();
    int push(Mydata md);
    int pop(Mydata &md);
    int write(const char c[]);
    void print();
    Stack encode();
    Stack decode();
    Stack();
};