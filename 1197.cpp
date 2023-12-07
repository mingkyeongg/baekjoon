#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VALUE 1000001
/*
	가중치 오름차순 만들기 어떻게..? 배열로 가능할까
	작은거부터 하나씩 union
	만들어야 할 거 find set
*/

vector<pair<int, pair<int,int> > >v;
int node[10001] = {0, };

int find(int x)
{
	if (node[x] == x)
		return x;
	else
		node[x] = find(node[x]);
	return node[x];
}

void union_root(int u, int v)
{
	int x = find(u);
	int y = find(v);

	node[x] = y;
}

int main(void)
{
	int V, E, A, B, C;
	int length = 0;

	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		v.push_back(make_pair(C, make_pair(A, B)));
		
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= V; i++)
		node[i] = i;
	for (int i = 0; i < v.size(); i++) {
		if (find(v[i].second.first) != find(v[i].second.second))
		{
			union_root(v[i].second.first, v[i].second.second);
			length += v[i].first;
		}
	}
	cout << length;
}
