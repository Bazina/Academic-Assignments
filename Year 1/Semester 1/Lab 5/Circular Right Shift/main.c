#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n, f;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (n <= 12 && n >=0){
        f = 1;
        for (int i = 1; i <= n; ++i){
            f *= i;
        }
        printf("Factorial = %d\n", f);
    }
    else{
        printf("Enter number between 0 and 12\n");
    }
    return 0;
}
