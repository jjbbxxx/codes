/*6��	��д��������ָ������ַ����󴮳��ȣ�����ʹ�ÿ⺯��strlen
int strLen( char* pStr); //����pStr����Ч�ַ��ĸ�����������\0
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