#include <iostream>
#include <vector>
#include <string>

using namespace std;
string str1;
string str2;
int dp[1001][1001] = {0, };
string ans = ""; // 정답 문자열

void LCS() {
	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j -1]);
			}
		}
	}
}

void Backtracking() {
	int i = str1.length();
	int j = str2.length();
	int target = dp[i][j];
	while (i >= 0 && j >= 0) {
		if (dp[i][j] > dp[i - 1][j - 1] && dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1]) {
				ans = str1[i - 1] + ans;
				i -= 1;
				j -= 1;
		} else if (dp[i][j] > dp[i - 1][j]) {
			j -= 1;
		} else {
			i -= 1;
		}
	}
}

int main(void) {
	cin >> str1 >> str2;
	int str1_len = str1.length();
	int str2_len = str2.length();

	LCS();
	Backtracking();
	cout << dp[str1_len][str2_len] << '\n';
	cout << ans;
}