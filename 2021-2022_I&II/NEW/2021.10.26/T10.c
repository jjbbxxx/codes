#include <stdio.h>
int main()
{
    int num, sum = 0;
    printf("������һ����λ�������֣�");
    scanf("%d", &num);
    while (num != 0)
    {
        printf("%d+", num % 10);
        sum += num % 10;
        num /= 10;
    }
    printf("\b=%d\n", sum);
    return 0;
}