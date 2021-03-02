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

int nrpol(char *fisier)
{
	int nr=0;
	FILE *f;
	char buff[100];
	f=fopen(fisier,"r");
	while(fgets(buff,100,f))
		nr++;
	fclose(f);
	return nr;
}

int main(int argc,char *argv[])
{
	FILE *f;
	char *numef,buff[100];
	int i,j,nr;
	polinom_rar P;
	numef=strdup(argv[1]);
	nr=nrpol(numef);
	for(i=2;i<argc;i++)
	{
		if(atoi(argv[i])>nr)
			printf("Nu exista polinom\n");
		else
		{
			f=fopen(numef,"r");
			for(j=1;j<atoi(argv[i]);j++)
				fgets(buff,100,f);
			fscanf(f,"%d %d ",&P.ntn,&P.grd);
			P.t=(termen*)malloc(P.ntn*sizeof(termen));
			for(j=0;j<P.ntn;j++)
				fscanf(f,"%lf %d",&P.t[j].c,&P.t[j].exp);
			fscanf(f,"\n");
			for(j=0;j<P.ntn;j++)
			{
				if(P.t[j].exp>0)
				{
					if(P.t[j+1].c>0)
						printf("%lfX^%d+",P.t[j].c,P.t[j].exp);
					else
						printf("%lfX^%d",P.t[j].c,P.t[j].exp);
				}
				else
					printf("%lf",P.t[j].c);
			}
			printf("\n");
			free(P.t);
			fclose(f);
		}
	}
	free(numef);
	return 0;
}
