#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int conv(int num, int base){
    int convDig;
    if (num != 0) {
        convDig = num % base;
        num = num / base;
        conv(num, base);
        (convDig > 9) ? printf("%c", convDig + 55) : printf("%d", convDig);
    }
}

int main(){
    long long int num;
    int base;
    printf("Enter number & base: ");
    scanf("%lld %d", &num, &base);
    printf("\nDigits: ");
    if (base == 10){
        printf("%d", num);
    } else {
        // Determine if the number is positive or negative
        num = (num < 0) ? -num : num;
        conv(num, base);
    }
    printf("\n");
    return 0;
}
