#include<iostream>
using namespace std;
int main(){
    int one,two,five,count=0;
    for(five=0;five<=20;five++){
        for(two=0;two<=50;two++){
            if((five*5+two*2)<=100)
            count+=1;
        }
    }
    cout<<count<<endl;
    return 0;
}