#include <iostream>
#include <vector>

// DP

using namespace std;

vector<int>stairs; // 계단
int N; // 계단의 개수
int dp[301] = {0, };

int solve() {
	dp[0] = stairs[0];
	dp[1] = max(stairs[0] + stairs[1], stairs[1]); // 2칸
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]); // 3칸

	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], stairs[i - 1] + stairs[i] + dp[i - 3]);
	}
	return dp[N - 1];
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		stairs.push_back(x);
	}
	cout << solve();
}