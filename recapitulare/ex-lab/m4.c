#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	return (a+b+abs(a-b))/2;
}
int min(int a,int b)
{
	return (a+b-abs(a-b))/2;
}
int main(int argc,char *argv[])
{
	printf("%d %d\n",max(atoi(argv[1]),atoi(argv[2])),min(atoi(argv[1]),atoi(argv[2])));
	return 0;
}