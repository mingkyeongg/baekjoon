#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M; // 포켓몬의 개수, 내가 찾아야 하는 문제의 개수
map<string, int>strmap;
map<int, string>intmap;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		strmap[str] = i;
		intmap[i] = str;
	}

	for (int i = 0; i < M; i++) {
		string q;
		cin >> q;
		if (isdigit(q[0])) {
			int idx = stoi(q);
			cout << intmap[idx] << '\n';
		} else {
			cout << strmap[q] << '\n';
		}
	}
}