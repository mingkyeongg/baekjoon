#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define colorRed 1
#define colorBlue 2

bool visited[20001] = {false,};

bool BFS(int ver, int n, vector<vector<int> >&v, vector<int>&color)
{
	queue<int>q;
	q.push(ver);
	visited[ver] = 1;
	color[ver] = colorRed;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++)
		{
			int adc = v[x][i];
			if (!visited[adc])
			{
				q.push(adc);
				visited[adc] = true;
				color[adc] = color[x] % 2 + 1;
			}
			if (visited[adc])
			{
				if (color[adc] != (color[x] % 2 + 1) || !color[adc] || !color[x])
					return false;
			}
		}
	}
	return true;
}

int main(void)
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int V, E;
		cin >> V >> E;
		vector<vector<int> >v(V + 1);
		vector<int>color(V + 1, 0);
		for (int j = 0; j < E; j++)
		{
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);
		}
		bool ret = true;
		for (int j = 1; j <= V; j++)
		{
			if (visited[j])
				continue;
			if (!BFS(j, V, v, color))
			{
				ret = false;
				cout << "NO" << '\n';
				break;
			}
		}
		if (ret)
			cout << "YES" << '\n';
		fill(&visited[1], &visited[V + 1], 0);
	}
}