#include <bits/stdc++.h>
#include "link.cpp"
#include "stack.cpp"
using namespace std;
int main(){
    Stack s;
    char c[]="hello";
    s.write(c);
    (s.encode()).print();
    ((s.encode()).decode()).print();
    return 0;
}