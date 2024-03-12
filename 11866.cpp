#include <iostream>
#include <vector>

using namespace std;

int N, K;


int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K;
	vector<int>v(N);

	for (int i = 0; i < N; i++)
		v[i] = i + 1;
	int index = 0, cnt = 0;

	cout << '<';
	while (cnt < N)
	{
		index = (index + K - 1) % v.size();
		cout << v[index];
		if (cnt != N - 1)
			cout << ", ";
		v.erase(v.begin() + index);
		cnt++;
	}
	cout << '>';
}

int partition(int *a, int low, int high)
{
	int left, right;
	int pivot_item;
	pivot_item = a[low];
	left = low;
	right = high;
	while (left < right) 
	{
		while (a[left] <= pivot_item) left++;
		while (a[right] >= pivot_item) right--;
		if (left < right) swap(a, left, right);
	}
	a[low] = a[right];
	a[right] = pivot_item;
	return right;
}