#include<bits/stdc++.h>
using namespace std;
template <class t>
t minn(t a[],int u){
    t res=a[0];
    for(int i=0;i<u;i++){
        if(a[i]<res)
        res=a[i];
    }
    return res;
}
int main(){
    int a[]={332,45,32,3,1};
    float b[]={2.5,324.5,1.23,34.2};
    char c[]={'d','w','c','s','b'};
    cout<<minn(a,5)<<endl;
    cout<<minn(b,4)<<endl;
    cout<<minn(c,5)<<endl;
    return 0;
}