#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream> 

using namespace std;

int main(void)
{
	vector<string> v;
	string s;
	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; i++)
	{
		string line;
        getline(cin, line); // 한 줄을 읽음
        istringstream iss(line); // istringstream 사용
        vector<string> v;
        string s;
	
		while (iss >> s)
		{
			v.push_back(s);
		}
		for (int j = 0; j < v.size(); j++)
		{
			reverse(v[j].begin(), v[j].end());
			cout << v[j] << ' ';
		}
		cout << '\n';
		v.clear();
	}
}