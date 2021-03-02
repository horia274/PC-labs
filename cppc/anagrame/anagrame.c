#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_NAME 10
#define MAX_LINE 200

void sepcuv(FILE *f,char delim[],char **cuv);
void swap_chars(char *s,char *t);
void swap_string(char **s,char **t);

int main()
{
	FILE *f;
	char numef[MAX_NAME],delim[MAX_NAME]=";:, .-\n",**cuv;
	scanf("%s",numef);
	
	if((f=fopen(numef,"r"))==NULL)
	{
		fprintf(stderr, "Nu se poate deschide fisierul %s\n", numef);
		return -1;
	}

	cuv=(char**)malloc(sizeof(char*));
	sepcuv(f,delim,cuv);
	free(cuv);
	fclose(f);

	return 0;
}

void swap_chars(char *s,char *t)
{
	char aux;
	aux=*s;
	*s=*t;
	*t=aux;
}

void swap_string(char **s,char **t)
{
	char *aux;
	aux=*s;
	*s=*t;
	*t=aux;
}

void sepcuv(FILE *f,char delim[],char **cuv)
{
	int i,j,k,n,nrdif;
	char line[MAX_LINE],*p,**ord,**lines;
	n=0;
	fgets(line,MAX_LINE,f);
	p=strtok(line,delim);
	while(p!=NULL)
	{
		n++;
		cuv=(char**)realloc(cuv,n*sizeof(char*));
		cuv[n-1]=strdup(p);
		p=strtok(NULL,delim);
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(cuv[i]);j++)
			if(cuv[i][j]>='A' && cuv[i][j] <= 'Z')
				cuv[i][j]=tolower(cuv[i][j]);
	}

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(strcmp(cuv[i],cuv[j])>0)
				swap_string(&cuv[i],&cuv[j]);
			if(strcmp(cuv[i],cuv[j])==0)
			{
				for(k=j;k<n-1;k++)
					swap_string(&cuv[k],&cuv[k+1]);
				n--;
				cuv=(char**)realloc(cuv,n*sizeof(char*));
			}
		}

	ord=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		ord[i]=strdup(cuv[i]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(ord[i]);j++)
			for(k=j+1;k<strlen(ord[i]);k++)
				if(ord[i][j] > ord[i][k])
					swap_chars(&ord[i][j],&ord[i][k]);
	}

	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{	
			if(strcmp(ord[i],ord[j])>0)
			{
				swap_string(&ord[i],&ord[j]);
				swap_string(&cuv[i],&cuv[j]);
			}
			if(strcmp(ord[i],ord[j])==0 && strcmp(cuv[i],cuv[j])>0)
				swap_string(&cuv[i],&cuv[j]);
		}

	nrdif=0;
	for(i=0;i<n-1;i++)
		if(strcmp(ord[i],ord[i+1])!=0)
			nrdif++;
	nrdif++;

	lines=(char**)malloc(nrdif*sizeof(char*));
	for(i=0;i<nrdif;i++)
		lines[i]=(char*)malloc(MAX_LINE*sizeof(char));

	i=0;k=0;
	while(i<n)
	{
		j=i+1;
		memset(lines[k],0,MAX_LINE);
		strcpy(lines[k],cuv[i]);
		while(strcmp(ord[i],ord[j])==0)
		{
			strcat(lines[k],"-");
			strcat(lines[k],cuv[j]);
			j++;
		}
		i=j;
		k++;
	}

	for(i=0;i<nrdif;i++)
		for(j=i+1;j<nrdif;j++)
			if(strcmp(lines[i],lines[j])>0)
				swap_string(&lines[i],&lines[j]);

	for(i=0;i<nrdif;i++)
		printf("%s\n",lines[i]);

	for(i=0;i<nrdif;i++)
		free(lines[i]);
	for(i=0;i<n;i++)
	{
		free(cuv[i]);
		free(ord[i]);
	}
	free(ord);free(lines);
}
