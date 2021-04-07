#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int sumDigit(long long int n){
    int res = 0;
    if (n != 0){
        res = n%10 + sumDigit(n/10);
    }
    return res;
}

int main() {
    long long int n, res;
    printf("\nEnter number: ");
    scanf("%lld", &n);
    res = sumDigit(n);
    printf("Sum of digits of %lld = %lld", n, res);
    return 0;
}
