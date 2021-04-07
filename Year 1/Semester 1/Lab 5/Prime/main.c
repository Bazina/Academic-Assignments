#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x, i, id = 0;
    printf("Enter number: ");
    scanf("%d", &x);
    if (x <= 1000000 && x >= 1){
        for (i = 2; i <= x; ++i){
            if (x % i == 0){
                id = 0;
                break;
            }
        }
        if (x == i){
            id = 1;
        }
        if (id == 1){
            printf("%d is prime\n", x);
        }
        else {
            printf("%d is not prime\n", x);
        }
    }
    else {
        printf("Enter number between 1000000 and 0\n");
    }

    return 0;
}
