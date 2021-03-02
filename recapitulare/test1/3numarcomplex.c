#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
	float re;
	float im;
}Numar_Complex;
Numar_Complex* citire(char *filename,int *n)
{
	FILE *f;
	f=fopen(filename,"r");
	char num[2],s[20],*p;
	int i;
	Numar_Complex *x;
	sprintf(num,"%c",getc(f));
	*n=atoi(num);
	getc(f);
	x=(Numar_Complex*)malloc((*n)*sizeof(Numar_Complex));
	for(i=0;i<*n;i++)
	{
		fgets(s,20,f);
		s[strlen(s)-1]='\0';
		p=strtok(s,"+");
		x[i].re=atoi(p);
		p=strtok(NULL,"i");
		x[i].im=atoi(p);
	}
	fclose(f);
	return x;
}
void maxmodul(Numar_Complex *x,int n,float *modul,int *poz)
{
	float modx;
	int i;
	*modul=0;
	for(i=0;i<n;i++)
	{
		modx=sqrt((x[i].re*x[i].re)+(x[i].im*x[i].im));
		if(*modul<modx)
		{
			*modul=modx;
			*poz=i;
		}
	}
}
int main()
{
	Numar_Complex *x;
	int i,n,poz;
	float modul;
	x=citire("file.txt",&n);
	for(i=0;i<n;i++)
		printf("%f + %f * i\n",x[i].re,x[i].im);
	maxmodul(x,n,&modul,&poz);
	printf("%f %d\n",modul,poz);
	free(x);
	return 0;
}