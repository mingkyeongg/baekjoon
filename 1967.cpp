#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
vector<pair<int, int> >*v;
priority_queue<int>pq;
int N; // 노드의 개수
int max_weight = -1;
int max_node = 0;
bool visited[10001] = {false, };

void Dfs(int start, int weight) {
	visited[start] = true;
	if (weight > max_weight) {
		max_weight = weight;
		max_node = start;
	}

	for (int i = 0; i < v[start].size(); i++) {
		int next_node = v[start][i].first;
		int next_weight = v[start][i].second;
		
		if(!visited[next_node]) {
			Dfs(next_node, weight + next_weight);
		}
	}
}

int main(void) {
	cin >> N;
	v = new vector<pair<int, int> >[N + 1];
	for (int i = 0; i < N - 1; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		v[from].push_back(make_pair(to, weight));
		v[to].push_back(make_pair(from, weight));
	}
	Dfs(1, 0);

	max_weight = 0;
	memset(visited, false, sizeof(visited));
	Dfs(max_node, 0);
	cout << max_weight;
}