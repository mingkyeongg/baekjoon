#include <iostream>

using namespace std;

int path[101][101] = {0, };
int n; // 도시의 개수
int m; // 버스의 개수
#define INF 10000001

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		if (path[start][end] > 0 && path[start][end] < cost)
			continue;
		path[start][end] = cost;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && path[i][j] == 0)
				path[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				path[j][k] = min(path[j][k], path[j][i] + path[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (path[i][j] >= INF)
				cout << 0 << " ";
			else
				cout << path[i][j] << " ";
		}
		cout << '\n';
	}
}