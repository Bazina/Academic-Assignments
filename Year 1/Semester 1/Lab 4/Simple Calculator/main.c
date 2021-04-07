#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a, b;
    char op;
    printf("Enter a then operator then b: ");
    scanf("%d %c %d", &a, &op, &b);

    if ((op == '+')||(op == '-')||(op == '/')||(op == '*')||(op == '%')){
        if(op == '/'||op == '%'){
            if(b==0){
                printf("\nERROR: Division by zero is not allowed!");
            }
            else if (op == '/') {
                printf("\n%d %c %d = %d", a, op, b, a/b);
            }
            else {
                printf("\n%d %c %d = %d", a, op, b, a%b);
            }
        }
        else if (op == '+') {
            printf("\n%d %c %d = %d", a, op, b, a+b);
        }
        else if (op == '*') {
            printf("\n%d %c %d = %d", a, op, b, a*b);
        }
        else if (op == '-') {
            printf("\n%d %c %d = %d", a, op, b, a-b);
        }
    }
    else {
        printf("\nERROR: Unsupported Operator!");
    }
    return 0;
}
