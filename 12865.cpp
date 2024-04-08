/* 평범한 배낭 */

#include <iostream>
#include <vector>

using namespace std;

int N, K; // 물품의 수, 버틸 수 있는 무게
vector<pair<int, int> >bag; // 무게, 가치
int dp[100001][101];

void print() {
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K;
	bag.push_back(make_pair(0, 0));
	for (int i = 1; i <= N; i++) {
		int weight, value;
		cin >> weight >> value;
		bag.push_back(make_pair(weight, value));
		dp[0][i] = 0;
	}

	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == 0) {
				dp[i][j] = 0;
				continue;
			}
			int weight = bag[j].first;
			int value = bag[j].second;
			if (weight <= i)
				dp[i][j] = max(dp[i - weight][j - 1] + value, dp[i][j - 1]);
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	cout << dp[K][N];
}