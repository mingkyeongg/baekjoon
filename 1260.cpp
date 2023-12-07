#include <iostream>
#include <queue>

using namespace std;
int arr [1001][1001] = {0, };
int visited[1001] = {0, };


void BFS(int v, int n)
{
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 1; i <= n; i++)
		{
			if (arr[x][i] == 1 && visited[i] == 0)
			{
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

void DFS(int v, int n)
{
	cout << v << " ";
	visited[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[v][i] == 1 && visited[i] == 0)
			DFS(i, n);
	}
}

int main(void)
{
	int N, M, V;
	int i, j;

	cin >> N >> M >> V;
	for (int m = 0; m < M; m++)
	{
		cin >> i >> j;
		arr[i][j] = 1;
		arr[j][i] = 1;
	}
	DFS(V, N);
	fill(&visited[1], &visited[N + 1], 0);
	cout << "\n";
	BFS(V, N);
}