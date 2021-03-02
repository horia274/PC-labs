#include <stdio.h>
void inv (int a)
{
	if (a < 10)
		printf("%d", a);
	else
	{
		printf("%d", a % 10);
		inv (a / 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	inv (n);
}