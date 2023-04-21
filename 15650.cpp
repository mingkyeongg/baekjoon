#include <iostream>

using namespace std;

int arr[8] = {0};

int check_num (int N, int num)
{
    for (int i = 0; i < num; i++)
    {
        if (arr[i] >= N)
            return 0;
    }
    return 1;
}

void pick_num(int N, int M, int num)
{
    if (M == num)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if(check_num(i, num))
        {
            arr[num] = i;
            pick_num(N, M, num + 1);
        }
    }
}


int main(void)
{
    int M, N;
    
    cin >> N >> M;
    pick_num(N, M, 0);
    
}
