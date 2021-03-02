#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,j,k;
	float x,**a,aux;
	scanf("%d",&n);
	a=(float**)malloc(n*sizeof(float*));
	for(i=0;i<n;i++)
		a[i]=(float*)malloc(n*sizeof(float));
	for(k=0;k<n*n;k++)
	{
		scanf("%f",&x);
		a[k/n][k%n]=x;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
			for(k=j+1;k<n;k++)
				if(a[i][j]>a[i][k])
				{
					aux=a[i][j];
					a[i][j]=a[i][k];
					a[i][k]=aux;
				}
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
			for(k=i+1;k<n;k++)
				if(a[i][j]>a[k][j])
				{
					aux=a[i][j];
					a[i][j]=a[k][j];
					a[k][j]=aux;
				}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%f ",a[i][j]);
		printf("\n");
	}
	for(i=0;i<n;i++)
		free(a[i]);
	free(a);
	return 0;
}