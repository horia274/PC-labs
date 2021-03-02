#include <stdio.h>
int main()
{
	FILE* f;
	f=fopen("file.txt","w");
	fprintf(f,"%s","7\n1 2 3 4 5 6 7\n");
	fclose(f);
	return 0;
}