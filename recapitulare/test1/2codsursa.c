#include <stdio.h>
int main()
{
    FILE *fp;
    int c;
    fp = fopen(__FILE__,"r");
    do
    {
        c = getc(fp);
        putc(c,stdout);
    }
    while(c != EOF);
    fclose(fp);
    return 0;
}