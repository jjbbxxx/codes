/*3����ָ�뷽�������������Ƿ����ֵΪkey��Ԫ�أ���ɾ�������е�ָ��Ԫ�أ�������º���ʵ���书�ܣ�

�������ܣ���������a���Ƿ����ֵΪkey��Ԫ��
����˵���������׵�ַa�� ���鳤��n, ������Ԫ��key
����ֵ�������ҳɹ��򷵻�ֵΪ��һ��keyֵԪ���±�, ���򷵻أ�1
int find( int* a, int n, int key );

�������ܣ�ɾ������a���±�Ϊk��Ԫ��
����˵���������׵�ַa�� ���鳤��n, ��ɾ��Ԫ���±�k
����ֵ��  ���ɹ�ɾ��a[k]�򷵻�1����k>=n����ɾ���򷵻�0
int delete( int* a, int n, int k );  // ����Ϊn
*/

#include<stdio.h>
int find(int *a,int n, int key){
    for(int i=0;i<n;i++){
        if(*(a+i)==key)return i;
    }
    return -1;
}
int delete(int *a,int n,int k){
    if(k>=n)return 0;
    else {
        for(int i=k;i<n;i++){
            *(a+i)=*(a+i+1);
        }
        return 1;
    }
}
int main(){
    int a[6]={5,3,9,4,2,8};
    printf("%d %d\n",find(a,6,4),find(a,6,7));
    printf("%d %d\n",delete(a,6,9),delete(a,6,2));
    for(int i=0;i<6-1;i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}