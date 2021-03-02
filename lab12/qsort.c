#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b)
{
	int* x = (int*)a;
	int* y = (int*)b;
	return *x>*y;
	// daca a>b se interschimba
	// sort cresc
}

int main()
{
	int i,v[]={5,3,7,4};
	qsort(v,4,sizeof(int),cmp);
	for(i=0;i<4;i++)
		printf("%d ",v[i]);
	printf("\n");
	return 0;
}
