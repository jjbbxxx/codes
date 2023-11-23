#include <bits/stdc++.h>
using namespace std;
const int MAX = 10; // max capacity of Stack
class Stack
{
private:
    double st[MAX]; // elements of stack
    int top;        // top of the stack
public:
    Stack() { top = -1; }            // constructor
    void push(const double &number); // check whether Stack is full before push a new element
    double pop();                    // check whether Stack is empty before pop the top element
    double &operator[](int index);   // [ ] operator
};
void Stack::push(const double &number){
    if(top==MAX-1)cout<<"stack full!!!"<<endl;
    else {
        top++;
        this->st[top]=number;
    }
}
double Stack::pop(){
    if(top==-1)cout<<"stack empty!!!"<<endl;
    else{
        top--;
    }
    return this->st[top+1];
}
double &Stack::operator[](int index){
    return st[index];
}
int main()
{
    Stack st1;
    st1.push(11.1);
    st1.push(22.2);
    st1.push(33.3);
    cout << st1.pop() << endl;
    st1[1] = 0;
    cout << st1[0] << "," << st1[1] << endl;
    return 0;
}