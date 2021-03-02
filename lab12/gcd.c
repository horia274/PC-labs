#include <stdio.h>
#include <stdarg.h>

int gcd2(int a,int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int gcd(int n,...)
{
	va_list args;
	int x,y,d,i;
	va_start (args,n);
	x=va_arg(args,int);
	for(i=1;i<n;i++)
	{
		y=va_arg(args,int);
		d=gcd2(x,y);
		x=d;
	}
	va_end(args);
	return d;
}

int main()
{
	printf("%d\n",gcd(3,1,4,6));
	return 0;
}
