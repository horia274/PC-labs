#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char nume[20];
	double notaExamen;
	unsigned int nrTeme;
	double *noteTeme;
}TMaterie;

typedef struct
{
	char nume[20];
	unsigned int nrMaterii;
	unsigned int nrCrtMaterii;
	TMaterie *materii;
	char restantier;
}TStudent;

typedef struct
{
	char *nume;
	unsigned int nrMaxStudenti;
	unsigned int nrCrtStudenti;
	TStudent *studenti;
}TGrupa;

TGrupa aloc_grupa(char *nume,unsigned int nrMaxStudenti)
{
	TGrupa x;
	x.nume=(char*)malloc(strlen(nume)*sizeof(char));
	strcpy(x.nume,nume);
	x.nrMaxStudenti=nrMaxStudenti;
	x.nrCrtStudenti=0;
	x.studenti=(TStudent*)malloc(nrMaxStudenti*sizeof(TStudent));
	return x;
}

TStudent aloc_student(char *nume,unsigned int nrMaterii)
{
	TStudent x;
	strcpy(x.nume,nume);
	x.nrMaterii=nrMaterii;
	x.nrCrtMaterii=0;
	x.materii=(TMaterie*)malloc(nrMaterii*sizeof(TMaterie));
	return x;
}

void add_student(TStudent student, TGrupa grupa)
{
	grupa.nrCrtStudenti++;
	if(grupa.nrCrtStudenti>grupa.nrMaxStudenti)
	{
		grupa.nrMaxStudenti*=2;
		grupa.studenti=(TStudent*)realloc(grupa.studenti,grupa.nrMaxStudenti*sizeof(TStudent));
	}
	grupa.studenti[grupa.nrCrtStudenti]=student;
}

int main()
{
	TGrupa x;
	x=aloc_grupa("314CA",20);
	printf("%s\n%d\n",x.nume,x.nrMaxStudenti);
	return 0;
}