///��д����ʵ�����ɵ����������������в������º�����
// void bubbleSort( int a[], int n);  // �Ż���ð�����򣬶�n��������������
// void selectSort( double b[], int n) ;  // ѡ�����򣬶�n��ʵ�����н���

/* �������ܣ���������
����˵��������Ϊn���ַ�����c
����ʽmode=0���� mode=1��������
*/
//void insertSort( char c[], int n, int mode);

#include <stdio.h>

void bubbleSort(int a[], int n)
{
  int i, j, temp, flag;
  for (i = 0; i < n; i++)
  {
    flag = 0;
    for (j = 0; j < n - i - 1; j++)
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
        flag = 1;
      }
    if (flag == 0)
      break;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void selectSort(double b[], int n)
{
  int i, j;
  double temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (b[i] < b[j])
      {
        temp = b[j];
        b[j] = b[i];
        b[i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++)
    printf("%.1f ", b[i]);
  printf("\n");
}
void insertSort(char c[], int n, int mode)
{
  int t;
  int i, j;
  if (mode == 0)
  {
    for (i = 1; i < n; i++)
    {
      t = c[i]; //������Ԫ��
      for (j = i - 1; j >= 0 && c[j] > t; j--)
      {
        c[j + 1] = c[j];
      }
      c[j + 1] = t;
    }
  }
  if (mode == 1)
  {
    for (i = 1; i < n; i++)
    {
      t = c[i]; //������Ԫ��
      for (j = i - 1; j >= 0 && c[j] < t; j--)
      {
        c[j + 1] = c[j];
      }
      c[j + 1] = t;
    }
  }
  for (int i = 0; i < n; i++)
    printf("%c ", c[i]);
  printf("\n");
}

int main()
{
  int a[5] = {5, 6, 4, 7, 3};
  double b[5] = {4.6, 9.5, 6.4, 8.1, 6.7};
  char c[5]={'a','c','d','e','b'};
  bubbleSort(a, 5);
  selectSort(b, 5);
  insertSort(c,5,0);
  insertSort(c,5,1);
  return 0;
}