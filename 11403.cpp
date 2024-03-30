#include <iostream>
#include <vector>

using namespace std;

int N; // 정점의 개수
#define INF 1000000

int main(void) {
	cin >> N;
	vector<int>v[N];
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			if (x == 0) {
				v[i].push_back(INF);
			} else {v[i].push_back(x);}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] >= INF) {
				cout << "0 ";
			} else {
				cout << "1 ";
			}
		}
		cout << '\n';
	}
}