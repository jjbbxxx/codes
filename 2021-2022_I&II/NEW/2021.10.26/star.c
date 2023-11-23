#include<stdio.h>
int main()
{
    for(int i=1;i<=6;i++){
    for(int t=1;t<=6-i;t++)printf(" ");
    for(int u=1;u<=2*i-1;u++)printf("*");
    printf("\n");
    }
    return 0;
}