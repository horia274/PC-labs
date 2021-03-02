#include <stdio.h>
int main()
{
	int n, x, scif, nr, i;
	scanf("%d", &n);
	nr = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		scif = 0;
		while(x > 0)
		{
			scif += x % 10;
			x /= 10;
		}
		printf("%d ", scif);
		if(scif % 2 == 0)
			nr++;
	}
	printf("\n");
	printf("%d\n", nr);
	return 0;
}