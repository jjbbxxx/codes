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
   system("cls");  //����
   printf("\n\n\n\n\t\t\t*********   ���̹���ϵͳ  ***********\n");
   printf("\t\t\t             Time:2000��4��12��              \n");       
   printf("\t\t\t|==========================================|\n");
   printf("\t\t\t|*************1.  ¼����Ϣ  ***************|\n");
   printf("\t\t\t|*************2.  ��ѯ�ɼ�  ***************|\n");
   printf("\t\t\t|*************3.  �޸���Ϣ  ***************|\n");
   printf("\t\t\t|*************4.  ��ӽ�ʦ  ***************|\n");
   printf("\t\t\t|*************5.  ɾ���ɼ�  ***************|\n");
   printf("\t\t\t|*************6.  ��ʾ�ɼ�  ***************|\n");
   printf("\t\t\t|*************7.    ͳ��    ***************|\n");
   printf("\t\t\t|*************0.    �˳�    ***************|\n");
   printf("\t\t\t|==========================================|\n");
   printf("\t\t\t|******************************************|\n");
   printf("\n\n\t\t\t      ��ѡ����Ӧ�Ĺ���<������>:");
}
//¼����Ϣ
 
void input()
{
    FILE *fp;
    stu xs;                                   /*����һ���ṹ�������װ���ļ��ж�����������*/
    if((fp=fopen("teacher.dat","ab"))==NULL)  //�ж��ļ��ܷ��
	{
	   printf("can't open the file!\n");exit(0);     //�����˳�
	}
    printf("\n¼���ʽ: ���� ��ʦ��� ��ѧ���� ��ѧ̬�� ��ҵ���� �����ɼ� \n");
printf("����������Ϊ<End>����¼��\n");
    while(1)                                
	{
        scanf("%s",xs.name);
        if(strcmp(xs.name,"End")==0) break;   //�ж������Ƿ�ΪLAST�����ַ����ж�
        scanf("%d%f%f%f%f",&xs.num,&xs.c,&xs.by,&xs.sjk,&xs.lssx);
        fwrite(&xs,sizeof(stu),1,fp);        //���ɼ���Ϣд���ļ�
	}
    fclose(fp);
}
//��������
 
