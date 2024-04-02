#include <iostream>
#include <vector>

using namespace std;

#define BLUE 1
#define WHITE 0

int blue_paper = 0;
int white_paper = 0;
int n;

int CheckVal(vector<int>v[], int N, int x, int y) {
	bool is_white = false;
	bool is_blue = false;
	for (int i = x; i < N + x; i++) {
		for (int j = y; j < N + y; j++) {
			if (v[i][j] == BLUE) {
				is_blue = true;
			} else {is_white = true;}
		}
	}
	if (is_blue && !is_white)
		return BLUE;
	else if (!is_blue && is_white)
		return WHITE;
	else
		return -1;
}

void Split(vector<int>v[], int N, int x, int y) {
	int color = CheckVal(v, N, x, y);
	if (color == BLUE) {
		blue_paper++;
		return;
	}
	else if (color == WHITE) {
		white_paper++;
		return;
	}
	Split(v, N/2 ,x, y);
	Split(v, N/2, x + N/2, y);
	Split(v, N/2, x, y + N/2);
	Split(v, N/2, x + N/2, y + N/2);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	vector<int>v[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			v[i].push_back(x);
		}
	}
	Split(v, n, 0, 0);
	cout << white_paper << '\n' << blue_paper;
}