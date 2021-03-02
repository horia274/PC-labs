#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[])
{
	FILE *f;
	int i;
	char buff[65];
	f=fopen(argv[1],"r");
	while(!feof(f))
	{
		fread(buff,sizeof(char),64,f);
		for(i=0;i<strlen(buff);i++)
			printf("%X ",buff[i]);
		printf("\n");
	}
	return 0;
}
