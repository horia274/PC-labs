#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	double c;
	int exp;
} termen;

typedef struct
{
	int ntn;
	int grd;
	termen *t;
} polinom_rar;

void citire(FILE *in,int *nr,polinom_rar *pols)
{
	int info[2]; //info[0]=grad
				 //info[1]=numar termeni
	pols=NULL;
	*nr=0;
	while(fread(info,sizeof(int),2,in))
	{
		if(pols==NULL)
			pols=(polinom_rar*)malloc(sizeof(polinom_rar));
		else
			pols=realloc(pols,((*nr)+1)*sizeof(polinom_rar));
		pols[*nr].t=calloc(info[1],sizeof(termen));
		pols[*nr].ntn=info[1];
		pols[*nr].grd=info[0];
		fread(pols[*nr].t,info[1],sizeof(int),in);
		(*nr)++;
	}
}

void disp(polinom_rar *pols,int nr_pol,int x)
{
	// functia afiseaza al x-ulea polinom din vectorul pols
	int i;
	if(x>nr_pol)
		printf("Nu exista polinom!\n");
	else
	{
		for(i=0;i<pols->ntn;i++)
			printf("%lfX^%d + ",pols[x-1].t[i].c,pols[x-1].t[i].exp);
	}
}

void free_all(polinom_rar *pols,int nr_pol)
{
	int i;
	for(i=0;i<nr_pol;i++)
		free(pols[i].t);
	free(pols);
}

int main(int argc,char *argv[])
{
	FILE *in;
	polinom_rar *pols;
	int i,nr_pol;
	in=fopen(argv[1],"rb");
	citire(in,&nr_pol,pols);
	for(i=2;i<argc;i++)
	{
		int x=atoi(argv[i]);
		disp(pols,nr_pol,x);
	}
	free_all(pols,nr_pol);
	return 0;
}
