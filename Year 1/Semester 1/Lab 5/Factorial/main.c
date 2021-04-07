#include<stdio.h>

int main() {
    int n, k, i, temp;
    printf("Enter array size & shift number: ");
    scanf("%d %d", &n ,&k);
    int narr[n];
    printf("Enter array elements: ");
    for(i = 0; i < n; i++){
        temp = i + k;
        if(temp >= n){
           temp = temp % n;
        }
        scanf("%d", &narr[temp]);
    }
    printf("Shifted Array: ");
    for(i = 0; i < n; i++){
       printf("%d ", narr[i]);
    }
    return 0;
}
