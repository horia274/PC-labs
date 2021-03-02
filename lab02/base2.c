#include <stdio.h>
int baza2 (int a)
{
	if (a == 1)
		printf("%d", a);
	else
	{
		baza2 (a / 2);
		printf("%d", a % 2);
	}
}
int main ()
{
	int n;
	scanf("%d", &n);
	baza2 (n);
}