#include<stdio.h>
int main()
{
    char c;
    int x;
    printf("请输入一个字符：");
    c=getchar();
    printf("字符“%c”为",c);
    if('0'<=c&&c<='9')printf("数字\n");
    else if('A'<=c&&c<='Z')printf("大写字母\n");
    else if('a'<=c&&c<='z')printf("小写字母\n");
    else printf("其他字符\n");
    return 0;

}