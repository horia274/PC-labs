#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *f;
	char num[2];
	f=fopen("file.txt","r");
	sprintf(num,"%c",getc(f));
	printf("%s\n",num);
	printf("%d\n",atoi(num));
	return 0;
}