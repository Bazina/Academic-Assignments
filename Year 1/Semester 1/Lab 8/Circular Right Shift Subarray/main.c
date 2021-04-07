#include <stdio.h>
#include <stdlib.h>

//reverse elements of sub array from a[left] to a[right]
void reverse(int a[], int left, int right) {
    int tmp = a[left];
    a[left] = a[right];
    a[right] = tmp;

}

// shift the sub array a[left...right] to the right
//use reverse() as stated above
void shift(int a[], int left, int right, int k) {
    int i, j;
    k = k % (right - left + 1);
    for (i = 0; i < k; i++){
        for(j = left; (right - j + 1) >= 2; j++){
            reverse(a,j,right);
        }
    }
}

// reads a single query and process it by updating a[]
void process_query(int a[]) {
    int left, right, k;
    scanf("%d %d %d", &left, &right, &k);
    shift(a, left, right, k);
}

// scans array of size n
void scan_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

// print array of size n
void print_array(int a[], int n) {
    int i;
    printf("\nResult after shift: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

// don't change any thing in the main
int main() {

    int n, q;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
    scan_array(a, n);

    printf("Enter number of queries: ");
    scanf("%d", &q);
    printf("Enter left, right, shift elements: ");
    for(int i = 0; i < q; i++) {
        process_query(a);
    }

    print_array(a, n);

    return 0;
}
