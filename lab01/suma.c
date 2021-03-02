#include <stdio.h>
int main()
{
	int x;
	s = 0;
	scanf("%d", &x);
	while(x % 2 == 0)
	{
		s+=x;
		scanf("%d", &x);
	}
	printf("%d\n",s);
	return 0;
}
