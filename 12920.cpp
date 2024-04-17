#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > element;
int N; // 집에 있는 물건의 종류의 수
int M; // 민호가 들 수 있는 최대 무게

void print(vector<vector<int> >dp) {
	for (int i = 0; i < element.size(); i++) {
		cout << "weight : " << element[i].first << " value : " << element[i].second << endl; 
	}

	cout << "-----------------------------------\n";
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j < element.size(); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

void Solve(vector<vector<int> >&dp) {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j < element.size(); j++) {
			int weight = element[j].first;
			int value = element[j].second;
			if (weight > i) {
				dp[i][j] = dp[i][j - 1];
			} else {
				dp[i][j] = max(dp[i][j - 1], value + dp[i - weight][j - 1]);
			}
		}
	}
}


int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	int cnt = 0; // 물건의 총 개수
	element.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		int V, C, K; // 물건의 무게, 만족도, 물건의 개수
		cin >> V >> C >> K;
		for (int j = K; j > 0; j >>=1) {
			int part = j - (j >>1);
			element.push_back(make_pair(V * part, C * part));
		}
	}
	cnt = element.size();
	vector<vector<int> >dp((M + 1), vector<int>(cnt, 0));
	Solve(dp);
	cout << dp[M][cnt - 1];
}