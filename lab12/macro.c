#include <stdio.h>
#define DUBLU(a) (2*(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b)) 
/*#define CHANGE
#undef CHANGE*/
#define GIGEL 1
#ifdef CHANGE
#undef GIGEL // sterg GIGEL
#define GIGEL 0 // redefinesc simbolul cu alta valoare
#endif

int main()
{
	printf("GIGEL = %d\n", GIGEL);
	printf("%d %d\n",DUBLU(5),MAX(2,3));
	return 0;
}