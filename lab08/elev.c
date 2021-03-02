#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	struct elev
	{
		int h;
		int v;
		int dim;
		char *nume;
	};
	struct elev *x,aux;
	int n,i,j;
	scanf("%d",&n);
	x=(struct elev*)malloc(n*sizeof(struct elev));
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&x[i].h,&x[i].v,&x[i].dim);
		x[i].nume=(char*)malloc((x[i].dim+1)*sizeof(char));
		scanf(" ");
		fgets(x[i].nume,x[i].dim+1,stdin);
		x[i].nume[x[i].dim]='\0';
		//scanf("%s",x[i].nume);
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(x[i].v>x[j].v)
			{
				aux=x[i];
				x[i]=x[j];
				x[j]=aux;
			}
	for(i=0;i<n;i++)
	{
		printf("%d %d %d ",x[i].h,x[i].v,x[i].dim);
		printf("%s\n",x[i].nume);
	}
	for(i=0;i<n;i++)
		free(x[i].nume);
	free(x);
	return 0;	
}