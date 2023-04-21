#include <iostream>
#include <algorithm>

using namespace std;

int arr[8] = {0};
int arr2[8];

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
    for (int i = 0; i < N; i++)
    {
        arr[num] = arr2[i];
        pick_num(N, M, num + 1);
    }
}


int main(void)
{
    int M, N;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> arr2[i];
    }
    sort(arr2, arr2 + N);
    pick_num(N, M, 0);
    
}
