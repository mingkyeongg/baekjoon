#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string, string> >v[256];

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str1, str2;
		cin >> str1;
		cin >> str2;
		int a = str1[0];
		v[a].push_back(make_pair(str1, str2));
	}

	for (int i = 0; i < M; i++)
	{
		string addr;
		cin >> addr;
		int b = addr[0];

		for (int j = 0; j < v[b].size(); j++)
		{
			if (v[b][j].first == addr)
				cout << v[b][j].second << '\n';
		}
	}
}