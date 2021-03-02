#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	char cat[20],comp[25],numef[20],buff[100],fisiere[100][100];
	int n1,n2,i,nrf=0,j=0,k,ok;
	strcpy(cat,argv[1]);
	strcpy(comp,cat);
	strcat(comp,".cpl");
	//printf("%s\n%s\n",cat,comp);
	FILE *fcat,*fcomp,*f;
	fcat=fopen(cat,"r");
	fcomp=fopen(comp,"w");
	while(!feof(fcat))
	{
		fscanf(fcat,"%s",numef);
		fscanf(fcat,"%d %d\n",&n1,&n2);
		f=fopen(numef,"r");
		ok=1;
		for(k=0;k<j;k++)
			if(strcmp(fisiere[k],numef)==0)
				ok=0;
		if(ok==1)
		{
			nrf++;
			strcpy(fisiere[j],numef);
			j++;
		}
		i=1;
		while(i<n1)
		{
			fgets(buff,100,f);
			i++;
		}
		while(i<=n1+n2-1)
		{
			fgets(buff,100,f);
			i++;
			fprintf(fcomp,"%s",buff);
		}
		fclose(f);
	}
	printf("%d\n",nrf);
	fclose(fcat);
	fclose(fcomp);
	return 0;
}