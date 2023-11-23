#include "queue.h"
Queue ::Queue(){
    data.init();
}
int Queue::empty()
{
    if (data.empty())
        return 1;
    else
        return 0;
}
int Queue::enter(Node *p)
{
    data.addbehind(p);
    return 1;
}
int Queue::leave(Mydata &md)
{
    if (data.getfirst(md))
    {
        data.del(md);
        return 1;
    }
    else
        return 0;
}
void Queue::print(){
    data.print();
}