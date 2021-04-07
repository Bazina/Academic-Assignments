#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void seq(int n, int n1){
    if (n == 0){}
    else if (n > 0 && n1 <= n){
        printf("Sequence %d ", n1);
        seq(n, n1 + 1);
    }
}

int main(){
    int n, n1 = 1;
    printf("\nEnter number: ");
    scanf("%d", &n);
    seq(n, n1);
    return 0;
}
