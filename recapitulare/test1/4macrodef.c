#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define square(x) (x)*(x)
int main(int argc,char *argv[])
{
	int n,i;
	if(argc==1||argc>4)
	{
		printf("Eroare\n");
		exit(0);
	}
	for(i=2;i<argc;i++)
		if(strcmp(argv[i],"-a")!=0&&strcmp(argv[i],"-p")!=0)
		{
			printf("Eroare\n");
			exit(0);
		}
	for(i=0;i<strlen(argv[1]);i++)
		if(argv[1][i]<'0'||argv[1][i]>'9')
		{
			printf("Eroare\n");
			exit(0);
		}
	n=atoi(argv[1]);
	for(i=2;i<argc;i++)
	{
		if(strcmp(argv[i],"-a")==0)
			printf("%p\n",&n);
		if(strcmp(argv[i],"-p")==0)
			printf("%d\n",square(n));
	}
	return 0;
}