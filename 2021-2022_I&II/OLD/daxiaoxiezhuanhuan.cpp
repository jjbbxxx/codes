#include<stdio.h>

int main()
{
   char a,b;
   printf("请输入一个小写字母：");
   a=getchar();
   b=a-32;
   putchar(b);
   return 0;
}
