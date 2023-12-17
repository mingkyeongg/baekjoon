#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int>v;
vector<string>s;

void print(void)
{
	for(int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << '\n';
	cout << "----------------------\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << '\n';
}

int relation(string mbti1, string mbti2, string mbti3)
{
	int relation = 0;
	for (int i = 0; i < 4; i++)
	{
		if (mbti1[i] != mbti2[i])
			relation++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (mbti2[i] != mbti3[i])
			relation++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (mbti1[i] != mbti3[i])
			relation++;
	}
	return relation;
}

int bf(void)
{
	for (int i = 0; i < s.size() - 2; i++)
	{
		for (int j = i + 1; j < s.size() - 1; j++)
		{
			for (int k = j + 1; k < s.size(); k++)
			{
				v.push_back(relation(s[i], s[j], s[k]));
			}
		}
	}
	sort(v.begin(), v.end());
	return (v[0]);
}

int main(void)
{
	int t, n;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			string mbti;
			cin >> mbti;
			s.push_back(mbti);
		}
		if (s.size() > 32)
		{
			cout << "0\n";
			s.clear();
			continue;
		}
		cout << bf() << '\n';
		v.clear();
		s.clear();
	}
}