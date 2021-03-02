#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LUNG 20
#define MAX_LINE 100

int verif(int n,char **fisiere,char *numef)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp(fisiere[i],numef)==0)
			return 1;
	return 0;
}

int main(int argc,char *argv[])
{
	FILE *fcat,*fcomp,*f;
	char numef[MAX_LUNG],nume_comp[MAX_LUNG],*c,line[MAX_LINE];
	char **fisiere;
	int index_line,count,i,nrf;

	if(argc!=2)
	{
		fprintf(stderr, "Comanda gresita\n");
		return -1;
	}
	
	memset(nume_comp,0,MAX_LUNG);
	c=strchr(argv[1],'.');
	if(c==NULL)
		strcpy(nume_comp,argv[1]);
	else
		strncpy(nume_comp,argv[1],c-argv[1]);
	strcat(nume_comp,".cpl");

	if((fcat=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr, "Nu se poate deschide fisierul %s\n", argv[1]);
		return -1;
	}
	if((fcomp=fopen(nume_comp,"w"))==NULL)
	{
		fprintf(stderr, "Nu se poate scrie in fisierul %s\n", nume_comp);
		return -1;
	}

	nrf=1;
	fisiere=(char**)malloc(sizeof(char*));
	fscanf(fcat,"%s",numef);
	fisiere[nrf-1]=strdup(numef);

	fseek(fcat,0,SEEK_SET);
	while(!feof(fcat))
	{
		fscanf(fcat,"%s %d %d\n",numef,&index_line,&count);
		if((f=fopen(numef,"r"))==NULL)
		{
			fprintf(stderr, "Nu se poate deschide fisierul %s\n", numef);
			return -1;
		}
		for(i=0;i<index_line-1;i++)
			fgets(line,MAX_LINE,f);
		i=0;
		while(i<count)
		{
			fgets(line,MAX_LINE,f);
			fprintf(fcomp,"%s",line);
			i++;
		}
		if(!verif(nrf,fisiere,numef))
		{
			nrf++;
			fisiere=(char**)realloc(fisiere,nrf*sizeof(char*));
			fisiere[nrf-1]=strdup(numef);
		}
		fclose(f);
	}

	printf("Numarul fisierelor folosite: %d\n",nrf);
	for(i=0;i<nrf;i++)
		free(fisiere[i]);
	free(fisiere);
	fclose(fcat);fclose(fcomp);
	return 0;
}
