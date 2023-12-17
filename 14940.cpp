#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int> >q;
bool visited[1001][1001] = {false, };
int path[1001][1001] = {0,};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;

void print(int n, int m, vector<vector<int> >map)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << path[i][j] << ' ';
		cout << '\n';
	}
}

bool isValid(int x, int y, vector<vector<int> >*map)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if (visited[x][y] == true || (*map)[x][y] == 0)
		return false;
	return true;
}

void bfs(int start_x, int start_y, vector<vector<int> >*map)
{
	q.push(make_pair(start_x, start_y));
	visited[start_x][start_y] = true;
	path[start_x][start_y] = 0;

	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			if (isValid(new_x, new_y, map))
			{
				q.push(make_pair(new_x, new_y));
				visited[new_x][new_y] = true;
				path[new_x][new_y] = path[x][y] + 1;

			}
		}
	}
}

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int start_x, start_y;

	cin >> n >> m;

	vector<vector<int> >map(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			if (x == 2)
			{
				start_x = i;
				start_y = j;
			}
			map[i].push_back(x);
			if (x != 0)
				path[i][j] = -1;
		}
	}
	bfs(start_x, start_y, &map);
	print(n, m, map);
}