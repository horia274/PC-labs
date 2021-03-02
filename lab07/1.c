#include <stdio.h>
#include <string.h>
#include <ctype.h>
int verif(char *c)
{
	int n,i,m,j;
	n=strlen(c);
	m=n;
	for(i=0;i<m;i++)
		if(c[i]==' ')
			for(j=i;j<m;j++)
				{
					c[j]=c[j+1];
					n--;
				}
	for(i=0;i<n/2;i++)
		if(c[i]!=c[n-1-i]&&c[i]!=tolower(c[n-1-i])&&c[i]!=toupper(c[n-1-i]))
			return 0;
	return 1;
}
int main()
{
	char c[100];
	fgets(c,100,stdin);
	c[strlen(c)-1]='\0';
	if(verif(c)==1)
		printf("este palindrom\n");
	else
		printf("nu este palindrom\n");
	return 0;
}