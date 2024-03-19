/* 백준 4949 균형잡힌 세상
	자료구조, 문자열, 스택 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char>s;

bool IsLeftBraket(string str, int idx) {
	if (str[idx] == '(' || str[idx] == '[')
		return true;
	return false;
}

bool IsRightBraket(string str, int idx) {
	if (str[idx] == ')' || str[idx] == ']')
		return true;
	return false;
}

bool Matching(string str, int idx) {
	if (s.empty())
		return false;
	if (str[idx] == ')') {
		if (s.top() == '(') {
			s.pop();
			return true;
		}
		else
			return false;
	} else if (str[idx] == ']') {
		if (s.top() == '[') {
			s.pop();
			return true;
		} else {return false;}
	}
	return false;
}

bool IsBalancedSentence(string str) {
	int idx = 0;
	while (str[idx]) {
		if (IsLeftBraket(str, idx)) {
			s.push(str[idx]);
		} else if (IsRightBraket(str, idx)) {
			if (!Matching(str, idx)) {
				while (!s.empty())
					s.pop();
				return false;
			}
		}
		idx++;
	}
	if (str[str.size() - 1] == '.' && s.empty()) {
		return true;
	} else {return false;}
}

int main(void) {
	string str;
	while (1) {
		getline(cin, str);
		if (str == ".")
			break;
		if (IsBalancedSentence(str)) {
			cout << "yes" << endl;
		} else {cout << "no" << endl;}
		while (!s.empty())
			s.pop();
	}
}