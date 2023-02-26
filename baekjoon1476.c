#include <stdio.h>

int main(void)
{
    int E, S, M;
    int count = 1;
    int i = 1;
    int j = 1;
    int k = 1;
    scanf("%d %d %d", &E, &S, &M);
    
    while (1)
    {
        if (i > 15)
        {
            i = 1;
        }
        if (j > 28)
        {
            j = 1;
        }
        if (k > 19)
        {
            k = 1;
        }
        if (i == E && j == S && k == M)
        {
            break;
        }
        else
        {
            i++;
            j++;
            k++;
            count++;
        }
    }
    printf("%d\n", count);
    
}

