#include<stdio.h>
int main()
{
    float inv,itr1;
    int y=0;
    printf("input original investment:\n");
    scanf("%f",&inv);
    float da=inv,de=inv;
    itr1=inv/10;
    for(y;da>=de;y++) {
        da+=itr1;
        de*=1.05;
    }
    printf("After%dyears,Daphne:$%.2f,Deirdre:&%.2f.\n",y,da,de);
    
    return 0;
}