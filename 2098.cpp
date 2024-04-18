/* 외판원 순회 */
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N; // 도시의 수
vector<vector<int> >v; // 비용 행렬, 갈 수 없는 경우에는 0
int min_cost = 100000000;
int cost;
int dp[16][1<<16];

#define INF 100000000

void print() {
	cout << "------------------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 1 << N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------\n";
}

int Dfs(int now, int visited) {
	if (visited == (1 << N) - 1) {
		if (v[now][0] != 0) {
			return v[now][0];
		} else { return INF; }
	}
	if (dp[now][visited] != -1) {
		return dp[now][visited];
	}

	dp[now][visited] = INF;

	for (int next = 0; next < N; next++) {
		if (v[now][next] != 0 && !(visited & (1 << next))) {
			int cost = Dfs(next, visited | (1 << next)) + v[now][next];
            dp[now][visited] = min(dp[now][visited], cost);
		}
	}
	return dp[now][visited];
}

int main(void) {
	cin >> N;
	vector<vector<int> >temp(N + 1, vector<int>(N + 1, 0));
	v = temp;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cost;
			cin >> cost;
			v[i][j] = cost;
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << Dfs(0, 1);
}