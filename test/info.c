#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 20
typedef struct
{
  char name[10];
  int num;
  float c;
  float by;
  float sjk;
  float lssx;
}stu;
void menu() 
{
   system("cls");  //清屏
   printf("\n\n\n\n\t\t\t*********   评教管理系统  ***********\n");
   printf("\t\t\t             Time:2000年4月12日              \n");       
   printf("\t\t\t|==========================================|\n");
   printf("\t\t\t|*************1.  录入信息  ***************|\n");
   printf("\t\t\t|*************2.  查询成绩  ***************|\n");
   printf("\t\t\t|*************3.  修改信息  ***************|\n");
   printf("\t\t\t|*************4.  添加教师  ***************|\n");
   printf("\t\t\t|*************5.  删除成绩  ***************|\n");
   printf("\t\t\t|*************6.  显示成绩  ***************|\n");
   printf("\t\t\t|*************7.    统计    ***************|\n");
   printf("\t\t\t|*************0.    退出    ***************|\n");
   printf("\t\t\t|==========================================|\n");
   printf("\t\t\t|******************************************|\n");
   printf("\n\n\t\t\t      请选择相应的功能<输入编号>:");
}
//录入信息
 
void input()
{
    FILE *fp;
    stu xs;                                   /*定义一个结构体变量来装从文件中读出来的数据*/
    if((fp=fopen("teacher.dat","ab"))==NULL)  //判断文件能否打开
	{
	   printf("can't open the file!\n");exit(0);     //正常退出
	}
    printf("\n录入格式: 姓名 教师编号 教学质量 教学态度 作业评讲 总评成绩 \n");
printf("当输入姓名为<End>结束录入\n");
    while(1)                                
	{
        scanf("%s",xs.name);
        if(strcmp(xs.name,"End")==0) break;   //判断姓名是否为LAST，用字符串判断
        scanf("%d%f%f%f%f",&xs.num,&xs.c,&xs.by,&xs.sjk,&xs.lssx);
        fwrite(&xs,sizeof(stu),1,fp);        //将成绩信息写入文件
	}
    fclose(fp);
}
//姓名定义
 
