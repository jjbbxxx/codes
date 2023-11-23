#include<bits/stdc++.h> 
#include<stdio.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    printf("-----------欢迎来玩猜数游戏！-----------\n");
    printf("按回车键开始");
    getchar ();
    int y=0,scr=0;
    setting:  
    int x=0,mtd;
    while(x==0){
    x=1;
    char set;
    printf("\n请设置游戏难度(E,N,H),并按回车键继续：\n\n");
    printf("E:简单模式\n");
    printf("N:正常模式\n");
    printf("H:困难模式\n\n");
    scanf("%c",&set);
    if(y==0)getchar();
    if(set=='e'||set=='E')mtd=6;
    else if(set=='n'||set=='N')mtd=3;
    else if(set=='h'||set=='H')mtd=1;
    else{
        printf("请输入正确的字符！\n\n");
        x=0;
    }
    }
    start:
    int a,num,rst=0,i;
    srand((unsigned)time(NULL));
    a = rand();
    num=a%10+1;
    printf("\nemm...我想到了一个1~10之间的数字，请你在_%d_回合以内猜中它！\n\n※※※※※输入其他字符可随时结束游戏.※※※※※\n\n",mtd);
    for(i=1;i<=mtd;i++){
        printf("-----------回合%d-----------\n请输入你的答案，并按回车键继续：\n",i);
        jug:
        int ans;
		 
        std::cin>>ans;
        if(ans==num){
            rst=1;
            scr+=1;
            goto result;
        }
        else if(ans<num&&ans>0){
            printf("数字偏小！\n");
        }
        else if(ans>num&&ans<11){
            printf("数字偏大！\n");
        }
        else if(ans==0){
            rst=3;
            goto result;
        }
        else{
        	printf("输入的答案有误，重新输入！\n");
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
    printf("\n恭喜！你在%d回合中猜中了答案！\n得分：%d.\n\n输入“1”可继续游戏，输入“0”可重新设置难度，输入其他字符退出游戏。\n",i,scr);
        int bye1;
        std::cin>>bye1;
        if(bye1==1)goto start;
        else if(bye1==0){y=1;
        goto setting;
        }
        else goto exit;
        break;
    case 2:
    printf("\n你输了！没有在%d回合以内猜中答案！\n正确答案是%d.\n得分：%d.\n\n输入“1”可继续游戏，输入“0”可重新设置难度，输入其他字符退出游戏。\n",mtd,num,scr);
        int bye2;
        std::cin>>bye2;
        if(bye2==1)goto start;
        else if(bye2==0){y=1;
        goto setting;
        }
        else goto exit;
        break;
    case 3:
        printf("\n啊欧，你放弃了。\n得分：%d.\n",scr);
        goto exit;
        break;
    default:
        break;
    }

    exit:
    printf("\n感谢您的游玩，再见！\n");
    return 0;
}
