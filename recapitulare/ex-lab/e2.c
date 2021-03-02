#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	int i;
	FILE *f;
	f=fopen(argv[2],"w");
	for(i=0;i<strlen(argv[1]);i++)
		if(isalpha(argv[1][i])!=0)
			argv[1][i]='*';
	fprintf(f,"%s",argv[1]);
	return 0;
}