#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	typedef struct
	{
		int v;
		char *nume;
	}elev;
	elev x1,x2;
	char buff[20];
	scanf("%d",&x1.v);
	scanf("%s",buff);
	x1.nume=(char*)malloc((strlen(buff)+1)*sizeof(char));
	strcpy(x1.nume,buff);
	x2=x1;
	x2.nume=(char*)malloc((strlen(buff)+1)*sizeof(char));
	x2.nume="Don";
	printf("%s\n%s",x1.nume,x2.nume);
	return 0;
}