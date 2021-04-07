#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int x, rev = 0, og;
    printf("\nEnter Number: ");
    scanf("%d", &x);
    og = x;

    while (og != 0){
       rev = rev * 10 + og % 10;
       og /= 10;
    }
    if (rev == x) {
        printf("%d is a palindrome number", x);
    }
    else {
        printf("%d is not a palindrome number", x);
    }
    return 0;
}
