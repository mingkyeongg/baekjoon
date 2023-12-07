#include <iostream>
#include <deque>
#include <string>

using namespace std;
deque<int> d;

int front(void)
{
	int x;
	if (d.empty())
	{
		cout << "-1\n";
		return 0;
	}
	else
	{
		x = d.front();
		cout << x << '\n';
		return 1;
	}
}

int back(void)
{
	int x;
	if (d.empty())
	{
		cout << "-1\n";
		return 0;
	}
	else
	{
		x = d.back();
		cout << x << '\n';
		return 1;
	}
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string com;
		int num;
		int x;
		cin >> com;
		if (com == "push_front")
		{
			cin >> num;
			d.push_front(num);
		}
		else if (com == "push_back")
		{
			cin >> num;
			d.push_back(num);
		}
		else if (com == "pop_front")
		{
			if (front())
				d.pop_front();
		}
		else if (com == "pop_back")
		{
			if (back())
				d.pop_back();
		}
		else if (com == "size")
		{
			x = d.size();
			cout << x << '\n';
		}
		else if (com == "empty")
		{
			x = d.empty();
			cout << x << '\n';
		}
		else if (com == "front")
			front();
		else if (com == "back")
			back();
	}
}