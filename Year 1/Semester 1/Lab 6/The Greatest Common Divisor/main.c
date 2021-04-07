#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b, gcd, i;
    printf("\nEnter 2 Numbers: ");
    scanf("%d %d", &a, &b);
    if (a != 0 && b != 0){
        for (i = 1; i <= a && i <= b; i++){
            if (a % i == 0 && b % i == 0){
                gcd = i;
            }
        }
    }
    else {
        gcd = a + b;
    }

    printf("GCD: %d\n", gcd);
    return 0;
}
