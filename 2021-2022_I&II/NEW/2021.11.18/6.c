//��д������һ��������1000��ʮ��������ת���ɶ�����������������������������õݹ��㷨ʵ�֣���
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