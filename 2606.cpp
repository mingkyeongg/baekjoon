#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int com[101] = {0, };

int find_set(int x)
{
	if (com[x] == x)
		return x;
	else
		com[x] = find_set(com[x]);
	return com[x];
}

void union_com(int u, int v) {
    int x = find_set(u);
    int y = find_set(v);
    if (x != y)
        com[x] = y;
}

int main(void)
{
	int num, m, vi, ret = 0;
	vector<pair<int, int> >v;

	cin >> num >> m;
	for (int i = 0; i < m; i++)
	{
		int u, ve;
		cin >> u >> ve;
		v.push_back(make_pair(u, ve));
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= num; i++)
		com[i] = i;
	for (int i = 0; i < v.size(); i++)
		union_com(v[i].first, v[i].second);
	vi = find_set(1);
	for (int i = 1; i <= num; i++)
	{
		if (vi == find_set(com[i]))
			ret++;
	}
	cout << ret - 1;
}