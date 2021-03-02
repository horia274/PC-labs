#include <stdio.h>
void secv(int n,int m,int a[100][100])
{
	int i,j;
	for(j=0;j<m;j++)
		printf("%d ",a[0][j]);
	for(i=1;i<n;i++)
		printf("%d ",a[i][m-1]);
	for(j=m-2;j>=0;j--)
		printf("%d ",a[n-1][j]);
	for(i=n-2;i>0;i--)
		printf("%d ",a[i][0]);
}
void refac(int* n,int* m,int a[100][100])
{
	int i,j;
	for(i=0;i<*m-1;i++)
		for(j=0;j<*n-1;j++)
			a[i][j]=a[i+1][j+1];
	*m-=2;*n-=2;
}
int main()
{
	int n,m,a[100][100];
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	while(n>0&&m>0)
	{
		secv(n,m,a);
		refac(&n,&m,a);
	}
	printf("\n");
	return 0;
}
