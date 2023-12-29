#include <iostream>
#include <vector>
#include <functional>

using namespace std;

#define INF 20000000

vector<pair<int, int> >pq; // first : 다음 정점, second : 가중치
vector<pair<int, int> >*list;
int *d;
int *d2;
int *d3;
int N, E, stopover1, stopover2;

void print(int *d)
{
	for (int i = 1; i <= N; i++)
		cout << d[i] << " ";
	cout << '\n';
}


void allocatevec(void)
{
	pq.push_back(make_pair(INF, INF));
	list = new vector<pair<int, int> >[N + 1];
	d = new int[N + 1];
	d2 = new int[N + 1];
	d3 = new int [N + 1];

	for (int i = 1; i <= N; i++)
	{
		d[i] = INF;
		d2[i] = INF;
		d3[i] = INF;
	}
}


int parent(int i)
{
	return i/2;
}

void swap(int parent, int son)
{
	int tempFirst = pq[parent].first;
	int tempSecond = pq[parent].second;

	pq[parent].first = pq[son].first;
	pq[parent].second = pq[son].second;

	pq[son].first = tempFirst;
	pq[son].second = tempSecond;
}


void insert(int first, int second)
{
	pq.push_back(make_pair(first, second));
	int i = pq.size() - 1;

	while (i > 1)
	{
		if (pq[i].second >= pq[parent(i)].second)
			break;
		swap(parent(i), i);
		i = parent(i);
	}
}

int selectMinChild(int i)
{
	int leftChild = i * 2;
	int rightChild = i * 2 + 1;
	int size = pq.size() - 1;

	if (leftChild > size)
		return - 1;
	if (leftChild == size)
		return leftChild;
	if (pq[leftChild].second < pq[rightChild].second)
		return leftChild;
	return rightChild;
}

void minHeapify(int i)
{
	int child = selectMinChild(i);
	if (child == -1)
		return;
	else
	{
		if (pq[child].second < pq[i].second)
		{
			swap(i, child);
			minHeapify(child);
		}
	}
}

bool isEmpty(void)
{
	if (pq.size() <= 1)
		return true;
	return false;
}

void deleteTop(void)
{
	if (pq.size() == 1)
		return;
	else if (pq.size() == 2)
	{
		pq.pop_back();
		return ;
	}
	swap(1, pq.size() - 1);
	pq.pop_back();
	minHeapify(1);
}

void djikstra(int start, int *d)
{
	d[start] = 0;
	pq.push_back(make_pair(start, d[start]));

	while(!isEmpty())
	{
		int currentIndex = pq[1].first;
		int weight = pq[1].second;
		deleteTop();

		for (int i = 0; i < list[currentIndex].size(); i++)
		{
			int nextIndex = list[currentIndex][i].first;
			int distance = weight + list[currentIndex][i].second;

			if (distance < d[nextIndex])
			{
				d[nextIndex] = distance;
				pq.push_back(make_pair(nextIndex, distance));
			}
		}
	}
}


int cal(void)
{
	int path1 = d[stopover1] + d2[stopover2] + d3[N];
	int path2 = d[stopover2] + d3[stopover1] + d2[N];

	int ans = min(path1, path2);
	if (ans >= INF)
		return -1;
	else
		return ans;
}



int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> E;
	allocatevec();
	for (int i = 0; i < E; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		list[start].push_back(make_pair(end, weight));
		list[end].push_back(make_pair(start, weight));
	}
	cin >> stopover1 >> stopover2;
	djikstra(1, d);
	djikstra(stopover1, d2);
	djikstra(stopover2, d3);
	cout << cal();
}