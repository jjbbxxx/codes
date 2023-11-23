#include<stdio.h>
int main(){
    int f;
    printf("input the initial number of friends:\n");
    scanf("%d",&f);
    for(int week=1;;week++){
        f=(f-1)*2;
        if(f>=150)break;
        printf("WEEK%d: %d\n",week,f);
    }
    return 0;
}