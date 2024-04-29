#include <iostream>
#include <vector>

using namespace std;
int N, M; // N X N 도시 M개 고르기
int map[51][51] = {0, };
int choice[14][2] = {0, };
vector<pair<int, int> >chicken;
vector<pair<int, int> >house;
int min_dist = 1e9;

int CalDist() { // 거리 재기
	int sum_dist = 0;
	for (int i = 0; i < house.size(); i++) {
		int dist = 1e9;
		int house_x = house[i].first + 1;
		int house_y = house[i].second + 1;
		for (int i = 0; i < M; i++) {
			dist = min(dist, (abs(house_x - choice[i][0]) + abs(house_y - choice[i][1])));
		}
		sum_dist += dist;
		if (sum_dist > min_dist)
			return 1e9;
	}
	return sum_dist;
}

void FindChickenPos(int depth, int start) { // 치킨집 선택
	if (depth == M) {
		int dist = CalDist();
		min_dist = min(min_dist, dist);
		return;
	}

	for (int i = start; i < chicken.size(); i++) {
		choice[depth][0] = chicken[i].first + 1;
		choice[depth][1] = chicken[i].second + 1;
		FindChickenPos(depth + 1, i + 1);
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			if (x == 2) {
				chicken.push_back(make_pair(i, j));
			} else if (x == 1) {
				house.push_back(make_pair(i, j));
			}
			map[i][j] = x;
		}
	}
	FindChickenPos(0, 0);
	cout << min_dist;
}