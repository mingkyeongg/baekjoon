#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int target;
int start;
int T; // 테스트케이스
queue<pair<int, string> >q;

int OperDouble(int num) {
	return (2 * num) % 10000;
}
int OperSub(int num) {
	num -= 1;
	if (num < 0) {
		return 9999;
	} else {return num;}
}

int OperLeft(int num) {
	int units = num % 10;
	int tens = (num % 100) / 10;
	int hundreds = (num % 1000) / 100;
	int thousands = num / 1000;

	return hundreds * 1000 + tens * 100 + units * 10 + thousands;
}

int OperRight(int num) {
	int units = num % 10;
	int tens = (num % 100) / 10;
	int hundreds = (num % 1000) / 100;
	int thousands = num / 1000;
	
	return units * 1000 + thousands * 100 + hundreds * 10 + tens;
}

void bfs(bool visited[]) {
	visited[start] = true;
	q.push(make_pair(start, ""));
	
	while (!q.empty()) {
		int num = q.front().first;
		string cmd = q.front().second;
		if (num == target) {
			cout << cmd << '\n';
			return;
		}
		q.pop();
		int D, S, L, R;
		D = OperDouble(num);
		if (visited[D] == false) {
			visited[D] = true;
			q.push(make_pair(D, cmd + 'D'));
		}
		S = OperSub(num);
		if (visited[S] == false) {
			visited[S] = true;
			q.push(make_pair(S, cmd + 'S'));
		}
		L = OperLeft(num);
		if (visited[L] == false) {
			visited[L] = true;
			q.push(make_pair(L, cmd + 'L'));
		}
		R = OperRight(num);
		if (visited[R] == false) {
			visited[R] = true;
			q.push(make_pair(R, cmd + 'R'));
		}
	}
}

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> start >> target;
		bool visited[10001] = {false, };
		bfs(visited);
		while (!q.empty()) q.pop();
	}
}