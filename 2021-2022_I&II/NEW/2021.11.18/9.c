/*ͳ��M��ѧ����N�ſεĳɼ�, �ֱ�ʵ�����¹��ܣ�
��1������M��ѧ�������ֺͳɼ�
��2��double ave( int grade[], int n); ����ÿ��ͬѧ��ƽ����
��3��double pass(int grade[][N], int n ); ͳ��ÿ�ſγ̵ļ����ʡ�
��4��void print(int grade[][N], int average[]) �����¸�ʽ������гɼ���
*/
#include<stdio.h>
#define M 5
#define N 3
double ave( double grade[][N], int n){
    double avg=0;
    for(int i=0;i<N;i++){
        avg+=grade[n][i];
    }
    avg/=N;
    return avg;
}
double pass(double grade[][N],int n){
    double p=0;
    for(int i=0;i<M;i++){
        if(grade[i][n]<60)
        p++;
    }
    p=(M-p)/M;
    return p;
}
void print();

int main(){
    char name[M]={'a','b','c','d','e'};
    double grade[M][N]={{80,75,92},{61,65,71},{50,56,70},{85,87,90},{76,50,65}};
    print(name,grade);

    return 0;
}

void print(char name
[M],double grade[M][N]){
    printf(" __________________________________\n");
    printf("|        |");
    for(int i=0;i<M;i++)printf("%3c",name[i]);
    printf(" |  rate  |\n");
    printf("|  Math  |");
    for(int i=0;i<M;i++)printf("%3.0f",grade[i][0]);
    printf(" |  %2.1f   |\n",pass(grade,0));
    printf("|   C    |");
    for(int i=0;i<M;i++)printf("%3.0f",grade[i][1]);
    printf(" |  %2.1f   |\n",pass(grade,1));
    printf("|English |");
    for(int i=0;i<M;i++)printf("%3.0f",grade[i][2]);
    printf(" |  %2.1f   |\n",pass(grade,2));
    printf("|AVERAGE | ");
    for(int i=0;i<M;i++)printf("%.0f ",ave(grade,i));
    printf("|        |\n");
    printf(" ����������������������������������\n");

    return ;
}