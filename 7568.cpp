#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> >v; // 몸무게, 키
vector<int>cnt; // 자신보다 덩치가 큰 사람 카운트
int N; // 사람 수

void print() {
	for (int i = 0; i < N; i++) {
		cout << cnt[i] << " ";
	}
}

void BiggerOne(int a, int b) {
	if (v[a].first > v[b].first && v[a].second > v[b].second) {
		cnt[b]++;
	}
}

void FindBig() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			BiggerOne(i, j);
		}
	}
}

int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
		cnt.push_back(1);
	}
	FindBig();
	print();
}