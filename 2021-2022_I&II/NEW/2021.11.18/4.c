///编写函数实现若干的数排序，在主函数中测试以下函数。
// void bubbleSort( int a[], int n);  // 优化的冒泡排序，对n个整数进行升序
// void selectSort( double b[], int n) ;  // 选择排序，对n个实数进行降序

/* 函数功能：插入排序
参数说明：长度为n的字符数组c
排序方式mode=0升序， mode=1降序排序
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
      t = c[i]; //待排序元素
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
      t = c[i]; //待排序元素
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