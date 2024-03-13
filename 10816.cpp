#include <iostream>
#include <map>

using namespace std;

map<int, int>m;
int M, N;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		m[x]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		cout << m[x] << ' ';
	}
}