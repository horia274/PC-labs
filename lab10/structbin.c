#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	FILE *f;
	f=fopen("fbin","wb");
	char buff[1000];
	struct elev
	{
		char *nume;
		int lg_nume;
		int age;
	};
	struct elev *x;
	int n,i;
	scanf("%d",&n);
	x=(struct elev*)malloc(n*sizeof(struct elev));
	for(i=0;i<n;i++)
	{
		scanf("%s",buff);
		x[i].nume=(char*)malloc(strlen(buff)*sizeof(char));
		strcpy(x[i].nume,buff);
		x[i].lg_nume=strlen(buff);
		scanf("%d",&x[i].age);
	}
	fwrite(x,sizeof(struct elev),n,f);
	for(i=0;i<n;i++)
	{
		fwrite(x[i].nume,sizeof(char),x[i].lg_nume,f);
		fwrite(&x[i].lg_nume,sizeof(int),1,f);
		fwrite(&x[i].age,sizeof(int),1,f);
		printf("%s",x[i].nume);
		printf(" %d %d\n",x[i].lg_nume,x[i].age);
	}
	for(i=0;i<n;i++)
		free(x[i].nume);
	free(x);
	fclose(f);
	return 0;
}