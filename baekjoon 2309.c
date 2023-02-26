#include <stdio.h>
#include <stdlib.h>

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main() {
    int arr[9];
    int sum = 0;
    int i , j , k;
    
    for (i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (i != j) {
                sum = 0;
                for (k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        sum += arr[k];
                    }
                }
                if (sum == 100) {
                    arr[i] = 100;
                    arr[j] = 100;
                    break;
                } else {continue;}
            }
        }
    }
    qsort(arr, 9, sizeof(int), compare);
    
    for (i = 0; i < 7; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
