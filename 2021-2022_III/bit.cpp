#include<bits/stdc++.h>
using namespace std;
int main(){
    short int a=0xe;// 1110
    short int b=0x7;// 0111
    short int c=a>>2;// 0110
    cout<<c<<"  "<<hex<<c<<"  "<<oct<<c<<"  "<<bitset<16>(c);
    return 0;
}