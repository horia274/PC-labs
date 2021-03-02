#include <stdio.h>
int main()

{
    int n;
    scanf("%d", &n);  
    int cnt = 0;
    int i, x;
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            printf("%d\n", x);
            ++cnt;
        }
            
     }
     printf("%d\n", cnt);
     return 0;
 }