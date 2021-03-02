#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUME_TARA 16
#define NUMAR_TARI 12
#define TOP 10

void swap_int(int *x,int *y);
void swap_string(char **s,char **t);
void creare(int n,FILE *f,char **tari,char ***voturi);
void anulat(int n,char **tari,char ***voturi,int *ok);
void puncte(int n,char **tari,char ***voturi,int *ok,int *punctaje);
void sortare(int p,int n,char **tari,int *punctaje);
void afis_trisori(int n,char **tari,int *ok);
void afis_top(int p,int n,char **tari,int *punctaje);
void afis_pierzatori(int n,char **tari,int *punctaje);
void free_all(int n,char ***voturi,char **tari,int *ok,int *punctaje);

int main()
{
	FILE *f;
	int n,*punctaje,*ok,i,j;
	char numef[NUME_TARA],***voturi,**tari;
	scanf("%d%s",&n,numef);
	if((f=fopen(numef,"r"))==NULL)
	{
		fprintf(stderr, "Fisierul %s nu poate fi deschis\n", numef);
		return -1;
	}

	voturi=(char***)malloc(n*sizeof(char**));
	tari=(char**)malloc(n*sizeof(char*));
	punctaje=(int*)calloc(n,sizeof(int));
	ok=(int*)calloc(n,sizeof(int));
	
	creare(n,f,tari,voturi);
	anulat(n,tari,voturi,ok);
	puncte(n,tari,voturi,ok,punctaje);
	afis_trisori(n,tari,ok);
	afis_top(TOP,n,tari,punctaje);
	afis_pierzatori(n,tari,punctaje);
	free_all(n,voturi,tari,ok,punctaje);
	fclose(f);
	
	return 0;
}

void swap_int(int *x,int *y)
{
	int aux;
	aux=*x;
	*x=*y;
	*y=aux;
}

void swap_string(char **s,char **t)
{
	char *aux;
	aux=*s;
	*s=*t;
	*t=aux;
}

void creare(int n,FILE *f,char **tari,char ***voturi)
{
	int i,j;
	char tara[NUME_TARA];
	for(i=0;i<n;i++)
	{
		fscanf(f,"%s",tara);
		tari[i]=strdup(tara);
		voturi[i]=(char**)malloc(NUMAR_TARI*sizeof(char*));
		for(j=0;j<NUMAR_TARI;j++)
			{
				fscanf(f,"%s",tara);
				voturi[i][j]=strdup(tara);
			}
	}
}

void anulat(int n,char **tari,char ***voturi,int *ok)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<NUMAR_TARI;j++)
			if(strcmp(tari[i],voturi[i][j])==0)
			{
				ok[i]=1;
				break;
			}
	}
}

void puncte(int n,char **tari,char ***voturi,int *ok,int *punctaje)
{
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			for(k=0;k<NUMAR_TARI;k++)
				if(strcmp(tari[i],voturi[j][k])==0 && ok[j]==0)
						punctaje[i]+=(12-k);
}

void sortare(int p,int n,char **tari,int *punctaje)
{
	int i,j;
	for(i=0;i<p;i++)
		for(j=i+1;j<n;j++)
			if(punctaje[i]<punctaje[j])
			{
				swap_int(&punctaje[i],&punctaje[j]);
				swap_string(&tari[i],&tari[j]);
			}
}

void afis_trisori(int n,char **tari,int *ok)
{
	int i;
	printf("Juriu descalificat\n");
	for(i=0;i<n;i++)
		if(ok[i]==1)
			printf("%s\n",tari[i]);
	printf("\n");
}

void afis_top(int p,int n,char **tari,int *punctaje)
{
	int i;
	sortare(p,n,tari,punctaje);
	printf("Podium\n");
	for(i=0;i<p;i++)
		printf("#%d %s -> %d puncte\n",i+1,tari[i],punctaje[i]);
	printf("\n");
}

void afis_pierzatori(int n,char **tari,int *punctaje)
{
	int i;
	printf("0 voturi :(\n");
	for(i=0;i<n;i++)
		if(punctaje[i]==0)
			printf("%s\n",tari[i]);
}

void free_all(int n,char ***voturi,char **tari,int *ok,int *punctaje)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		free(tari[i]);
		for(j=0;j<NUMAR_TARI;j++)
			free(voturi[i][j]);
	}
	for(i=0;i<n;i++)
		free(voturi[i]);
	free(voturi);free(tari);
	free(ok);free(punctaje);
}
