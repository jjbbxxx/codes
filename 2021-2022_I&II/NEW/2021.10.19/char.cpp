#include<stdio.h>
int main()
{
    char c;
    int x;
    printf("������һ���ַ���");
    c=getchar();
    printf("�ַ���%c��Ϊ",c);
    if('0'<=c&&c<='9')printf("����\n");
    else if('A'<=c&&c<='Z')printf("��д��ĸ\n");
    else if('a'<=c&&c<='z')printf("Сд��ĸ\n");
    else printf("�����ַ�\n");
    return 0;

}