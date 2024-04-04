#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
vector<string>v;
int N, M; // N개의 열 M개의 행
queue<pair<pair<int, int> , int> >q; // x좌표, y좌표, levels
bool visited[101][101] = {false};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int min_level = 10000001;

bool IsVaild(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return false;
	else if (v[x][y] == '0' || visited[x][y])
		return false;
	return true;
}

void bfs() {
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0] = true;

	while (!q.empty()) {
		int current_x = q.front().first.first;
		int current_y = q.front().first.second;
		int current_level = q.front().second;
		q.pop();

		if (current_x == N - 1 && current_y == M - 1) {
			if (min_level > current_level)
				min_level = current_level;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];
			int next_level = current_level + 1;
			if (IsVaild(next_x, next_y)) {
				visited[next_x][next_y] = true;
				q.push(make_pair(make_pair(next_x, next_y), next_level));
			}
		}
	}
}

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	bfs();
	cout << min_level;
}