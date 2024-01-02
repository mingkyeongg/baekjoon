#include <iostream>

using namespace std;

int N, K;

int dp[1001][1001];

void sol(void)
{
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j < i && j <= K; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
	}
	cout << dp[N][K];
}

int main(void)
{
	cin >> N >> K;
	sol();
}