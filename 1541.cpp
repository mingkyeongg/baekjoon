#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>v;

void print(void)
{
	cout << "--------------------\n";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] <<" ";
	cout << '\n';
	cout << "--------------------\n";
}

int main(void)
{
	string str;
	cin >> str;
	int oper = 0, ret = 0;
	int sign = 1;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			string sub = str.substr(oper, i);
			oper = i + 1;
			v.push_back(sign * stoi(sub));
			if (str[i] == '-')
				sign = -1;
		}
	}
	string sub = str.substr(oper, str.size());
	v.push_back(sign * stoi(sub));
	for (int i = 0; i < v.size(); i++)
		ret += v[i];
	cout << ret;
}