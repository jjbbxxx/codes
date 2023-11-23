/*编写求指数幂的函数，设计并调用函数。不要用任何数学库函数。
1）  用迭代的算法实现函数，指数exponent可为正整数，负整数或零。
2）用递归算法实现函数，假设exponent是大于或等于1的整数值，底数base为整数。
*/
int math1(int x,int a){
    int rst=1;
    for(int i=0;i<a;i++){
        rst*=x;
    }
    return rst;
}
int math2(int x,int a){
    if(a>1)x*=math2(x,a-1);
    return x;
}
#include<stdio.h>
int main(){
    int x,a;
    scanf("%d %d",&x,&a);
    printf("%d %d\n",math1(x,a),math2(x,a));
    return 0;
}