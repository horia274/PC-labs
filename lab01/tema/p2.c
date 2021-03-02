#include <stdio.h>
int main()
{
	int n, i, x, y, r, nr;
	nr = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		y = x;
		r = 0;
		while(x > 0)
		{
			r = r * 10 + x % 10;
			x /= 10;
		}
		if(y == r)
		nr++;
	}
	printf("%d\n", nr);
	return 0;
}