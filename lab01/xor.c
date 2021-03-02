#include <stdio.h>
int main()
{
	int n,x,y,i;
	scanf("%d", &n);
	scanf("%d", &x);
	for(i = 2;i <= n;i++)
	{
		scanf("%d", &y);
		x = x^y;
	}
	printf("%d\n",x);
	return 0;
}