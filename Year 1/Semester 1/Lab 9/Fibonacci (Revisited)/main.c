#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fibo(int n){
    int fib = 1;
    if (n == 2){
        fib = 1;
    } else if (n > 2){
        fib = fibo(n - 1) + fibo(n - 2);
    } else if (n == 0){
        fib = 0;
    }
    return fib;
}
int main(){
    int nterm, res;
    printf("Fibonacci Nth term: ");
    scanf("%d", &nterm);
    res = fibo(nterm);
    printf("Fibonacci of %d = %d", nterm, res);
    return 0;
}
