#include "sortlink.h"
void Sortlink::add(Node *p){
    Node *r=h;
    Node *q=h->next;
    h->data=1000000;
    while(1){
        if((p->data)<=(q->data)){
            p->next=q;
            r->next=p;
            return;
        }
        else{
            r=q;
            q=q->next;
        }
    }
 //   p->next=h;
//   r->next=p;
}