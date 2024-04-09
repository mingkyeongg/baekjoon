/* LCS */

#include <iostream>
#include <string>

using namespace std;

string str1; // 두 개의 입력 문자열
string str2;
int dp[1001][1001] = {0, };

void print() {
	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
}

int main(void) {
	cin >> str1 >> str2;
	int x_length = str1.length();
	int y_length = str2.length();

	for (int i = 1; i <= x_length; i++) {
		for (int j = 1; j <= y_length; j++) {
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[x_length][y_length];
}