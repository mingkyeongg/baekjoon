#include <stdio.h>
#include <math.h>

int arr[1000001] = {0};

int main () {
    int i,j, num;
    
    for(i = 2; i <= sqrt(1000001); i++) {
        if(arr[i] == 0) {
            for(j = 2; i * j < 1000001; j++) {
                arr[i * j] = 1;
            }
        }
    }
        
        while(1) {
            scanf("%d", &num);
            if(num == 0) {
                break;
            }
            for (i = 2; i < num /2; i++) {
                for (j = num - 2; j > num /2; j-- ) {
                    if (arr[i] != 0 && arr[j] != 0) {
                        if (i + j == num) {
                            printf("%d + %d = %d", i , j, num);
                        } else {
                            printf("Goldbach's conjecture is wrong.");
                        }
                    }
                }
            }
        }
    return 0;
}
