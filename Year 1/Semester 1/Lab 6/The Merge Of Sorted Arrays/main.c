#include<stdio.h>

int main() {
	int i, j = 0, k = 0, n, m;

    printf("Enter size of Array 1: ");
	scanf("%d", &n);
	int arr1[n];
	printf("Enter Array 1 elements: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
	}

    printf("Enter size of Array 2: ");
	scanf("%d", &m);
	int arr2[m];
	printf("Enter Array 2 elements: ");
	for (i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}

	int merge[m + n];
	i = 0;

	while (i < n && j < m) {
		if (arr1[i] <= arr2[j]) {
			merge[k++] = arr1[i++];
		} else {
            merge[k++] = arr2[j++];
		}
	}

	while (i < n) {
		merge[k++] = arr1[i++];
	}

	while (j < m) {
		merge[k++] = arr2[j++];
	}

    printf("Merge: ");
	for (i = 0; i < n + m; i++) {
		printf("%d ", merge[i]);
	}
	return 0;
}
