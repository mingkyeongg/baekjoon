#include <iostream>
#include <map>

using namespace std;

map<string, bool, greater<string> >m;
int n;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string name, com;
		cin >> name >> com;
		if (com == "enter") {
			m[name] = true;
		} else {
			m.erase(name);
		}
	}
	map<string, bool> ::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << '\n';
	}
}