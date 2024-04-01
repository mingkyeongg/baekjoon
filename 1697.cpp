#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K; // 수빈이의 위치, 동생의 위치
bool visited[200001] = {false, };
queue<pair<int, int> >q; // 위치, 초

void bfs() {
	visited[N] = true;
	q.push(make_pair(N, 0));

	while(!q.empty()) {
		int pos = q.front().first;
		int sec = q.front().second;
		q.pop();
		if (pos == K) {
			cout << sec;
			break;
		}
		int plus = pos + 1 , minus = pos - 1, multi = pos * 2;
		if (plus <= 100000 && !visited[plus]) {
			q.push(make_pair(plus, sec + 1));
			visited[plus] = true;
		}
		if (minus <= 100000 && minus >= 0 && !visited[minus]) {
			q.push(make_pair(minus, sec + 1));
			visited[minus] = true;
		}
		if (multi <= 100000 && !visited[multi]) { 
			q.push(make_pair(pos * 2, sec + 1));
			visited[multi] = true;
		}
	}
}

int main(void) {
	cin >> N >> K;
	bfs();
}