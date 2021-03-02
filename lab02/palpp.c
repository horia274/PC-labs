#include <stdio.h>
int pal (int a)
{
	int b, r;
	b = a;
	r = 0;
	while (a > 0)
	{
		r = r * 10 + a % 10;
		a /= 10;
	}
	if (b == r)
		return 1;
	return 0;
}
int scif (int a)
{
	int s;
	s = 0;
	while (a > 0)
	{	
		s += a % 10;
		a /= 10;
	}
	return s;
}
int maxpp (int a)
{
	int k;
	k = 0;
	while (k * k < a)
	{
		k++;
	}
	return (k - 1) * (k - 1);
}
int functie (int a,int b)
{
	if (pal (b) == 1)
		printf("%d\n", scif (a));
	else
		printf("%d\n", maxpp (a));
}
int main ()
{
	int a,b;
	scanf("%d%d", &a, &b);
	functie (a,b);
	return 0;
}