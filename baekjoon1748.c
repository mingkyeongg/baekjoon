#include <stdio.h>

int main(void)
{
    int N;
    int i;
    int line = 0;
    
    scanf("%d", &N);
    for (i = 1; i <= N; i *= 10)
        line +=  N - i + 1;
    printf("%d\n", line);
}