void xingming()
{
    FILE *fp;
    stu xs;
    char name[10];
    printf("\n请输入需要查询的教师姓名: ");
	scanf("%s",name);
    if((fp=fopen("teacher.dat","rb"))==NULL) 
	{
	   printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))                           //判断文件是否到达末尾，即读取文件失败时
	{
        fread(&xs,sizeof(stu),1,fp);
        if(strcmp(xs.name,name)==0)//按姓名查询时判断输入的姓名是否存在，会循环从数据中找取
		{
           printf(" 教师的信息如下:\n");
           printf("\n%10s %6s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
           printf("%10s %6d %6.2f %6.2f   %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
           break;
		}
	}
    if(feof(fp))
		printf("ERROR，查找失败!!!"); /*教师不存在*/
    fclose(fp);
}
 
//教师编号定义
 
void jiaoshibianhao()
{
    FILE *fp;
    stu xs;
    int num;
    printf("\n请输入需要查询的教师编号: ");
	scanf("%d",&num);
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file");exit(0);
	}
    while(!feof(fp))
	{
        fread(&xs,sizeof(stu),1,fp);
        if(xs.num==num)/*按编号查询时判断输入的编号是否存在，会循环从数据中找取*/
		{
             printf(" 教师的信息如下:\n");
           printf("\n%10s %6s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
           printf("%10s %6d %6.2f %6.2f   %6.2f   %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
             break;
		}
	}
     if(feof(fp)) 
		 printf("ERROR，查找失败!!!");
     fclose(fp);
}
 
//查询
 
void search()
{
	char ch1;
	system("cls");
    printf("请选择何种方式查询<编号>:\n");
    printf("1->姓名，2->教师编号:");
    ch1=getchar();              /*用字符接收*/
    switch(ch1)                 /*判断*/
  {
    case '1':xingming();break;
    case '2':jiaoshibianhao();break;
  }
getch();                       /*让屏幕停留同时按任意键返回*/ }
 
//修改:输入教师的姓名,查找该教师，若找到则修改该教师的成绩信息，并显示修改前后的结果;
 
void modify1()
{
 
    stu xs;
    FILE *fp;
    char name[10];
    printf("\n请输入要修改的教师姓名: ");
	scanf("%s",name);
    if((fp=fopen("teacher.dat","rb+"))==NULL)
	{
     	printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
         fread(&xs,sizeof(stu),1,fp);
         if(strcmp(xs.name,name)==0)                      /*判断输入要修改的姓名是否存在*/
		 {
            printf(" 修改前教师的信息:\n");
            printf("\n%10s %6s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
            printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
            printf("\n请依次输入 教学质量 教学态度 作业评讲 总评成绩的成绩:");
			scanf("%f%f%f%f",&xs.c,&xs.by,&xs.sjk,&xs.lssx);
            break;
		 }
	}
    if(!feof(fp))
	{
         printf(" \n 修改后的教师的信息如下:\n");
         printf("\n%10s %6s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
         printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
		 fseek(fp,-sizeof(stu),1);   //负号表示后退，1表示文件当前位置
		 fwrite(&xs,sizeof(stu),1,fp);  //再重新写入，同时把之前的要修改的覆盖掉
	}
    else
         printf("\nERROR，教师不存在，修改失败!!");
    fclose(fp);
	getch();
    
}
 
//修改:输入教师的编号,查找该教师，若找到则修改该教师的成绩信息，并显示修改前后的结果;
 
void modify22()
{
    stu xs;
    FILE *fp;
    int num;
    printf("\n请输入要修改的教师编号: ");
	scanf("%d",&num);
    if((fp=fopen("teacher.dat","rb+"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
 
    while(!feof(fp))
	{
       fread(&xs,sizeof(stu),1,fp);
         if(xs.num==num)/*判断输入要修改的姓名是否存在*/
		 {
            printf(" 修改前教师的信息如下:\n");
            printf("\n%10s %6s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
            printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
            printf("\n请依次输入教学质量 教学态度 作业评讲 总评成绩的成绩:");
			scanf("%f%f%f%f",&xs.c,&xs.by,&xs.sjk,&xs.lssx);
            break;
		 }
	}
    if(!feof(fp))
	{
        printf(" \n 修改后的教师的信息如下:\n");
         printf("\n%10s %6s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
         printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
		fseek(fp,-sizeof(stu),1);
		fwrite(&xs,sizeof(stu),1,fp);
	}
    else
        printf("\nERROR，教师不存在，修改失败!!");
	getch();
    fclose(fp);
    
}
//选择修改方式
void modiway()
{
    char ch1;
    system("cls");
    printf("请输入按何种方式修改<编号>:\n");
    printf("1->姓名，2->教师编号:");
    ch1=getchar();       /*用字符接收*/
    switch(ch1)          /*判断*/
	{
      case '1':modify1();break;
      case '2':modify2();break;
	}
 
    getch();/*让屏幕停留同时按任意键返回*/ 
}
 
//插入
void insert()
{
	int i=0,j,k,lenth;
    FILE *fp;
    stu s,xs[N];
    system("cls");
    printf("\n请输入添加的教师的姓名:");
	scanf("%s",&s.name);
    printf("\n教师编号:");scanf("%d",&s.num);
    printf("\n教师的成绩：教学质量、教学态度、作业评讲、总评成绩:");scanf("%f %f %f %f",&s.c,&s.by,&s.sjk,&s.lssx);
    printf("\n请输入插入到第几行:");scanf("%d",&k); 
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
        fread(&xs[i],sizeof(stu),1,fp);/*把数据读入到结构体数组中*/
        if(feof(fp)) break;
        i++;
	}
    fclose(fp);
    lenth=i;                            //记录此时lenth最大
    if(k<lenth && k>=0)                 /*k的位置要位于数组范围之内*/
	{
       for(j=lenth-1;j>=k;j--)
           xs[j+1]=xs[j];               /*一开始j是最大的，往后移一个这样移动避免数据被覆盖*/
           xs[k]=s;                     /*将输入的教师信息加入这个k位置*/
           lenth++;                   //增加一个教师空间，否则会少一个数据
       if((fp=fopen("teacher.dat","wb"))==NULL)
	   {
	        printf("不能建立文件!!\n");exit(0);
	   }
       for(i=0;i<lenth;i++)
       fwrite(&xs[i],sizeof(stu),1,fp);  //存入数据
	}
    else/*不再数组范围之内*/
	{
        if((fp=fopen("teacher.dat","ab"))==NULL) 
		{
	       printf("不能建立文件!!\n");exit(0);
		}
    fwrite(&s,sizeof(stu),1,fp);
	}
	fclose(fp);
}
 
//显示
 
void print()
{
    FILE *fp;
    stu s;
    system("cls");
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
    printf("\n%10s %s %6s %6s %6s %6s \n","姓名","教师编号","教学质量","教学态度","作业评讲","总评成绩");
    while(!feof(fp))
	{
        fread(&s,sizeof(stu),1,fp);  //从文件中读取成绩信息
           if(feof(fp)) break;       //判断是否文件尾
              printf("%10s %4d %6.2f %6.2f  %6.2f  %6.2f \n",s.name,s.num,s.c,s.by,s.sjk,s.lssx);
	}
    fclose(fp);
    getch();
}
 
//删除:输入教师姓名，若该教师存在，则删除，并显示删除后余下的教师成绩信息
 
void delete1()
{
 
    stu xs[N];
    FILE *fp;
    char name[10];
    int i=0,len,k=-1/*k<0是为后面if判断用的*/;
    system("cls");
    printf("\n请输入要删除的教师姓名: ");scanf("%s",name);
    if((fp=fopen("teacher.dat","rb+"))==NULL) 
	{
	    printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
       fread(&xs[i],sizeof(stu),1,fp);
       if(feof(fp)) break;
       if(strcmp(xs[i].name,name)==0) k=i;
       i++;
	}
    fclose(fp);
 
//以下是删除后重新写文件
 
    len=i;/*结构体数组上限*/
    if(k>=0)/*k>0说明找到删除教师位置*/
	{
      if((fp=fopen("teacher.dat","wb+"))==NULL) 
	  {
	      printf("can't open the file!\n");exit(0);
	  }
      for(i=0;i<len;i++)
	  {
      if(i==k) continue;/*从这个位置开始写入*/
      fwrite(&xs[i],sizeof(stu),1,fp);
	  }
      fclose(fp);
	}
      else {printf("ERROR,删除失败!!!\n");getch();} /*失败后重新返回菜单*/
      print();
}
 
 
//删除:输入教师编号，若该教师存在，则删除，并显示删除后余下的教师成绩信息
 
void delete2()
{
    stu xs[N];
    FILE *fp;
    int num;
    int i=0,len,k=-1/*k<0是为后面if判断用的*/;
    system("cls");
    printf("\n请输入要删除的教师编号: ");
	scanf("%d",&num);
    if((fp=fopen("teacher.dat","rb+"))==NULL) 
	{
	printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
        fread(&xs[i],sizeof(stu),1,fp);
        if(feof(fp)) break;
        if(xs[i].num==num)
			k=i;
            i++;
	}
    fclose(fp);
//以下是删除后重新写文件
 
    len=i;/*结构体数组上限*/
    if(k>=0)/*k>0说明找到删除教师位置*/
	{
    if((fp=fopen("teacher.dat","wb+"))==NULL) 
	{
	     printf("can't openfile!\n");exit(0);
	}
    for(i=0;i<len;i++)
	{
       if(i==k) continue;/*从这个位置开始写入*/
       fwrite(&xs[i],sizeof(stu),1,fp);
	}
    fclose(fp);
	}
    else {printf("ERROR,删除失败!!!\n");getch();} /*失败后重新返回菜单*/
    print();
}
 
 
//删除
 
void deleteway()
{
    char ch1;
    system("cls");
    printf("请输入按何种方式删除:\n");
    printf("1->姓名，2->教师编号:");
    ch1=getchar();/*用字符接收*/
    switch(ch1)/*判断*/
	{
	case '1':delete1();break;
    case '2':delete2();break;
	}
	getch();/*让屏幕停留同时按任意键返回*/
}
 
//统计总评成绩情况
 
void count() 
{
    int i=0,j=0,k=0,l=0,m=0,n,p,q,r,t,u;   //j,k,m,l分别是指各个分数段，n,p,q,r也是
    FILE *fp;
    stu s[N], *p1[N],*p2[N],*p3[N],*p4[N];/*用指针数组*/
    system("cls");
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
        fread(&s[i++],sizeof(stu),1,fp);/*读入数据*/
        if(feof(fp)) break;  //到文件末尾中断程序
	}
    t=i;i=0;           //t 指最大
    for(u=0;u<t;u++)/*以下每个指针数组用于指向各分数段的教师信息*/
	{
        if(s[i].c<5) 
		{
			p1[j++]=&s[i++];continue;
		}                                     /*每个教师信息只能位于一个分数段*/
        if(s[i].c>=6 && s[i].c<8) 
		{
			p2[k++]=&s[i++];continue;
		}
        if(s[i].c>=8) 
		{
			p3[l++]=&s[i++];continue;
		}
       
	}
    printf("     不合格:姓名 教师编号 总评成绩\n");
    for(n=0;n<j-1;n++)
	{
        printf("%14s %4d %6.2f\n",p1[n]->name,p1[n]->num,p1[n]->c);      //逐个显示个分数段信息，显示上面指针的内容
	}
    printf(" 6-8分之间:姓名 教师编号 总评成绩\n");
    for(p=0;p<k;p++)
	{
        printf("%16s %4d %6.2f\n",p2[p]->name,p2[p]->num,p2[p]->c);
	}
    printf(" 9-10分之间:姓名 教师编号 总评成绩\n");
    for(q=0;q<l;q++)
	{
        printf("%16s %4d %6.2f\n",p3[q]->name,p3[q]->num,p3[q]->c);
	}
    
    fclose(fp);
    getch();
}
 
 
//菜单选择
 
void main()
{
	char ch;
    while(1)
	{
      menu();// 显示菜单
      ch=getch();//选择菜单
      if(ch=='0') 
		  break;
      switch(ch)//判断功能项
	  {
      case '1':input();break;
      case '2':search();break;
      case '3':modiway();break;
      case '4':insert();break;
	  case '5':deleteway();break;
      case '6':print();break;
	  case '7':count();break;
	  }
	} 
	printf("\n\n\n\t\t\t\tWelcome to use,Goodbye!\02!\n");
}

