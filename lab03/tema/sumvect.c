#include <stdio.h>
int main()
{
	int x[100],y[100],m,n,i,s[100],nr,t;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%d",&x[i]);
	for(i=0;i<n;i++)
		scanf("%d",&y[i]);
	nr=0;t=0;
	while(nr<n&&nr<m)
	{
		s[nr]=(x[nr]+y[nr]+t)%10;
		if(x[nr]+y[nr]+t>9)
			t=1;
		else
			t=0;
		nr++;
	}
	while(nr<m)
	{
		s[nr]=(x[nr]+t)%10;
		if(x[nr]+t>9)
			t=1;
		else
			t=0;
		nr++;
	}
	while(nr<n)
	{
		s[nr]=(y[nr]+t)%10;
		if(y[nr]+t>9)
			t=1;
		else
			t=0;
		nr++;
	}
	for(i=0;i<nr;i++)
		printf("%d ",s[i]);
	printf("\n");
	return 0;
}