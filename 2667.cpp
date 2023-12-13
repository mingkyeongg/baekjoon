#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

vector<string>house;
bool visited[26][26] = {false, };
vector<int>ret;


bool is_valid(int x, int y, int n)
{
	if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y] == true || house[x][y] == '0')
		return false;
	return true;
}

void dfs(int x, int y, int *width, int n)
{
	visited[x][y] = true;
	(*width) += 1;

	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (is_valid(new_x, new_y, n))
		{
			dfs(new_x, new_y, width, n);
		}
	}
}

int main(void)
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int N;
	int width = 0;

	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string line;
		getline(cin, line);
		house.push_back(line);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (house[i][j] == '0' || visited[i][j] == true)
				continue;
			width = 0;
			dfs(i, j, &width, N);
			ret.push_back(width);
		}
	}
	cout << ret.size() << '\n';
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++)
		cout <<  ret[i] << '\n';
}