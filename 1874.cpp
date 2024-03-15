#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

stack<int> s;
vector<int> v;
vector<string> result;
int n;

void print() {
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
}

void prepare() {
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
}

void solve() {
	int stack_cnt = 1;
	int i = 0;
	while (1) {
		if (i == n) {
			break;
		}
		int key = v[i];
		if (s.empty()) {
			s.push(stack_cnt++);
			result.push_back("+");
		}
		else if (key == s.top()) {
			s.pop();
			result.push_back("-");
			i++;
		}
		else if (key > s.top()) {
			s.push(stack_cnt++);
			result.push_back("+");
		}
		else {
			cout << "NO";
			return;
		}
	}
	print();
}

int main(void) {
	cin >> n;
	prepare();
	solve();
}