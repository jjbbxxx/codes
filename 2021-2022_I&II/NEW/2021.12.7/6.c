/*6、	编写函数，用指针遍历字符串求串长度，不能使用库函数strlen
int strLen( char* pStr); //计算pStr中有效字符的个数，不包括\0
*/
#include<stdio.h>
int strlen(char* pStr){
    int count=0;
    for(int i=0;i<100;i++){
        if(*(pStr+i)!='\0')count++;
        else break;
    }
    return count;
}
int main(){
    char a[100];
    printf("input string:");
    gets(a);
    char* p;
    p=a;
    printf("%d\n",strlen(p));
    return 0;
}