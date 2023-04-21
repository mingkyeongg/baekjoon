#include <iostream>

using namespace std;

int arr[10][10] = {0};
int arr2[10] = {0};

int check_num (int num)
{
    for (int i = 0; i < num; i++)
    {
        arr2[i]
    }
}

void pick_num(int N, int M, int num, int *max)
{
    int sum = 0;
    if (M == num)
    {
        if (*max < sum)
        {
            *max = sum;
            return;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            arr2[j] = i
            if (check_num(num))
            {
                sum += arr[i][j];
                pick_num(N, M, num + 1, max);
            }
        }
    }
}
                
                
                int main(void)
                {
                int N, M, K;
                cin >> N >> M >> K;
                
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        cin >> arr[i][j];
                    }
                }
                
            }
                
