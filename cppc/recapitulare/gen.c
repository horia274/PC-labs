#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

long* newVect(int n, ...){
	va_list ap;
	int i;
	long *a;
	a=(long*)malloc((n+1)*sizeof(long));
	va_start(ap, n);
	a[0]=n;
	for(i = 1; i < n+1; i++)
		a[i] = va_arg(ap, long);
	va_end(ap);
	return a;
}

void init(char *file1,char *file2, char *file3){
	FILE *f1,*f2,*f3;
	int i,j;
	long *p[3] = {
		newVect(6, 7, 8, 20, 35, 56, 70),
		newVect(6, 2, 10, 23, 45, 101, 206),
		newVect(10, 4, 6, 12, 25, 40, 47, 67, 123, 145, 204)
	};

	for(i=0;i<3;i++)
	{
		for(j=1;j<=p[i][0];j++)
			printf("%ld ",p[i][j]);
		printf("\n");
	}

	f1=fopen(file1,"wb");
	f2=fopen(file2,"wb");
	f3=fopen(file3,"wb");

	for(j=1;j<=p[0][0];j++)
		fwrite(&p[0][j],sizeof(long),1,f1);
	for(j=1;j<=p[1][0];j++)
		fwrite(&p[1][j],sizeof(long),1,f2);
	for(j=1;j<=p[2][0];j++)
		fwrite(&p[2][j],sizeof(long),1,f3);
	
	fclose(f1);fclose(f2);fclose(f3);
}

int main(int argc, char *argv[]){
	FILE *f1,*f2,*f3;
	long x;
	init(argv[1],argv[2],argv[3]); /* se creeaza un fisier de intrare */
	f1=fopen(argv[1],"rb");
	f2=fopen(argv[2],"rb");
	f3=fopen(argv[3],"rb");
	
	printf("\n");
	while(fread(&x,sizeof(long),1,f1))
		printf("%ld ",x);
	printf("\n");
	
	while(fread(&x,sizeof(long),1,f2))
		printf("%ld ",x);
	printf("\n");
	
	while(fread(&x,sizeof(long),1,f3))
		printf("%ld ",x);
	printf("\n");
	return 0;
}
