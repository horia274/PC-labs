#include <stdio.h>
int main()
{
	int n,a[100],k,i,j,aux;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
	for(i=0;i<k;i++)
		printf("%d ",a[i]);
	return 0;
}