#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N; // M : 가로 칸의 수 N : 세로 칸의 수 v[N][M]
bool visited[1001][1001] = {false, };
queue<pair<pair<int, int>, int>  >q; // x값, y값, level
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int final_level = 0;

bool findZero(vector<int>v[]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (v[i][j] == 0)
				return false;
		}
	}
	return true;
}

bool isVaild(vector<int>v[], int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M)
		return false;
	else if (v[x][y] == -1 || visited[x][y])
		return false;
	return true;
}

void bfs(vector<int>v[]) {
	while (!q.empty()) {
		int front_x = q.front().first.first;
		int front_y = q.front().first.second;
		int current_level = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = front_x + dx[i];
			int next_y = front_y + dy[i];
			if (isVaild(v, next_x, next_y)) {
				q.push(make_pair(make_pair(next_x, next_y), current_level + 1));
				final_level = current_level;
				v[next_x][next_y] = 1;
				visited[next_x][next_y] = true;
			}
		}
	} 
}

int main() {
	cin >> M >> N;
	vector<int>v[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				q.push(make_pair(make_pair(i, j), 1));
				visited[i][j] = true;
			}
			v[i].push_back(x);
		}
	}
	bfs(v);
	if (!findZero(v))
		cout << "-1";
	else
		cout << final_level;
}