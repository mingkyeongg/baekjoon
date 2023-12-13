#include <iostream>
#include <vector>

using namespace std;

int node[1001] = {0, };

int find_set(int x)
{
	if (node[x] == x)
		return x;
	else
	{
		node[x] = find_set(node[x]);
	}
	return node[x];
}

void union_node (int u, int v)
{
	int x = find_set(u);
	int y = find_set(v);

	node[y] = x;
}

int main(void)
{
	vector<pair<int, int> >v;
	int N, M, ret = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		node[i] = i;
	for (int i = 0; i < M; i++)
	{
		int u, ve;
		cin >> u >> ve;
		v.push_back(make_pair(u, ve));
	}
	for (int i = 0; i < v.size(); i++)
		union_node(v[i].first, v[i].second);
	for (int i = 1; i <= N; i++)
	{
		if (node[i] == i)
			ret++;
	}
	cout << ret;
}