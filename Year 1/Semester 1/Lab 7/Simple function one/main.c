#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long int calc(int n){
    long long int res = 3*pow(n, 5) + 2*pow(n, 4) - 5*pow(n, 3) - pow(n, 2) + 7*n - 6;
    return (res);
}

int main() {
    int x;
    printf("\nEnter integer X: ");
    scanf("%d", &x);
    long long int ans = calc(x);
    printf("Equation result: %lld\n", ans);
    return 0;
}
