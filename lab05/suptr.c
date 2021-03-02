#include <stdio.h>
#include <stdlib.h>
int main()
{
	int **a,n,i,j,s;
	scanf("%d", &n);
	a=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		a[i]=(int*)malloc((n-i)*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n-i;j++)
			scanf("%d",&a[i][j]);
	s=0;
	for(i=0;i<n;i++)
		s=s+a[0][i]+a[i][0]+a[i][n-1-i];
	s=s-a[0][0]-a[0][n-1]-a[n-1][0];
	printf("%d\n",s);
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);
	return 0;
}