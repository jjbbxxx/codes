//�������10��100���ڵ���Ȼ����ͳ�ƴ��ڵ���ƽ��ֵ��Ԫ�ظ�����
#include<stdio.h>
#include<math.h>
int main(){
    int a[10],b[10]={},count=0;
    float avg,sum=0;
    for (int i=0;i<=9;i++){
        b[i]=abs(a[i])%100;
        printf("%d ",b[i]);
        sum+=b[i];
    }
    printf("\n");
    avg=sum/10;
    for (int i=0;i<=9;i++){
        if(b[i]>=avg)count+=1;
    }
    printf("above average(%.1f):%d\n",avg,count);
    return 0;
}
