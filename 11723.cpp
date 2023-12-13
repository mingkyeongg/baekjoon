#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define BYTE_SIZE 8
unsigned char S[20 / BYTE_SIZE + 1] = {0, };

bool check(int n)
{
	return (S[n / BYTE_SIZE] & (1 << (n % BYTE_SIZE)));
}

void add(int i)
{
	if (check(i))
		return ;
	S[i / BYTE_SIZE] |= (1 << (i % BYTE_SIZE));
}

void remove(int i)
{
	if (!check(i))
		return ;
	S[i / BYTE_SIZE] &= ~(1 << (i % BYTE_SIZE));
}

int main(void)
{
	int M;

	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
	cin >> M;
	cin.ignore();
	for (int i = 0; i < M; i++)
	{
		string str;

		cin >> str;
		if (str == "add")
		{
			cin >> str;
			add(stoi(str));
		}
		else if (str == "remove")
		{
			cin >> str;
			remove(stoi(str));
		}
		else if (str == "check")
		{
			cin >> str;
			if (check(stoi(str)))
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "toggle")
		{
			cin >> str;
			if (check(stoi(str)))
				remove(stoi(str));
			else
				add(stoi(str));
		}
		else if (str == "all")
			fill(begin(S), end(S), 0xFF);
		else if (str == "empty")
			fill(begin(S), end(S), 0);
	}
}