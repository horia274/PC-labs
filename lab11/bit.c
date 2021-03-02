#include <stdio.h>
#include <string.h>
int main()
{
	int m,n,i;
	char c;
	short x;
	char viz[2000],l;
	memset(viz,0,2000);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf(" %c%hd",&c,&x);
		if(c=='a')
			viz[x/8]=viz[x/8]|(1<<(x%8));
		else
			viz[x/8]=viz[x/8]&(~(1<<(x%8)));
	}
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%hd",&x);
		l=viz[x/8]&(1<<(x%8));
		if(l!=0)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}