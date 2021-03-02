#include <stdio.h>
#include <stdlib.h>
#define MAX_NUME 10

typedef struct
{
	int n,nn;
	int *x;
	int *poz;
} vector_rar;

int* decomp(vector_rar vrar)
{
	int *v,i;
	v=(int*)calloc(vrar.n,sizeof(int));
	for(i=0;i<vrar.nn;i++)
		v[vrar.poz[i]]=vrar.x[i];
	return v;
}


vector_rar comp(int n,int *v)
{
	int i,nr=0,j=0;
	vector_rar vrar;
	for(i=0;i<n;i++)
		if(v[i]!=0)
			nr++;
	vrar.n=n;
	vrar.nn=nr;
	vrar.x=(int*)malloc(nr*sizeof(int));
	vrar.poz=(int*)malloc(nr*sizeof(int));	
	for(i=0;i<n;i++)
		if(v[i]!=0)
		{
			vrar.x[j]=v[i];
			vrar.poz[j]=i;
			j++;
		}
	return vrar;
}

void aduna(FILE *f1,FILE *f2,int n1,int n2)
{
	int i,j,k,n=0,**v,*dim;
	vector_rar vrar;
	v=(int**)malloc(sizeof(int*));
	dim=(int*)malloc(sizeof(int));
	while(fread(&vrar.n,sizeof(int),1,f1))
	{
		n++;
		fread(&vrar.nn,sizeof(int),1,f1);
		vrar.x=(int*)malloc(vrar.nn*sizeof(int));
		vrar.poz=(int*)malloc(vrar.nn*sizeof(int));
		fread(vrar.poz,sizeof(int),vrar.nn,f1);
		fread(vrar.x,sizeof(int),vrar.nn,f1);
		v=(int**)realloc(v,n*sizeof(int*));
		dim=(int*)realloc(dim,n*sizeof(int));
		v[n-1]=decomp(vrar);
		dim[n-1]=vrar.n;
	}

	for(i=0;i<n;i++)
	{
		if(dim[i]>=n1 && dim[i]<=n2)
		{
			for(j=i+1;j<n;j++)
				if(dim[i]==dim[j])
				{
					for(k=0;k<dim[i];k++)
						v[i][k]+=v[j][k];
					dim[j]=-1;
				}
			vrar=comp(dim[i],v[i]);
			printf("%d\n",dim[i]);
			for(j=0;j<dim[i];j++)
				printf("%d ",v[i][j]);
			printf("\n\n");
			/*fwrite(&vrar2.n,sizeof(int),1,f2);
			fwrite(&vrar2.nn,sizeof(int),1,f2);
			fwrite(vrar2.x,sizeof(int),vrar2.nn,f2);
			fwrite(vrar2.poz,sizeof(int),vrar2.nn,f2);
			*/printf("%d %d\n",vrar.n,vrar.nn);
			for(i=0;i<vrar.nn;i++)
				printf("%d ",vrar.x[i]);
			printf("\n");
			for(i=0;i<vrar.nn;i++)
				printf("%d ",vrar.poz[i]);
			printf("\n");
		}
	}

}

int main(int argc,char *argv[])
{
	FILE *f1,*f2;
	int n1,n2;

	if(argc!=5)
	{
		fprintf(stderr, "Date introduse gresit\n");
		return -1;
	}

	if((f1=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr, "Nu se poate deschide fisierul nf1\n");
		return -1;
	}
	if((f2=fopen(argv[2],"wb"))==NULL)
	{
		fprintf(stderr, "Nu se poate scrie in fisierul nf2\n");
		return -1;
	}

	n1=atoi(argv[3]);
	n2=atoi(argv[4]);
	aduna(f1,f2,n1,n2);
	
	fclose(f1);
	fclose(f2);
	return 0;
}
