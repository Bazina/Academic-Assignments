#include <stdio.h>

long long int binConv(long long int sum){
    if (sum == 1){
        return sum;
    } else {
        long long int bin = sum % 2, div = sum / 2;
        return (bin + binConv(div));
    }
}

long long int sumScan(long long int size){
    int elem;
    if (size == 0){
        return size;
    }
    scanf("%d", &elem);
    return (elem + sumScan(size - 1));
}

void scanS(int test, int t, int arr[]){
    long long int size = 0, sum = 0;
    int bin;
    if (test == 0){
        return;
    } else {
        printf("Enter size: ");
        scanf("%lld", &size);
        printf("Enter elements: ");
        sum = sumScan(size);
        bin = binConv(sum);
        arr[test - 1] = bin;
        scanS(test - 1, t, arr);
        printf("\nResult for each array: ");
        printf("%d\n", arr[t - test]);
    }
}

int main(){
    int test;
    printf("\nEnter number of test cases: ");
    scanf("%d", &test);
    int arr[test], t = test;
    scanS(test, t, arr);
    return 0;
}
