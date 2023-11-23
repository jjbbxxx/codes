#include<stdio.h>
int a[100001];
int n;
void kp(int x,int y)
{
	if(x>=y)
	{
		return;
	}
	int jz=a[x];
	int i=x,j=y;
	int temp;
	while(i!=j)
	{
		while(a[j]>=jz&&i<j)
		{
			j--;
		}
		while(a[i]<=jz&&i<j)
		{
			i++;
		}
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	} 
	a[x]=a[j];
	a[j]=jz;
	kp(x,j-1);
	kp(j+1,y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	kp(1,n);
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 