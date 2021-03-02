#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int verif(char *p)
{
	int i;
	for(i=0;i<strlen(p);i++)
		if(p[i]<'A'|| (p[i]>'Z'&&p[i]<'a') ||p[i]>'z')
			return 0;
	return 1;
}
int main()
{
	char s[100];
	int i,nr=0;
	fgets(s,100,stdin);
	char *p;
	//p=(char*)malloc(100*sizeof(char));
	p=strtok(s," !?.,:;\n\t");
	while(p!=NULL)
	{
		printf("%s\n",p);
		if(verif(p)==1);
			nr++;
		p=strtok(NULL," !?.,:;\n\t");
	}
	printf("%d\n",nr);
	return 0;
}