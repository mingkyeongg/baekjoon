#include <iostream>
#include <vector>
#include <cctype>
#include <deque>

using namespace std;

deque<int>dq;
vector<string>ans;
int T; // 테스트 케이스의 수
int n; // 배열에 들어있는 수
int front, back;
bool flag = true;

void Print(string &cmd) {
	if (flag) {
		string ret;
		ret.append("[");
		while (!dq.empty()) {
			ret += to_string(dq.front());
			if (dq.size() != 1) {
				ret.append(",");
			}
			dq.pop_front();
		}
		ret.append("]\n");
		ans.push_back(ret);
	} else {
		string ret;
		ret.append("[");
		while (!dq.empty()) {
			ret += to_string(dq.back());
			if (dq.size() != 1) {
				ret.append(",");
			}
			dq.pop_back();
		}
		ret.append("]\n");
		ans.push_back(ret);
	}
}

void PushArr(string &arr) {
	int i = 0;
	string number;
	while (arr[i]) {
		if (arr[i] == ',' || arr[i] == ']') {
			if (number.size() == 0)
				break;
			dq.push_back(stoi(number));
			number.clear();
		}
		if (isdigit(arr[i])) {
			number += arr[i];
		}
		i++;
	}
}

void Processing(string &cmd) {
	flag = true;
	/* 
		R : 뒤집기
		D : 버리기
	*/

	int idx = 0;
	while (cmd[idx]) {
		if (cmd[idx] == 'R') {
			if (flag == true) {
				flag = false;
			} else { flag = true; }
		}
		else if (cmd[idx] == 'D') {
			if (dq.empty()) {
				ans.push_back("error\n");
				return;
			}
			if (flag == true) {
				dq.pop_front();
			} else {
				dq.pop_back();
			}
		}
		idx++;
	}
	Print(cmd);
}

int main(void) {
	cin >> T;
	for (int i = 0; i < T; i++) {
		string cmd, arr;
		cin >> cmd;
		cin >> n;
		cin >> arr;
		PushArr(arr);
		Processing(cmd);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}