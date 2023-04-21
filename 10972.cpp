#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(void)
{
    int N;
    int temp;
    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    if(!next_permutation(v.begin(), v.end()))
        cout << -1;
    else
    {
        for (int i = 0; i < N; i++)
            cout << v[i] << " ";
    }
}
