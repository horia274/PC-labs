#include <stdio.h>
#include <stdlib.h>
void aloc(int ***a,int *n)
{
	scanf("%d",n);
	int i;
	*a=(int**)malloc(*n*sizeof(int*));
	for(i=0;i<*n;i++)
		*a[i]=(int*)malloc((*n-i)*sizeof(int));
}
void cit(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-i;j++)
			scanf("%d",&a[i][j]);
}
int suma(int **a,int n)
{
	int s,i;
	s=0;
	for(i=0;i<n;i++)
		s=s+a[0][i]+a[i][0]+a[i][n-1-i];
	s=s-a[0][0]-a[0][n-1]-a[n-1][0];
	return s;
}
void fre(int **a,int n)
{
	int i;
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);
}
int main()
{
	int **a,n;
	aloc(&a,&n);
	cit(a,n);
	printf("%d\n",suma(a,n));
	fre(a,n);
	return 0;
}