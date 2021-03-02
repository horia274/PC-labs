#include <stdio.h>
int main()
{
	FILE* f;
	f=fopen("file.txt","r");
	fseek(f,0,SEEK_SET);
	int s,n,x,i;
	s=0;
	fscanf(f,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(f,"%d",&x);
		s+=x;
	}
	printf("%d\n",s);
	fclose(f);
	return 0;
}