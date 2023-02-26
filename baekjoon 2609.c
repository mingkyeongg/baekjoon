#include <stdio.h>

int GCD (int a, int b) {
    int temp;
    if (a % b != 0) {
        temp = a % b;
        a = b;
        b = temp;
        return GCD(a, b);
    } else if (a % b == 0) {return b;}
    
    return 0;
}

int main () {
    int A, B;
    int gcd, lcd;
    scanf("%d %d", &A, &B);
    
    gcd = GCD(A, B);
    lcd = (A * B) / gcd;
    
    printf("%d\n%d", gcd, lcd);
    return 0;
    
}
