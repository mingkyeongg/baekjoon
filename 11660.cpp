#include <iostream>
#include <vector>

using namespace std;

int N, M; // 표의 크기, 합을 구해야하는 횟수
void dp(vector<int>v[]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
				v[i][j] += v[i - 1][j];
				v[i][j] += v[i][j - 1];
				v[i][j] -= v[i - 1][j - 1];
		}
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	vector<int>v[N + 1];

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0) {
				v[i].push_back(0);
				continue;
			}
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	dp(v);
	for (int i = 0; i < M; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		cout << v[y1][y2] - v[y1][x2 - 1] - v[x1 - 1][y2] + v[x1 - 1][x2 - 1] << '\n';
	}
}