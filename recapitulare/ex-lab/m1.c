#include <stdio.h>
int main()
{
	int x[10],i;
	char *p;
	for(i=0;i<10;i++)
		x[i]=i;
	p=(char*)x;
	for(i=0;i<40;i++)
		printf("%02X ",p[i]);
	printf("\n");
	return 0;
}