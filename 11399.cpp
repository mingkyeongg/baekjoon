#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;

int main(void)
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
	int N, ret = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	ret = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		v[i] += v[i - 1];
		ret += v[i];
	}
	cout << ret;
}