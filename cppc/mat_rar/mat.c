#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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

matrice_rara* newMat(int nl, int nc, int nn, ...){
	va_list ap;
	int i;
	matrice_rara *M = (matrice_rara *)malloc(sizeof(matrice_rara));
	M->nl = nl;
	M->nc = nc;
	M->nn = nn;
	M->term = (termen *)malloc(nn * sizeof(termen));
	va_start(ap, nn);
	for(i = 0; i < nn; i++) {
		M->term[i].lin = va_arg(ap, int);
		M->term[i].col = va_arg(ap, int);
		M->term[i].val = va_arg(ap, double);
	}
	va_end(ap);
	return M;
}

void init(char *filename){
	FILE *f;
	int i;
	matrice_rara *M[4] = {
		newMat(3, 3, 3, 1, 1, 2.0, 1, 2, 3.0, 0, 0, 1.0),
		newMat(2, 3, 2, 0, 1, 1.0, 1, 1, 2.0),
		newMat(2, 2, 2, 1, 0, 3.0, 0, 0, 2.0),
		newMat(4, 4, 2, 1, 1, 3.0, 2, 1, 5.0),
	};
	if( (f = fopen(filename, "wb")) == NULL ) {
		fprintf(stderr, "Error: creating file.\n");
		return;
	}
	for(i=0; i<4; i++){
		fwrite(&(M[i]->nl), 1, sizeof(int), f);
		fwrite(&(M[i]->nc), 1, sizeof(int), f);
		fwrite(&(M[i]->nn), 1, sizeof(int), f);
		fwrite(M[i]->term, M[i]->nn, sizeof(termen), f);
	}
	fclose(f);
}

int salt(int nk,int *nr_term)
{
	int i,d=0;
	for(i=0;i<nk;i++)
		d+=nr_term[i];
	return d;
}

int main(int argc, char *argv[])
{
	FILE *f;
	init(argv[1]);
	int ntn,*nr_term,i,j,k,nm=0,nk,d;
	double **a;
	matrice_rara M;
	nr_term=(int*)calloc(1,sizeof(int));
	if(argc<=2)
	{
		fprintf(stderr, "Error\n");
		return -1;
	}
	if((f=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr, "Error\n");
		return -1;
	}
	fseek(f,2*sizeof(int),SEEK_CUR);
	while(fread(&ntn,1,sizeof(int),f))
	{
		nm++;
		nr_term=(int*)realloc(nr_term,nm*sizeof(int));
		nr_term[nm-1]=ntn;
		fseek(f,2*sizeof(int)+ntn*sizeof(termen),SEEK_CUR);
	}
	for(k=2;k<argc;k++)
	{
		nk=atoi(argv[k])-1;
		d=salt(nk,nr_term);
		fseek(f,3*nk*sizeof(int)+d*sizeof(termen),SEEK_SET);
		fread(&M.nl,1,sizeof(int),f);
		fread(&M.nc,1,sizeof(int),f);
		fread(&M.nn,1,sizeof(int),f);
		M.term=(termen*)malloc(M.nn*sizeof(termen));
		fread(M.term,M.nn,sizeof(termen),f);
		a=(double**)malloc(M.nl*sizeof(double*));
		for(i=0;i<M.nl;i++)
			a[i]=(double*)calloc(M.nc,sizeof(double));
		for(i=0;i<M.nn;i++)
			a[M.term[i].lin][M.term[i].col]=M.term[i].val;
		for(i=0;i<M.nl;i++)
		{
			for(j=0;j<M.nc;j++)
				printf("%lf ",a[i][j]);
			printf("\n");
		}
		printf("\n");
		for(i=0;i<M.nl;i++)
			free(a[i]);
		free(a);
	}
	free(nr_term);
	fclose(f);
	return 0;
}
