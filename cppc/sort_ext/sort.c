#include <stdio.h>
#include <stdlib.h>

int Min(int n,long *a,int *OK)
{
	int i,poz;
	long Min;
	Min=100000;
	for(i=0;i<n;i++)
		if(Min>a[i] && OK[i]==0)
			{
				Min=a[i];
				poz=i;
			}
	return poz;
}

int verif(int n,int *OK)
{
	int i;
	for(i=0;i<n;i++)
		if(OK[i] != 1)
			return 1;
	return 0;
}

int main(int argc,char *argv[])
{
	FILE **f,*fout;
	int n,i,poz,ok,*OK;
	long *a;

	if(argc<3)
	{
		fprintf(stderr, "Nu avem ce sorta\n");
		return -1;
	}

	n=argc-2;
	a=(long*)malloc(n*sizeof(long));
	OK=(int*)calloc(n,sizeof(int));
	f=(FILE**)malloc(n*sizeof(FILE*));

	for(i=0;i<n;i++)
	{
		if((f[i]=fopen(argv[i+1],"rb"))==NULL)
		{
			fprintf(stderr, "Fisierul %s nu poate fi deshis\n", argv[i+2]);
			return -1;
		}
	}
	if((fout=fopen(argv[argc-1],"wb"))==NULL)
	{
		fprintf(stderr, "Fisierul %s nu poate fi deshis\n", argv[argc-1]);
		return -1;
	}

	for(i=0;i<n;i++)
		fread(&a[i],sizeof(long),1,f[i]);
	ok=1;
	while(ok)
	{
		poz=Min(n,a,OK);
		printf("%ld\n",a[poz]);
		fwrite(&a[poz],sizeof(long),1,fout);
		if(fread(&a[poz],sizeof(long),1,f[poz]));
		else
			OK[poz]=1;
		ok=verif(n,OK);
	}

	for(i=0;i<n;i++)
		fclose(f[i]);
	fclose(fout);
	free(a);free(f);
	return 0;
}
