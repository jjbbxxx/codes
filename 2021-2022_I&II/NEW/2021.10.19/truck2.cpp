#include<stdio.h>
int main()
{
    float w,s,t,p;
    int x=0;
    printf("������������������˾��룺\n");
    scanf("%f %f",&w,&s);
    if(0<=s&&s<100)p=30;
    if(100<=s&&s<200)p=27.5;
    if(200<=s&&s<300)p=25;
    if(300<=s&&s<400)p=22.5;
    if(400<=s)p=20;
    t=w*s*p;
    printf("���˷�Ϊ��%.2fԪ\n",t);
    return 0;

}