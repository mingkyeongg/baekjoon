#include <iostream>
#include <queue>

using namespace std;

queue<int>q;
int N;

void preprocess()
{
	for (int i = 1; i <= N; i++)
		q.push(i);
}

int main(void)
{
	int cnt = 1;
	cin >> N;
	preprocess();
	while (q.size() > 1)
	{
		if (cnt % 2 == 1)
			q.pop();
		else {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		cnt++;
	}
	cout << q.front();
}