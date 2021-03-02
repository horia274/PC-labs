#include <stdio.h>
void sume(int a[100],int n,int s[100][100])
{
	int i,j,s1,k;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			s[i][j]=0;
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			{
				s1=0;
				for(k=i;k<=j;k++)
					s1+=a[k];
				s[i][j]=s1;
			}
}
void Max(int n,int s[100][100],int *ic,int *jc)
{
	int Max,i,j;
	Max=s[1][1];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(Max<s[i][j])
				{
					*ic=i;
					*jc=j;
					Max=s[i][j];
				}
}
int main()
{
	int n,a[100],s[100][100];
	int i,j,ic,jc,suma;
	suma=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sume(a,n,s);
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d ",s[i][j]);
		printf("\n");
	}*/
	Max(n,s,&ic,&jc);
	/*for(i=ic;i<=jc;i++)
		suma+=a[i];
	printf("%d\n",suma);*/
	for(i=ic;i<=jc;i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}