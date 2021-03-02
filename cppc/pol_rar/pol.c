#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int salt(int ni,int *nr_term)
{
	int i,d=0;
	for(i=0;i<ni;i++)
		d+=nr_term[i];
	return d;
}

int main(int argc, char *argv[])
{
	FILE *f;
	int i,j,*nr_term,nrp,ntn,ni,d;
	polinom_rar p;
	nrp=0;
	nr_term=(int*)calloc(1,sizeof(int));
	if(argc <= 2)
	{
		fprintf(stderr, "Eroare\n");
		return -1;
	}
	if((f=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr, "Eroare\n");
		return -1;
	}
	while(fread(&ntn,1,sizeof(int),f))
	{
		nrp++;
		nr_term=(int*)realloc(nr_term,nrp*sizeof(int));
		nr_term[nrp-1]=ntn;
		fseek(f,sizeof(int)+ntn*sizeof(termen),SEEK_CUR);
	}
	for(i=2;i<argc;i++)
	{
		ni=atoi(argv[i])-1;
		d=salt(ni,nr_term);
		fseek(f,2*ni*sizeof(int)+d*sizeof(termen),SEEK_SET);
		fread(&p.ntn,1,sizeof(int),f);
		fread(&p.grd,1,sizeof(int),f);
		p.t=(termen*)malloc(p.ntn*sizeof(termen));
		fread(p.t,p.ntn,sizeof(termen),f);
		for(j=0;j<p.ntn;j++)
			printf("%lfX^%d+",p.t[j].c,p.t[j].exp);
		printf("\n");
		free(p.t);
	}
	free(nr_term);
	fclose(f);
	return 0;
}
