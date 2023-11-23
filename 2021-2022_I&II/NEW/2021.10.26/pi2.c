#include<stdio.h>
int main(){
    double p=1,a; 
    for(float n=1;n<=100000;n++){
        a=(2*n)/(2*n-1);
        a*=(2*n)/(2*n+1);
        p*=a;
    }
    printf("pi=%f\n",p*2);
    return 0;
}
