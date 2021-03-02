#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int lin,col;
	double val;
} termen;

typedef struct
{
	int nl,nc,nn;
	termen *term;
} matrice_rara;

int nrmat(char file[])
{
	FILE *f;
	f=fopen(file,"r");
	char buff[100];
	int nr=0;
	while(fgets(buff,100,f))
		nr++;
	fclose(f);
	return nr;
}

int main(int argc,char *argv[])
{
	FILE *f;
	int i,j,k,poz,nr;
	char buff[100];
	matrice_rara A;
	double **M;
	nr=nrmat(argv[1]);
	for(i=2;i<argc;i++)
	{
		f=fopen(argv[1],"r");
		poz=atoi(argv[i]);
		if(poz>nr)
			printf("Matrice inexistenta\n");
		else
		{
			for(j=1;j<poz;j++)
				fgets(buff,100,f);
			fscanf(f,"%d %d %d ",&A.nl,&A.nc,&A.nn);
			A.term=(termen*)malloc(A.nn*sizeof(termen));
			for(j=0;j<A.nn;j++)
				fscanf(f,"%d %d %lf",&A.term[j].lin,&A.term[j].col,&A.term[j].val);
			fscanf(f,"\n");
			/*
			printf("%d %d %d\n",A.nl,A.nc,A.nn);
			for(j=0;j<A.nn;j++)
				printf("%d %d %lf\n",A.term[j].lin,A.term[j].col,A.term[j].val);
			*/
			M=(double**)malloc(A.nl*sizeof(double*));
			for(j=0;j<A.nl;j++)
				M[j]=(double*)malloc(A.nc*sizeof(double));
			for(j=0;j<A.nl;j++)
				for(k=0;k<A.nc;k++)
					M[j][k]=0;
			for(j=0;j<A.nn;j++)
				M[A.term[j].lin][A.term[j].col]=A.term[j].val;
			for(j=0;j<A.nl;j++)
			{
				for(k=0;k<A.nc;k++)
					printf("%lf ",M[j][k]);
				printf("\n");
			}
			printf("\n");
			free(A.term);
			for(j=0;j<A.nl;j++)
				free(M[j]);
			free(M);
		}
		fclose(f);
	}
	return 0;
}
