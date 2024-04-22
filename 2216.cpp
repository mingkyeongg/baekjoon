#include <iostream>
#include <vector>
#include <string>

using namespace std;

int A, B, C; // 같은 경우, 공백, 다른 경우
string X, Y; // 비교할 문자열;

void Print(vector<int> &dp) {
	for (int i = 0; i < X.size() + 1; i++) {
		cout << dp[i] << " "; 
	}
	cout << endl;
}

void Dp(vector<int> &dp) {
	for (int i = 1; i < Y.size() + 1; i++) {
		vector<int>temp(X.size() + 1, 0);
		temp[0] = i * B;
		for (int j = 1; j < X.size() + 1; j++) {
			if (Y[i - 1] == X[j - 1]) {
				temp[j] = dp[j - 1] + A;
			} else {
				temp[j] = max(dp[j] + B, temp[j - 1] + B);
				temp[j] = max(temp[j], dp[j - 1] + C);
			}
		}
		dp = temp;
	}
}

void Initial(vector<int> &dp) {
	for (int i = 0; i < X.size() + 1; i++) {
		int val = i * B;
		dp[i] = val;
	}
}

int main(void) {
	cin >> A >> B >> C;
	cin >> X;
	cin >> Y;

	vector<int>dp(X.size() + 1, 0);
	Initial(dp);
	Dp(dp);
	cout << dp[X.size()];
}