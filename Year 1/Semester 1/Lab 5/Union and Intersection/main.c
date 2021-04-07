#include <stdio.h>

int main()
{
    int n1, n2, arr1[20], arr2[20], Union[40], Intersection[20], i, j, f, k=0, m=0, t=0;
    printf("Enter Array 1 size: ");
    scanf("%d", &n1);
    printf("Enter Array 1 elements: ");
    for(i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }

    for(i = 0; i < n1; i++){
        for(j = i+1; j < n1; j++){
            if(arr1[i] == arr1[j]){
                for(k = j; k < n1; k++){
                    arr1[k] = arr1[k + 1];
                }
                n1--;
                j--;
            }
        }
    }
    printf("Enter Array 2 size: ");
    scanf("%d", &n2);
    printf("Enter Array 2 elements: ");
    for(i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }

    for(i = 0; i<n2; i++){
        for(j = i+1; j < n2; j++){
            if(arr2[i] == arr2[j]){
                for(k = j; k < n2; k++){
                    arr2[k] = arr2[k + 1];
                }
                n2--;
                j--;
            }
        }
    }

    for (i = 0; i < n1; i++){
        for (j = 0; j < n2; j++){
            if (arr1[i] == arr2[j]){
                Intersection[m] = arr1[i];
                m++;
            }
        }
    }

    for (i = 0; i < n1; i++){
        Union[t] = arr1[i];
        t++;
    }
    for (i = 0; i < n2; i++){
        f = 0;
        for (j = 0; j < n1; j++){
            if (arr2[i] == arr1[j]){
                f = 1;
            }
        }
        if (f == 0){
            Union[t] = arr2[i];
            t++;
        }
    }

    printf("Array1: ");
    for (i = 0; i < n1; i++){
        printf("%d", arr1[i]);
        if (i < n1-1){
            printf(", ");
        }
    }

    printf("\nArray2: ");
    for (i = 0; i < n2; i++){
        printf("%d", arr2[i]);
        if (i < n2-1){
            printf(", ");
        }
    }
    printf("\nUnion: ");
    for (i = 0; i < t; i++){
        printf("%d", Union[i]);
        if (i < t-1){
            printf(", ");
        }
    }
    printf("\nIntersection: ");
    for (i = 0; i < m; i++){
        printf("%d", Intersection[i]);
        if (i < m-1){
            printf(", ");
        }
    }

    return 0;
}
