/* 2、	寻找n个元素的整型数组中最大元素的位置
int* max( int *a , int n) ;  //返回最大元素的地址
*/
int *max(int *a,int n){
    int *b=&a[0];
    for(int i=1;i<n;i++){
        if(a[i]>*b)
        b=&a[i];
    }
    return b;
}
#include<stdio.h>
int main(){
    int *p;
    int a[5]={6,3,8,5,1};
    p=max(a,5);
    printf("max:%d\n",*p);
    return 0;
}