#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int node[1001];

int find_set(int x)
{
	if (node[x] == x)
		return x;
	else
		node[x] = find_set(node[x]);
	return node[x];
}

void union_node(int u, int v)
{
	int x = find_set(u);
	int y = find_set(v);

	node[x] = y;
}

int main(void)
{
	int T, nation, plane, from, to;
	vector<pair<int, int> >v;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> nation >> plane;
		int count = 0;
		for (int i = 0; i < plane; i++) {
			cin >> from >> to;
			v.push_back(make_pair(from, to));
		}
		for (int i = 1; i <= nation; i++)
			node[i] = i;
		for (int i = 0; i < v.size(); i++) {
			if (find_set(v[i].first) != find_set(v[i].second)) {
				union_node(v[i].first, v[i].second);
				count++;
			}
		}
		cout << count << '\n';
		v.clear();
	}
}