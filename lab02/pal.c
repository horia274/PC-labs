#include <stdio.h>
int pal (int a)
{
	int b, r;
	b = a;
	r = 0;
	while (a > 0)
	{
		r = r * 10 + a % 10;
		a /= 10;
	}
	if (b == r)
		return 1;
	return 0;
}
int main()
{
	int n,x,i,nr;
	nr = 0;
	scanf("%d", &n);
	for (i = 1;i <= n; i++)
	{
		scanf("%d", &x);
		if (x % 2 == 0 && pal(x) == 1)
			nr ++;
	}
	printf("%d\n", nr);
	return 0;
}