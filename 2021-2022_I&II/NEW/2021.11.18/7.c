/*编写函数 int max( int arr[], int n ),
实现求数组中最大元素的位置，
在主函数中输出一维数组中最大元素的下标和值。*/
#include<stdio.h>
int max(int arr[],int n){
    int f=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[f])
        f=i;
    }
    return f;
}
int main(){
    int a[10]={6,8,3,4,5,9,1,4,0,2};
    printf("max:arr[%d]=%d\n",max(a,10),a[max(a,10)]);
    return 0;
}