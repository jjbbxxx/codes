#include<iostream>
using namespace std;
int main(){
    float a,b;
    cout<<"Input 2 numbers:";
    cin>>a>>b;
    cout<<a<<'+'<<b<<'='<<a+b<<endl;
    cout<<a<<'-'<<b<<'='<<a-b<<endl;
    cout<<a<<'*'<<b<<'='<<a*b<<endl;
    if(b!=0)
    cout<<a<<'/'<<b<<'='<<a/b<<endl;
    else
    cout<<a<<'/'<<b<<"=err"<<endl;
    return 0;
}