//编写函数将一个不大于1000的十进制整数转换成二进制数，并在主函数中输出（采用递归算法实现）。
#include<stdio.h>
int dec2bin(int n){
    if(n/2>0)dec2bin(n/2);
    printf("%d",n%2);

}
int main(){
    int n;
    scanf("%d",&n);
    dec2bin(n);
    return 0;
}