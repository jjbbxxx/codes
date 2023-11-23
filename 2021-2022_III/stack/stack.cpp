#include "stack.h"
Stack::Stack(){
    sdata.init();
}
int Stack::empty(){
    return sdata.empty();
}
int Stack::push(Mydata md){
    Node *p=new Node;
    p->data =md;
    sdata.add(p);
    return 1;
}
int Stack::pop(Mydata &md){
    if(sdata.getfirst(md)){
    sdata.del(md);
    return 1;
    }
    else return 0;
}