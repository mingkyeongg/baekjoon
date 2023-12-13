#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string>v;
bool visited[101][101] = {false, };
bool visited_colorant[101][101] = {false, };

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int colorsize;
int ret = 0;
int colorant_ret = 0;

void print(void)
{
	cout << "----------------------\n";
	for (int i = 0; i < colorsize; i++)
		cout << v[i] << '\n';
	cout << "----------------------\n";
}

bool isValid(int x, int y)
{
	if (x >= colorsize || x < 0 || y >= colorsize || y < 0)
		return false;
	return true;
}

bool colorantCheck(int x, int y, int new_x, int new_y)
{
	if (v[x][y] == v[new_x][new_y])
		return true;
	if (v[x][y] == 'R')
	{
		if (v[new_x][new_y] == 'G')
			return true;
		else
			return false;
	}
	else if (v[x][y] == 'G')
	{
		if (v[new_x][new_y] == 'R')
			return true;
		else
			return false;
	}
	return false;
}

void dfs_colorant(int x, int y)
{
	visited_colorant[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (isValid(new_x, new_y) && !visited_colorant[new_x][new_y] && colorantCheck(x, y, new_x, new_y))
			dfs_colorant(new_x, new_y);
	}
}

void dfs(int x, int y)
{
	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (isValid(new_x, new_y) && !visited[new_x][new_y] && v[x][y] == v[new_x][new_y])
			dfs(new_x, new_y);
	}
}

int main(void)
{

	cin >> colorsize;

	for (int i = 0; i < colorsize; i++)
	{
		string str;
		cin >> str;

		v.push_back(str);
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (!visited[i][j])
			{
				dfs(i, j);
				ret++;
			}
			if (!visited_colorant[i][j])
			{
				dfs_colorant(i, j);
				colorant_ret++;
			}
		}
	}
	cout << ret << '\n' << colorant_ret << '\n';
}