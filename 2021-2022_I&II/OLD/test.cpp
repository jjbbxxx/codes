#include <stdio.h>
int main()
{
	int a, b, c, x, y;
	printf("aaa\n");
	scanf("%d %d %d", &a, &b, &c);
	bool q = a + b > c && b == c,
		 w = a || b + c && b - c,
		 e = !(a + b) && !c || 1,
		 r = !(x = a) && (y = b) && 0,
		 t = !(a + b) + c - 1 && b + c / 2;
	printf("%d%d%d%d%d", q, w, e, r, t);
	return 0;
}
