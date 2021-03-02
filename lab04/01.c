#include <stdio.h>
void cit(int* v,int* n)
{
	int i;
	scanf("%d",n);
	for(i=0;i<*n;i++)
		scanf("%d",&v[i]);
}
int main()
{
	int x[100],n,i;
	cit(x,&n);
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
	return 0;
}