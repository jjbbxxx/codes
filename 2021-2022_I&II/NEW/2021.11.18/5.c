/*��д��ָ���ݵĺ�������Ʋ����ú�������Ҫ���κ���ѧ�⺯����
1��  �õ������㷨ʵ�ֺ�����ָ��exponent��Ϊ�����������������㡣
2���õݹ��㷨ʵ�ֺ���������exponent�Ǵ��ڻ����1������ֵ������baseΪ������
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