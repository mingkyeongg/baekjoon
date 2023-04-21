#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int sum_vec(int N)
{
    int sum = 0;
    for (int i = 0; i < N -1; i++)
    {
        sum += abs(v[i] - v[i + 1]);
    }
    return sum;
}

int main(void)
{
    int N;
    int temp;
    int max = 0;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    max = sum_vec(N);
    while (next_permutation(v.begin(), v.end()))
    {
        if (max < sum_vec(N))
            max = sum_vec(N);
    }
    cout << max;
}
