#include <stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int e1=(a+b)*(c-d);
	int e2=((a+b))*((c-d));
	printf("%d\n%d\n",e1,e2);
	printf("Hello there, %s!\n", "student");
	printf(("Hello there, %s!\n", "student"));
	return 0;
}