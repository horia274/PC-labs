#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sort_strings(int n,char **v)
{
	int i,j;
	char *aux;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(strlen(v[i])>strlen(v[j]))
			{
				aux=strdup(v[i]);
				v[i]=strdup(v[j]);
				v[j]=strdup(aux);
			}
	for(i=0;i<n-1;i++)
		if(strlen(v[i])==strlen(v[i+1])&&strcmp(v[i],v[i+1])>0)
		{
			aux=strdup(v[i]);
			v[i]=strdup(v[i+1]);
			v[i+1]=strdup(aux);
		}
}
void afis(int n, char **v)
{
	int i,j;
	for(i=0;i<n;i++)
	{	
		printf("%s",v[i]);
		printf("\n");
	}
}
int main()
{
	char **v;
	int n,i;
	scanf("%d",&n);
	v=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
	{
		v[i]=(char*)malloc(100*sizeof(char));
		scanf("%s",v[i]);
	}
	sort_strings(n,v);
	afis(n,v);
	return 0;
}