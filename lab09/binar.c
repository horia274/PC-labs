#include <stdio.h>
int main()
{
	FILE *f1, *f2;
	f1=fopen("binar.bin","wb");
	f2=fopen("file.txt","r");
	int n,x[100],i;
	fscanf(f2,"%d",&n);
	fwrite(&n,sizeof(int),1,f1);
	for(i=0;i<n;i++)
		fscanf(f2,"%d",&x[i]);
	fwrite(x,sizeof(int),n,f1);
	fclose(f1);
	fclose(f2);
	return 0;
}