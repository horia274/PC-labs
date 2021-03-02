#include <stdio.h>
int main()
{
	struct test_struct
	{
		char a;
		double b;
		short c;
		int d;
		short e;
	}t;
	printf("%ld\n",sizeof(t));
	//printf("%ld\n",sizeof(x.a)+sizeof(x.b)+sizeof(x.c)+sizeof(x.d));
	void *start,*offset;
	start = &t;
	
	offset = &t.a;
	printf("Offset a: %ld\n", offset - start);
 
	offset = &t.b;
	printf("Offset b: %ld\n", offset - start);
 
	offset = &t.c;
	printf("Offset c: %ld\n", offset - start);
 
	offset = &t.d;
	printf("Offset d: %ld\n", offset - start);
	
	offset = &t.e;
	printf("Offset d: %ld\n", offset - start);
	return 0;
}