void xingming()
{
    FILE *fp;
    stu xs;
    char name[10];
    printf("\n��������Ҫ��ѯ�Ľ�ʦ����: ");
	scanf("%s",name);
    if((fp=fopen("teacher.dat","rb"))==NULL) 
	{
	   printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))                           //�ж��ļ��Ƿ񵽴�ĩβ������ȡ�ļ�ʧ��ʱ
	{
        fread(&xs,sizeof(stu),1,fp);
        if(strcmp(xs.name,name)==0)//��������ѯʱ�ж�����������Ƿ���ڣ���ѭ������������ȡ
		{
           printf(" ��ʦ����Ϣ����:\n");
           printf("\n%10s %6s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
           printf("%10s %6d %6.2f %6.2f   %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
           break;
		}
	}
    if(feof(fp))
		printf("ERROR������ʧ��!!!"); /*��ʦ������*/
    fclose(fp);
}
 
//��ʦ��Ŷ���
 
void jiaoshibianhao()
{
    FILE *fp;
    stu xs;
    int num;
    printf("\n��������Ҫ��ѯ�Ľ�ʦ���: ");
	scanf("%d",&num);
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file");exit(0);
	}
    while(!feof(fp))
	{
        fread(&xs,sizeof(stu),1,fp);
        if(xs.num==num)/*����Ų�ѯʱ�ж�����ı���Ƿ���ڣ���ѭ������������ȡ*/
		{
             printf(" ��ʦ����Ϣ����:\n");
           printf("\n%10s %6s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
           printf("%10s %6d %6.2f %6.2f   %6.2f   %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
             break;
		}
	}
     if(feof(fp)) 
		 printf("ERROR������ʧ��!!!");
     fclose(fp);
}
 
//��ѯ
 
void search()
{
	char ch1;
	system("cls");
    printf("��ѡ����ַ�ʽ��ѯ<���>:\n");
    printf("1->������2->��ʦ���:");
    ch1=getchar();              /*���ַ�����*/
    switch(ch1)                 /*�ж�*/
  {
    case '1':xingming();break;
    case '2':jiaoshibianhao();break;
  }
getch();                       /*����Ļͣ��ͬʱ�����������*/ }
 
//�޸�:�����ʦ������,���Ҹý�ʦ�����ҵ����޸ĸý�ʦ�ĳɼ���Ϣ������ʾ�޸�ǰ��Ľ��;
 
void modify1()
{
 
    stu xs;
    FILE *fp;
    char name[10];
    printf("\n������Ҫ�޸ĵĽ�ʦ����: ");
	scanf("%s",name);
    if((fp=fopen("teacher.dat","rb+"))==NULL)
	{
     	printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
         fread(&xs,sizeof(stu),1,fp);
         if(strcmp(xs.name,name)==0)                      /*�ж�����Ҫ�޸ĵ������Ƿ����*/
		 {
            printf(" �޸�ǰ��ʦ����Ϣ:\n");
            printf("\n%10s %6s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
            printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
            printf("\n���������� ��ѧ���� ��ѧ̬�� ��ҵ���� �����ɼ��ĳɼ�:");
			scanf("%f%f%f%f",&xs.c,&xs.by,&xs.sjk,&xs.lssx);
            break;
		 }
	}
    if(!feof(fp))
	{
         printf(" \n �޸ĺ�Ľ�ʦ����Ϣ����:\n");
         printf("\n%10s %6s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
         printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
		 fseek(fp,-sizeof(stu),1);   //���ű�ʾ���ˣ�1��ʾ�ļ���ǰλ��
		 fwrite(&xs,sizeof(stu),1,fp);  //������д�룬ͬʱ��֮ǰ��Ҫ�޸ĵĸ��ǵ�
	}
    else
         printf("\nERROR����ʦ�����ڣ��޸�ʧ��!!");
    fclose(fp);
	getch();
    
}
 
//�޸�:�����ʦ�ı��,���Ҹý�ʦ�����ҵ����޸ĸý�ʦ�ĳɼ���Ϣ������ʾ�޸�ǰ��Ľ��;
 
void modify22()
{
    stu xs;
    FILE *fp;
    int num;
    printf("\n������Ҫ�޸ĵĽ�ʦ���: ");
	scanf("%d",&num);
    if((fp=fopen("teacher.dat","rb+"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
 
    while(!feof(fp))
	{
       fread(&xs,sizeof(stu),1,fp);
         if(xs.num==num)/*�ж�����Ҫ�޸ĵ������Ƿ����*/
		 {
            printf(" �޸�ǰ��ʦ����Ϣ����:\n");
            printf("\n%10s %6s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
            printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
            printf("\n�����������ѧ���� ��ѧ̬�� ��ҵ���� �����ɼ��ĳɼ�:");
			scanf("%f%f%f%f",&xs.c,&xs.by,&xs.sjk,&xs.lssx);
            break;
		 }
	}
    if(!feof(fp))
	{
        printf(" \n �޸ĺ�Ľ�ʦ����Ϣ����:\n");
         printf("\n%10s %6s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
         printf("%10s %6d %6.2f %6.2f  %6.2f  %6.2f \n",xs.name,xs.num,xs.c,xs.by,xs.sjk,xs.lssx);
		fseek(fp,-sizeof(stu),1);
		fwrite(&xs,sizeof(stu),1,fp);
	}
    else
        printf("\nERROR����ʦ�����ڣ��޸�ʧ��!!");
	getch();
    fclose(fp);
    
}
//ѡ���޸ķ�ʽ
void modiway()
{
    char ch1;
    system("cls");
    printf("�����밴���ַ�ʽ�޸�<���>:\n");
    printf("1->������2->��ʦ���:");
    ch1=getchar();       /*���ַ�����*/
    switch(ch1)          /*�ж�*/
	{
      case '1':modify1();break;
      case '2':modify2();break;
	}
 
    getch();/*����Ļͣ��ͬʱ�����������*/ 
}
 
//����
void insert()
{
	int i=0,j,k,lenth;
    FILE *fp;
    stu s,xs[N];
    system("cls");
    printf("\n��������ӵĽ�ʦ������:");
	scanf("%s",&s.name);
    printf("\n��ʦ���:");scanf("%d",&s.num);
    printf("\n��ʦ�ĳɼ�����ѧ��������ѧ̬�ȡ���ҵ�����������ɼ�:");scanf("%f %f %f %f",&s.c,&s.by,&s.sjk,&s.lssx);
    printf("\n��������뵽�ڼ���:");scanf("%d",&k); 
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
        fread(&xs[i],sizeof(stu),1,fp);/*�����ݶ��뵽�ṹ��������*/
        if(feof(fp)) break;
        i++;
	}
    fclose(fp);
    lenth=i;                            //��¼��ʱlenth���
    if(k<lenth && k>=0)                 /*k��λ��Ҫλ�����鷶Χ֮��*/
	{
       for(j=lenth-1;j>=k;j--)
           xs[j+1]=xs[j];               /*һ��ʼj�����ģ�������һ�������ƶ��������ݱ�����*/
           xs[k]=s;                     /*������Ľ�ʦ��Ϣ�������kλ��*/
           lenth++;                   //����һ����ʦ�ռ䣬�������һ������
       if((fp=fopen("teacher.dat","wb"))==NULL)
	   {
	        printf("���ܽ����ļ�!!\n");exit(0);
	   }
       for(i=0;i<lenth;i++)
       fwrite(&xs[i],sizeof(stu),1,fp);  //��������
	}
    else/*�������鷶Χ֮��*/
	{
        if((fp=fopen("teacher.dat","ab"))==NULL) 
		{
	       printf("���ܽ����ļ�!!\n");exit(0);
		}
    fwrite(&s,sizeof(stu),1,fp);
	}
	fclose(fp);
}
 
//��ʾ
 
void print()
{
    FILE *fp;
    stu s;
    system("cls");
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
    printf("\n%10s %s %6s %6s %6s %6s \n","����","��ʦ���","��ѧ����","��ѧ̬��","��ҵ����","�����ɼ�");
    while(!feof(fp))
	{
        fread(&s,sizeof(stu),1,fp);  //���ļ��ж�ȡ�ɼ���Ϣ
           if(feof(fp)) break;       //�ж��Ƿ��ļ�β
              printf("%10s %4d %6.2f %6.2f  %6.2f  %6.2f \n",s.name,s.num,s.c,s.by,s.sjk,s.lssx);
	}
    fclose(fp);
    getch();
}
 
//ɾ��:�����ʦ���������ý�ʦ���ڣ���ɾ��������ʾɾ�������µĽ�ʦ�ɼ���Ϣ
 
void delete1()
{
 
    stu xs[N];
    FILE *fp;
    char name[10];
    int i=0,len,k=-1/*k<0��Ϊ����if�ж��õ�*/;
    system("cls");
    printf("\n������Ҫɾ���Ľ�ʦ����: ");scanf("%s",name);
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
 
//������ɾ��������д�ļ�
 
    len=i;/*�ṹ����������*/
    if(k>=0)/*k>0˵���ҵ�ɾ����ʦλ��*/
	{
      if((fp=fopen("teacher.dat","wb+"))==NULL) 
	  {
	      printf("can't open the file!\n");exit(0);
	  }
      for(i=0;i<len;i++)
	  {
      if(i==k) continue;/*�����λ�ÿ�ʼд��*/
      fwrite(&xs[i],sizeof(stu),1,fp);
	  }
      fclose(fp);
	}
      else {printf("ERROR,ɾ��ʧ��!!!\n");getch();} /*ʧ�ܺ����·��ز˵�*/
      print();
}
 
 
//ɾ��:�����ʦ��ţ����ý�ʦ���ڣ���ɾ��������ʾɾ�������µĽ�ʦ�ɼ���Ϣ
 
void delete2()
{
    stu xs[N];
    FILE *fp;
    int num;
    int i=0,len,k=-1/*k<0��Ϊ����if�ж��õ�*/;
    system("cls");
    printf("\n������Ҫɾ���Ľ�ʦ���: ");
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
//������ɾ��������д�ļ�
 
    len=i;/*�ṹ����������*/
    if(k>=0)/*k>0˵���ҵ�ɾ����ʦλ��*/
	{
    if((fp=fopen("teacher.dat","wb+"))==NULL) 
	{
	     printf("can't openfile!\n");exit(0);
	}
    for(i=0;i<len;i++)
	{
       if(i==k) continue;/*�����λ�ÿ�ʼд��*/
       fwrite(&xs[i],sizeof(stu),1,fp);
	}
    fclose(fp);
	}
    else {printf("ERROR,ɾ��ʧ��!!!\n");getch();} /*ʧ�ܺ����·��ز˵�*/
    print();
}
 
 
//ɾ��
 
void deleteway()
{
    char ch1;
    system("cls");
    printf("�����밴���ַ�ʽɾ��:\n");
    printf("1->������2->��ʦ���:");
    ch1=getchar();/*���ַ�����*/
    switch(ch1)/*�ж�*/
	{
	case '1':delete1();break;
    case '2':delete2();break;
	}
	getch();/*����Ļͣ��ͬʱ�����������*/
}
 
//ͳ�������ɼ����
 
void count() 
{
    int i=0,j=0,k=0,l=0,m=0,n,p,q,r,t,u;   //j,k,m,l�ֱ���ָ���������Σ�n,p,q,rҲ��
    FILE *fp;
    stu s[N], *p1[N],*p2[N],*p3[N],*p4[N];/*��ָ������*/
    system("cls");
    if((fp=fopen("teacher.dat","rb"))==NULL)
	{
	    printf("can't open the file!\n");exit(0);
	}
    while(!feof(fp))
	{
        fread(&s[i++],sizeof(stu),1,fp);/*��������*/
        if(feof(fp)) break;  //���ļ�ĩβ�жϳ���
	}
    t=i;i=0;           //t ָ���
    for(u=0;u<t;u++)/*����ÿ��ָ����������ָ��������εĽ�ʦ��Ϣ*/
	{
        if(s[i].c<5) 
		{
			p1[j++]=&s[i++];continue;
		}                                     /*ÿ����ʦ��Ϣֻ��λ��һ��������*/
        if(s[i].c>=6 && s[i].c<8) 
		{
			p2[k++]=&s[i++];continue;
		}
        if(s[i].c>=8) 
		{
			p3[l++]=&s[i++];continue;
		}
       
	}
    printf("     ���ϸ�:���� ��ʦ��� �����ɼ�\n");
    for(n=0;n<j-1;n++)
	{
        printf("%14s %4d %6.2f\n",p1[n]->name,p1[n]->num,p1[n]->c);      //�����ʾ����������Ϣ����ʾ����ָ�������
	}
    printf(" 6-8��֮��:���� ��ʦ��� �����ɼ�\n");
    for(p=0;p<k;p++)
	{
        printf("%16s %4d %6.2f\n",p2[p]->name,p2[p]->num,p2[p]->c);
	}
    printf(" 9-10��֮��:���� ��ʦ��� �����ɼ�\n");
    for(q=0;q<l;q++)
	{
        printf("%16s %4d %6.2f\n",p3[q]->name,p3[q]->num,p3[q]->c);
	}
    
    fclose(fp);
    getch();
}
 
 
//�˵�ѡ��
 
void main()
{
	char ch;
    while(1)
	{
      menu();// ��ʾ�˵�
      ch=getch();//ѡ��˵�
      if(ch=='0') 
		  break;
      switch(ch)//�жϹ�����
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

