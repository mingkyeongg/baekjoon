#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int node[101];
vector<pair<float, pair <int, int> > >v;
vector<pair<float, float> >s;

int find_set(int x)
{
	if(node[x] == x)
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

int main()
{
	int star;
	float distance, length = 0;

	cin >> star;
	for (int i = 0; i < star; i++)
	{
		float x, y, distance;
		cin >> x >> y;
		s.push_back(make_pair(x, y));
	}
	for (int i = 0; i < s.size(); i++)
		node[i] = i;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			distance = sqrt(pow(s[i].first - s[j].first, 2) + pow(s[i].second - s[j].second, 2));
			v.push_back(make_pair(distance, make_pair(i , j)));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		if (find_set(v[i].second.first) != find_set(v[i].second.second))
		{
			union_node(v[i].second.first, v[i].second.second);
			length += v[i].first;
		}
	}
	printf("%0.2f", length);
	return 0;
}