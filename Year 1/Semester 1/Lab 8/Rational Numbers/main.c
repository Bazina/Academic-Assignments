#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
    int gcd, i;
    if (a != 0 && b != 0){
        for (i = 1; i <= a && i <= b; i++){
            if (a % i == 0 && b % i == 0){
                gcd = i;
            }
        }
    }
    else {
        gcd = a + b;
    }

    return gcd;
}

typedef struct Frac{
    int numer;
    int den;
    int lowNumer;
    int lowDen;
}fraction;

fraction add(fraction num1, fraction num2);

fraction subtract(fraction num1, fraction num2);

fraction multiply(fraction num1, fraction num2);

fraction divide(fraction num1, fraction num2);

int main(){
    fraction num1, num2;
    char ope;
    printf("Enter number 1: ");
    scanf("%d/%d", &num1.numer, &num1.den);
    printf("Enter number 2: ");
    scanf("%d/%d", &num2.numer, &num2.den);
    if (num1.den == 0 || num2.den == 0){
        printf("\nMath Error\n");
        return;
    }
    int gcd1 = GCD(num1.numer, num1.den);
    num1.lowNumer = num1.numer / gcd1;
    num1.lowDen = num1.den / gcd1;
    int gcd2 = GCD(num2.numer, num2.den);
    num2.lowNumer = num2.numer / gcd2;
    num2.lowDen = num2.den / gcd2;
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &ope);
    switch (ope){
        case '+':
            add(num1, num2);
            break;
        case '-':
            subtract(num1, num2);
            break;
        case '*':
            multiply(num1, num2);
            break;
        case '/':
            divide(num1, num2);
            break;
        default:
            printf("\nWrong operator was entered\n");
    }

    return 0;
}

fraction add(fraction num1, fraction num2){
    if (num1.lowDen == num2.lowDen){
        int sum = num1.lowNumer + num2.lowNumer;
        int sgcd1 = GCD(sum, num1.lowDen);
        int lowsum = sum / sgcd1;
        int lowden = num1.lowDen / sgcd1;
        if (lowden == 1){
            printf("\n%d/%d + %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsum);
        }
        else if (lowsum == 0){
            printf("\n%d/%d + %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsum);
        } else {
            printf("\n%d/%d + %d/%d = %d/%d\n", num1.numer, num1.den, num2.numer, num2.den, lowsum, lowden);
        }
    } else {
        int sDen = num1.lowDen * num2.lowDen;
        int sNum = (num1.lowNumer * num2.lowDen) + (num2.lowNumer * num1.lowDen);
        int sgcd2 = GCD(sNum, sDen);
        int lowsDen = sDen / sgcd2;
        int lowsNum = sNum / sgcd2;
        if (lowsDen == 1){
            printf("\n%d/%d + %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsNum);
        }
        else if (lowsNum == 0){
            printf("\n%d/%d + %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsNum);
        } else {
            printf("\n%d/%d + %d/%d = %d/%d\n", num1.numer, num1.den, num2.numer, num2.den, lowsNum, lowsDen);
        }
    }
}

fraction subtract(fraction num1, fraction num2){
    if (num1.lowDen == num2.lowDen){
        int sub = num1.lowNumer - num2.lowNumer;
        int sgcd1 = GCD(sub, num1.lowDen);
        int lowsub = sub / sgcd1;
        int lowden = num1.lowDen / sgcd1;
        if (lowden == 1){
            printf("\n%d/%d - %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsub);
        }
        else if (lowsub == 0){
            printf("\n%d/%d - %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsub);
        } else {
            printf("\n%d/%d - %d/%d = %d/%d\n", num1.numer, num1.den, num2.numer, num2.den, lowsub, lowden);
        }
    } else {
        int sDen = num1.lowDen * num2.lowDen;
        int sNum = (num1.lowNumer * num2.lowDen) - (num2.lowNumer * num1.lowDen);
        int sgcd2 = GCD(sNum, sDen);
        int lowsDen = sDen / sgcd2;
        int lowsNum = sNum / sgcd2;
        if (lowsDen == 1){
            printf("\n%d/%d - %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsNum);
        }
        else if (lowsNum == 0){
            printf("\n%d/%d - %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowsNum);
        } else {
            printf("\n%d/%d - %d/%d = %d/%d\n", num1.numer, num1.den, num2.numer, num2.den, lowsNum, lowsDen);
        }
    }
}

fraction multiply(fraction num1, fraction num2){
    int mNum = num1.lowNumer * num2.lowNumer;
    int mDen = num1.lowDen * num2.lowDen;
    int mgcd = GCD(mNum, mDen);
    int lowmNum = mNum / mgcd;
    int lowmDen = mDen / mgcd;
    if (lowmDen == 1){
        printf("\n%d/%d * %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowmNum);
    }
    else if (lowmNum == 0){
        printf("\n%d/%d * %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowmNum);
    } else {
        printf("\n%d/%d * %d/%d = %d/%d\n", num1.numer, num1.den, num2.numer, num2.den, lowmNum, lowmDen);
    }
}

fraction divide(fraction num1, fraction num2){
    if (num2.lowNumer == 0){
        printf("\nMath Error\n");
    } else {
        int mNum = num1.lowNumer * num2.lowDen;
        int mDen = num1.lowDen * num2.lowNumer;
        int mgcd = GCD(mNum, mDen);
        int lowmNum = mNum / mgcd;
        int lowmDen = mDen / mgcd;
        if (lowmDen == 1){
            printf("\n%d/%d / %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowmNum);
        }
        else if (lowmNum == 0){
            printf("\n%d/%d / %d/%d = %d\n", num1.numer, num1.den, num2.numer, num2.den, lowmNum);
        } else {
            printf("\n%d/%d / %d/%d = %d/%d\n", num1.numer, num1.den, num2.numer, num2.den, lowmNum, lowmDen);
        }
    }
}
