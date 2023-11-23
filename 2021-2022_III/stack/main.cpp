#include <bits/stdc++.h>
#include "link.cpp"
#include "point.cpp"
#include "stack.cpp"
using namespace std;
int main(){
    Mydata md;
    Stack s1;
    s1.push('a');
    s1.push('b');
    s1.pop(md);
    cout<<md<<endl;
    s1.push('c');
    while(!s1.empty()){
        s1.pop(md);
        cout<<md<<endl;
    }
}