/*��ƺ�����Լɪ�����⣬m����Χ��Ȧ�����Ϊ1��m��
��1�ſ�ʼ����������n�ı��������뿪��һֱ����ȥ��
ֱ�����ֻʣ��1�ˣ���Ϸ���ʤ���߱�š� 
*/
#include <stdio.h>
#include <stdlib.h>
int over(int *p, int m)
{
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (*(p + i) != 0)
            count++;
    }
    if (count == 1)
        return 1;
    else
        return 0;
}
int game(int m, int n, int *p)
{
    int num, i = n - 1;
    while (over(p, m) == 0)
    {
        *(p + i) = 0;
        i += n;
        if (i + 1 > m)
            i -= m;
    }
    for (int i = 0; i < m; i++)
    {
        if (*(p + i) != 0)
            return i +1;
    }
    return 0;
}
int main()
{
    int *p, m, n;
    printf("input m n:\n");
    scanf("%d %d", &m, &n);
    p = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        *(p + i) = i + 1;
    }
    printf("winner number: ");
    printf("%d\n", game(m, n, p));
    for (int i = 0; i < m; i++)
    {
        printf("%d ", *(p + i));
    }
    free(p);
    return 0;
}