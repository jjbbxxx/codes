#include<stdio.h>
int main()
{
    float t,p,s,w;
    int n;
    printf("������������������˾��룺\n");
    scanf("%f %f",&w,&s);
    n=int(s)/100; 
    switch(n){
        case 0: p=30;
        break;
        case 1: p=27.5;
        break;
        case 2: p=25;
        break;
        case 3: p=22.5;
        break;
        default: p=20;
    }
    t=w*s*p;
    printf("���˷�Ϊ��%.2fԪ\n",t);
    return 0;

}