#include <stdio.h>
#include <stdlib.h>

// print array of size n
int check(int a[], int n){
    int i, f = 1;
    for (i = 0; i < n; i++){
        if (a[i] != 0){
            f = 0;
        }
    }
    return (f);
}

void print_array(int a[], int n) {
    int i, f;
    f = check(a, n);
    if (f == 0){
        for(i = n-1; i>= 0;i--){
            if(a[i] > 0){
                break;
            }
        }
        printf("\nMultiplication Result: ");
        for(;i >= 0;i--){
            printf("%d", a[i]);
        }
        printf("\n");
    } else {
        printf("\nMultiplication Result: %d\n",0);
    }
}

// scans a single integer into array with size n
void scan_array(int a[], int n) {
	for(int i = 0; i < n; i++) {
		scanf("%1d", &a[i]);
	}
}

void reverse_array(int a[], int n){
    int i, j, temp;
    for (i = n-1, j = 0; i > j; i--, j++){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}

// the multiplication operation
// it is better to split the logic on several other functions
// then make multiply function call them.
void multiply(int a[], int n, int b[], int m, int res[], int t) {
    int temp, i, j;

    reverse_array(a, n);
    reverse_array(b, m);

    for (i = 0; i < t; i++){
        res[i] = 0;
    }

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            res[i+j] += b[i] * a[j];
        }
    }
    for (i = 0; i < t; i++){
        temp = res[i]/10;
        res[i] = res[i]%10;
        res[i+1] = res[i+1] + temp;
    }
}

// don't change any thing in the main
int main() {

	int n;
	printf("\nEnter size of first number: ");
	scanf("%d", &n);
	int x[n];
	printf("Enter first number: ");
	scan_array(x, n);

	int m;
	printf("Enter size of second number: ");
	scanf("%d", &m);
	int y[m];
	printf("Enter second number: ");
	scan_array(y, m);

	int t = n + m;
	int ans[t];

	multiply(x, n, y, m, ans, t);
	print_array(ans, t);

	return 0;
}
