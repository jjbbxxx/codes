#include<bits/stdc++.h> 
#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    printf("-----------��ӭ���������Ϸ��-----------\n");
    printf("���س�����ʼ");
    getchar ();
    int y=0,scr=0;
    setting:  
    int x=0,mtd;
    while(x==0){
    x=1;
    char set;
    printf("\n��������Ϸ�Ѷ�(E,N,H),�����س���������\n\n");
    printf("E:��ģʽ\n");
    printf("N:����ģʽ\n");
    printf("H:����ģʽ\n\n");
    scanf("%c",&set);
    if(y==0)getchar();
    if(set=='e'||set=='E')mtd=6;
    else if(set=='n'||set=='N')mtd=3;
    else if(set=='h'||set=='H')mtd=1;
    else{
        printf("��������ȷ���ַ���\n\n");
        x=0;
    }
    }
    start:
    int a,num,rst=0,i;
    srand((unsigned)time(NULL));
    a = rand();
    num=a%10+1;
    printf("\nemm...���뵽��һ��1~10֮������֣�������_%d_�غ����ڲ�������\n\n�������������������ַ�����ʱ������Ϸ.����������\n\n",mtd);
    for(i=1;i<=mtd;i++){
        printf("-----------�غ�%d-----------\n��������Ĵ𰸣������س���������\n",i);
        jug:
        int ans;
		 
        std::cin>>ans;
        if(ans==num){
            rst=1;
            scr+=1;
            goto result;
        }
        else if(ans<num&&ans>0){
            printf("����ƫС��\n");
        }
        else if(ans>num&&ans<11){
            printf("����ƫ��\n");
        }
        else if(ans==0){
            rst=3;
            goto result;
        }
        else{
        	printf("����Ĵ������������룡\n");
            ans=0;
        	goto jug;
        }
    }
    rst=2;
    scr-=1;


    result:
    switch (rst)
    {
    case 1:
    printf("\n��ϲ������%d�غ��в����˴𰸣�\n�÷֣�%d.\n\n���롰1���ɼ�����Ϸ�����롰0�������������Ѷȣ����������ַ��˳���Ϸ��\n",i,scr);
        int bye1;
        std::cin>>bye1;
        if(bye1==1)goto start;
        else if(bye1==0){y=1;
        goto setting;
        }
        else goto exit;
        break;
    case 2:
    printf("\n�����ˣ�û����%d�غ����ڲ��д𰸣�\n��ȷ����%d.\n�÷֣�%d.\n\n���롰1���ɼ�����Ϸ�����롰0�������������Ѷȣ����������ַ��˳���Ϸ��\n",mtd,num,scr);
        int bye2;
        std::cin>>bye2;
        if(bye2==1)goto start;
        else if(bye2==0){y=1;
        goto setting;
        }
        else goto exit;
        break;
    case 3:
        printf("\n��ŷ��������ˡ�\n�÷֣�%d.\n",scr);
        goto exit;
        break;
    default:
        break;
    }

    exit:
    printf("\n��л�������棬�ټ���\n");
    return 0;
}
