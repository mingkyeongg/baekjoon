#include <iostream>
#include <vector>

using namespace std;

vector<int> relation[2001];
int visited[2001] = {0, };

void dfs(int depth, int start, int *flag, int n)
{
	if (depth >= 5) {
		*flag = 1;
		return;
	}

	visited[start] = 1;
	for (int i : relation[start])
	{
		if (!visited[i])
		{
			dfs(depth + 1, i, flag, n);
			if (*flag) return;
		}
	}
	visited[start] = 0;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	int i, j;
	for (int m = 0; m < M; m++)
	{
		cin >> i >> j;
		relation[i].push_back(j);
		relation[j].push_back(i);
	}

	int flag = 0;
	for (int i = 0; i < N && !flag; i++)
		dfs(1, i, &flag, N);
	cout << flag << '\n';

	return 0;
}
