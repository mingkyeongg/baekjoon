#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int T; // 테스트 케이스 개수
priority_queue<int>max_pq; // 최대 우선순위 큐
priority_queue<int, vector<int>, greater<int> >min_pq; // 최소 우선순위 큐
map<int, int>m; // 숫자 기록

void insert(int data) {
	max_pq.push(data);
	min_pq.push(data);
	m[data]++;
}

void out(int command) {
	int key;
	if (command == -1) {
		if (!min_pq.empty()) {
			key = min_pq.top();
			min_pq.pop();
			m[key]--;
		}
	} else {
		if (!max_pq.empty()) {
			key = max_pq.top();
			max_pq.pop();
			m[key]--;
		}
	}
}

void arrange() {
	while (!max_pq.empty() && m[max_pq.top()] == 0) max_pq.pop();
	while (!min_pq.empty() && m[min_pq.top()] == 0) min_pq.pop();
}

void print() {
	if (max_pq.empty() || min_pq.empty()) {
		cout << "EMPTY" <<endl;
	} else {
		cout << max_pq.top() << " " << min_pq.top() << endl;
	}
	m.clear();
	while (!min_pq.empty()) min_pq.pop();
	while (!max_pq.empty()) max_pq.pop();
}

int main(void) {
	cin >> T;
	
	while (T--) {
		int cnt;
		cin >> cnt;
		for (int i = 0; i < cnt; i++) {
			string cmd;
			int x;
			cin >> cmd >> x;
			if (cmd == "I") {
				insert(x);
			} else {
				out(x);
				arrange();
			}
		}
		print();
	}
}