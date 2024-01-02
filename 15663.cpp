#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
int ans[10] = {0, };
bool visited[10] = {false, };
int N, M;

void print(void)
{
	for (int i = 0; i < M; i++)
		cout << ans[i] << " ";
	cout << '\n';
}

void select(int m, int M)
{
	if (m == M)
	{
		print();
		return;
	}

	int check = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (!visited[i] && check != v[i])
		{
			ans[m] = v[i];
			check = v[i];
			visited[i] = true;
			select(m + 1, M);
			visited[i] = false;
		}
	}
}

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	select(0, M);
}