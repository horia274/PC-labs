#include <stdio.h>
int main()
{
	int n, i, x, nr;
	nr = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		while(x > 1 && x % 5 == 0)
			x /= 5;
		if(x == 1)
		nr++;		
	}
	printf("%d\n", nr);
	return 0;
}