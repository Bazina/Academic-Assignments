#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
    int n, m, f, i, j, k;
    printf("\nMultiplication Result: %d\n",0);
    scanf("%d %d %d", &n, &f, &m);
    int mat1[n][f], mat2[f][m], res[n][m];
    printf("Enter Matrix 1 Elements: \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < f; j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter Matrix 2 Elements: \n");
    for (i = 0; i < f; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            res[i][j] = 0;
            for (k = 0; k < f; k++){
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("\nMultiplication Matrix: \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d ", res[i][j]);
            if (j == m-1){
                printf("\n");
            }
        }
    }
    return 0;
}
