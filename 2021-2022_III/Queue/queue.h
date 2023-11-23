#include "link.h"
class Queue
{
    Link data;

public:
    Queue();
    int empty();
    int enter(Node *p);
    int leave(Mydata &md);
    void print();
};
