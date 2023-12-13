#include <iostream>
#include <vector>

using namespace std;

vector<int>v;

int biggestChild(int i)
{
	int leftChildIndex = 2 * i;
    int rightChildIndex = 2 * i + 1;
    int heapSize = v.size() - 1;

	if (leftChildIndex > heapSize)
        return -1;

    if (rightChildIndex > heapSize)
        return leftChildIndex;

    if (v[leftChildIndex] > v[rightChildIndex])
        return leftChildIndex;
    return rightChildIndex;
}

int parent(int n)
{
	return (n / 2);
}

void swap(int i, int j)
{
	int temp;
	temp  = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void insert(int x)
{
	v.push_back(x);
	int i = v.size() - 1;
	while (i > 1 && v[parent(i)] < v[i])
	{
		swap(parent(i), i);
		i = parent(i);
	}
}

void maxHeapify(int i)
{
	int k = biggestChild(i);
	if (k == -1)
		return;
	if (v[i] > v[k])
		return;
	swap(i, k);
	maxHeapify(k);
}

void extractMax(void)
{
	if (v.size() == 1)
	{
		cout << "0\n";
		return ;
	}
	cout << v[1] << '\n';
	swap(1, v.size() - 1);
	v.pop_back();
	maxHeapify(1);
}

void print(void)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << '\n';
}

int main(void)
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	v.push_back(0);

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x > 0)
			insert(x);
		if (x == 0)
			extractMax();
	}
}