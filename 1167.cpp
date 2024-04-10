/* 트리의 정점 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<pair<int, int> >*tree;
int V; // 트리의 정점 개수
bool visited[100001] = {false, };
int max_weight = -1;
int max_vertex;

void print() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			cout << "vertex : " << i << " to : " << tree[i][j].first << " weight : " << tree[i][j].second <<endl;
		}
	}
}

void Input() {
	cin >> V;
	tree = new vector<pair<int, int> >[V + 1];
	int from, to, weight;
	for (int i = 0; i < V; i++) {
		cin >> from;
		while (1) {
			cin >> to;
			if (to == -1) {
				break;
			}
			cin >> weight;
			tree[from].push_back(make_pair(to, weight));
		}
	}
}

void dfs(int vertex, int weight) {
	visited[vertex] = true;
	if (weight > max_weight) {
		max_weight = weight;
		max_vertex = vertex;
	}

	for (int i = 0; i < tree[vertex].size(); i++) {
		int next_vertex = tree[vertex][i].first;
		int next_weight = tree[vertex][i].second + weight;

		if (!visited[next_vertex]) {
			dfs(next_vertex, next_weight);
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	Input();
	dfs(1, 0);
	fill(&visited[0], &visited[V + 1], false);
	dfs(max_vertex, 0);
	cout << max_weight;
}

// 4
// 1 2 5 3 9 -1
// 2 1 5 -1
// 3 1 9 4 8 -1
// 4 3 8 -1

// 6
// 1 2 3 -1
// 2 1 3 5 3 3 5 -1
// 3 2 5 4 7 -1
// 4 3 7 -1
// 5 2 3 6 5 -1
// 6 5 5 -1