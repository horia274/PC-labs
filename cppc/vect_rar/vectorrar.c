#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int n;
	int nn;
	int *x;
	int *poz;
}SparceArray;

int *decomp(SparceArray sa)
{
	int *vrar,i;
	vrar=(int*)malloc(sa.n*sizeof(int));
	for(i=0;i<sa.n;i++)
		vrar[i]=0;
	for(i=0;i<sa.nn;i++)
		vrar[sa.poz[i]]=sa.x[i];
	return vrar;
}

SparceArray comp(int n,int *v)
{
	SparceArray sa;
	int i,j;
	sa.n=n;
	sa.nn=0;
	j=0;
	for(i=0;i<n;i++)
		if(v[i]!=0)
			sa.nn++;
	sa.x=(int*)malloc(sa.nn*sizeof(int));
	sa.poz=(int*)malloc(sa.nn*sizeof(int));
	for(i=0;i<n;i++)
		if(v[i]!=0)
		{
			sa.x[j]=v[i];
			sa.poz[j]=i;
			j++;
		}
	return sa;
}

int nrlinii(FILE *f1)
{
	int i,nr=0;
	SparceArray sa;
	while(!feof(f1))
	{
		fscanf(f1,"%d%d",&sa.n,&sa.nn);
		sa.x=(int*)malloc(sa.nn*sizeof(int));
		sa.poz=(int*)malloc(sa.nn*sizeof(int));
		for(i=0;i<sa.nn;i++)
			fscanf(f1,"%d",&sa.x[i]);
		for(i=0;i<sa.nn;i++)
			fscanf(f1,"%d",&sa.poz[i]);
		nr++;
	}
	nr--;
	fseek(f1,0,SEEK_SET);
	return nr;
}

void aduna(int n1,int n2)
{
	FILE *f1,*f2;
	SparceArray sa,sasum;
	int **vrar,*dim,i,j,k,n,nr;
	f1=fopen("nf1","r");
	f2=fopen("nf2","w");
	nr=nrlinii(f1);
	vrar=(int**)malloc(nr*sizeof(int*));
	dim=(int*)malloc(nr*sizeof(int));
	j=0;
	while(!feof(f1))
	{
		fscanf(f1,"%d%d",&sa.n,&sa.nn);
		sa.x=(int*)malloc(sa.nn*sizeof(int));
		sa.poz=(int*)malloc(sa.nn*sizeof(int));
		for(i=0;i<sa.nn;i++)
			fscanf(f1,"%d",&sa.x[i]);
		for(i=0;i<sa.nn;i++)
			fscanf(f1,"%d",&sa.poz[i]);
		vrar[j]=decomp(sa);
		dim[j]=sa.n;
		j++;
	}
	for(i=0;i<nr;i++)
	{
		if(dim[i]>=n1&&dim[i]<=n2)
		{
			for(j=i+1;j<nr;j++)
				if(dim[i]==dim[j])
				{
					dim[j]=-1;
					for(k=0;k<dim[i];k++)
						vrar[i][k]+=vrar[j][k];
				}
			sasum=comp(dim[i],vrar[i]);
			fprintf(f2,"%d %d\n",sasum.n,sasum.nn);
			for(k=0;k<sasum.nn;k++)
				fprintf(f2,"%d ",sasum.x[k]);
			fprintf(f2,"\n");
			for(k=0;k<sasum.nn;k++)
				fprintf(f2,"%d ",sasum.poz[k]);
			fprintf(f2,"\n");
		}
	}
}

int main()
{
	int n1,n2;
	scanf("%d%d",&n1,&n2);
	aduna(n1,n2);
	return 0;
}
