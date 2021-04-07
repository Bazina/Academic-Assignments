#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int digit(int n, int k){
    int i;
    for (i = 1; i < k && n >= 0; i++){
        n = n/10;
    }
    if (n == 0){
        return 0;
    } else {
        return (n % 10);
    }
}

int main() {

    int num, pos;
    printf("\nEnter number and digit position: ");
    scanf("%d %d", &num, &pos);
    int dig = digit(num, pos);
    printf("Digit: %d\n", dig);
    return 0;
}
