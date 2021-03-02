#include <stdio.h>
int main()
{
	int n,x[100];
	int i,j,ok;
	scanf("%d", &n);
	for(i = 1;i <= n;i++)
	scanf("%d", &x[i]);
	for(i = 1;i <= n;i++)
	{
		ok = 0;
		for(j = 1;j<=n;j++)
			if(j != i && x[i] == x[j])
			{
				ok=1;
				break;
			}
		if(ok == 0)
		{
			printf("%d\n",x[i]);
			break;
		}
	}
	return 0;
}