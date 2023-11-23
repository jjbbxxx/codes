#include <bits/stdc++.h>
#include "link.cpp"
#include "queue.cpp"
using namespace std;
int main()
{
    Queue q1;
    cout<<q1.empty()<<endl;
    Mydata a;
    cin>>a;
    while(a!=0){
        Node *p=new Node;
        p->data=a;
        q1.enter(p);
        cin>>a;
    }
    q1.print();
    Node *test=new Node;
    test->data=1234;
    q1.enter(test);
    q1.print();
    Mydata md;
    q1.leave(md);
    cout<<md<<endl;
    q1.print();
    return 0;
}