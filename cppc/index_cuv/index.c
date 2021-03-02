#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 100

typedef struct
{
	int l;
	char cuv[15];	
} art_cuv;

int main(int argc,char *argv[])
{
	FILE *fin,*fout,*f1,*f2;
	char name_fout[15],*c,*q,line[MAX_LINE],delim[7]=".,:;-\n ";
	int m,n,p,ok,pos,freq;
	art_cuv a,b;

	if(argc!=5)
	{
		fprintf(stderr, "Introducere necorespunzatoare a datelor\n");
		return -1;
	}

	memset(name_fout,0,15);
	c=strchr(argv[1],'.');
	if(c!=NULL)
		strncpy(name_fout,argv[1],c-argv[1]);
	else
		strcpy(name_fout,argv[1]);
	strcat(name_fout,".idx");

	m=atoi(argv[2]);
	n=atoi(argv[3]);
	p=atoi(argv[4]);

	if((fin=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr, "Nu exista fisierul %s\n", argv[1]);
		return -1;
	}
	if((f1=fopen("f1","w+b"))==NULL)
	{
		fprintf(stderr, "Nu se poate crea fisierul f1\n");
		return -1;
	}
	if((f2=fopen("f2","w+b"))==NULL)
	{
		fprintf(stderr, "Nu se poate crea fisierul f2\n");
		return -1;
	}
	if((fout=fopen(name_fout,"wb"))==NULL)
	{
		fprintf(stderr, "Nu se poate crea fisierul %s\n",name_fout);
		return -1;
	}

	while(fgets(line,MAX_LINE,fin))
	{
		line[strlen(line)-1]='\0';
		q=strtok(line," \n.,;:");
		while(q!=NULL)
		{
			memset(a.cuv,0,15);
			a.l=strlen(q);
			a.l++;
			strcpy(a.cuv,q);
			//printf("%d %s\n",a.l,a.cuv);
			q=strtok(NULL," \n.,;:");
			fwrite(&a.l,sizeof(int),1,f1);
			fwrite(a.cuv,sizeof(char),a.l,f1);
		}
	}
	fclose(fin);

	/*printf("\n");
	fseek(f1,0,SEEK_SET);
	while(fread(&a.l,sizeof(int),1,f1))
	{
		fread(a.cuv,sizeof(char),a.l,f1);
		printf("%d %s\n",a.l,a.cuv);
	}*/

	fseek(f1,0,SEEK_SET);
	while(fread(&a.l,sizeof(int),1,f1))
	{
		fread(a.cuv,sizeof(char),a.l,f1);
		pos=ftell(f1);
		fseek(f2,0,SEEK_SET);
		ok=0;
		while(!feof(f2)&&ok==0)
		{
			fread(&b.l,sizeof(int),1,f2);
			fread(b.cuv,sizeof(char),b.l,f2);
			fread(&freq,sizeof(int),1,f2);
			if(strcmp(a.cuv,b.cuv)==0)
				ok=1;
		}
		if(ok==0)
		{
			freq=1;
			fseek(f2,0,SEEK_END);
			fwrite(&a.l,sizeof(int),1,f2);
			fwrite(a.cuv,sizeof(char),a.l,f2);
			while(fread(&b.l,sizeof(int),1,f1))
			{
				fread(b.cuv,sizeof(char),b.l,f1);
				if(strcmp(a.cuv,b.cuv)==0)
					freq++;
			}
			fwrite(&freq,sizeof(int),1,f2);
			fseek(f1,pos,SEEK_SET);
		}
	}

	/*fseek(f2,0,SEEK_SET);
	while(fread(&a.l,sizeof(int),1,f2))
	{
		fread(a.cuv,sizeof(char),a.l,f2);
		fread(&freq,sizeof(int),1,f2);
		printf("%d %d %s\n",a.l,freq,a.cuv);
	}*/

	fseek(f2,0,SEEK_SET);
	while(fread(&a.l,sizeof(int),1,f2))
	{
		fread(a.cuv,sizeof(char),a.l,f2);
		fread(&freq,sizeof(int),1,f2);
		if((a.l-1)>=m && (a.l-1)<=n && freq>=p)
		{
			//printf("%s - %d\n",a.cuv,freq);
			fwrite(&a.l,sizeof(int),1,fout);
			fwrite(a.cuv,sizeof(char),a.l,fout);
			fwrite(&freq,sizeof(int),1,fout);
		}
	}
	fclose(f1);fclose(f2);fclose(fout);
	return 0;
}
