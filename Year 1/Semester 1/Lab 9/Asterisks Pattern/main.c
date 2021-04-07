#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int printpat(int n){
    if (n > 0){
        printpat(n - 1);
        printf("*");
    }
}

int pattern(int n, int t){
    if (n > 0){
        pattern(n - 1, t);
    }
    if (n <= t){
        printpat(n);
        printf("\n");
    } else {
        printpat(-n + t*2);
        printf("\n");
    }
}

int main(){
    int n;
    printf("\nEnter Number for the highest line of Asterisks: ");
    scanf("%d", &n);
    int t = n;
    pattern((n*2) - 1, t);
    return 0;
}
