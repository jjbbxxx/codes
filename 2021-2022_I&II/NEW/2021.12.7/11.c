/*设计函数求约瑟夫问题，m个人围成圈，编号为1—m，
从1号开始报数，报到n的倍数的人离开，一直数下去，
直到最后只剩下1人，游戏最后胜出者编号。 
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