#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <functional>

using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq; // 값, 인덱스
int arr[10000001];
int N; // 배열 개수

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		pq.push(make_pair(x, i));
	}
	int level = 0;
	int past_num = pq.top().first;
	while (!pq.empty()) {
		int current_num = pq.top().first;
		if (past_num == current_num) {
			arr[pq.top().second] = level;
		} else {
			level += 1;
			arr[pq.top().second] = level;
		}
		past_num = current_num;
		pq.pop();
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}