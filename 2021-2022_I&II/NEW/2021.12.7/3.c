/*3、用指针方法查找数组中是否存在值为key的元素，并删除数组中的指定元素，设计如下函数实现其功能：

函数功能：查找数组a中是否存在值为key的元素
参数说明：数组首地址a， 数组长度n, 待查找元素key
返回值：若查找成功则返回值为第一个key值元素下标, 否则返回－1
int find( int* a, int n, int key );

函数功能：删除数组a中下标为k的元素
参数说明：数组首地址a， 数组长度n, 待删除元素下标k
返回值：  若成功删除a[k]则返回1，若k>=n不能删除则返回0
int delete( int* a, int n, int k );  // 长度为n
*/

#include<stdio.h>
int find(int *a,int n, int key){
    for(int i=0;i<n;i++){
        if(*(a+i)==key)return i;
    }
    return -1;
}
int delete(int *a,int n,int k){
    if(k>=n)return 0;
    else {
        for(int i=k;i<n;i++){
            *(a+i)=*(a+i+1);
        }
        return 1;
    }
}
int main(){
    int a[6]={5,3,9,4,2,8};
    printf("%d %d\n",find(a,6,4),find(a,6,7));
    printf("%d %d\n",delete(a,6,9),delete(a,6,2));
    for(int i=0;i<6-1;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}