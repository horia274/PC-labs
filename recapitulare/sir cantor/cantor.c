#include <stdio.h>

void numar(int n,int *i,int *j)
{
	int l=1; //caut linia
	while(l*(l+1)/2<n)
		l++;
	int c; //coloana
	c=n-(l-1)*l/2;
	if(l%2==0)
	{
		*i=c;
		*j=l+1-c;
	}
	if(l%2==1)
	{
		*i=l+1-c;
		*j=c;
	}
}

int main()
{
	int m,n,i,j,k;
	scanf("%d",&m);
	for(k=0;k<m;k++)
	{
		scanf("%d",&n);
		numar(n,&i,&j);
		printf("%d/%d\n",i,j);
	}
	return 0;
}