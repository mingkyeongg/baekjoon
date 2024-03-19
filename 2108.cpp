/*
	수학, 구현, 정렬
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

vector<int> v;
map<int, int> m;
int N;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        m[x]++;
    }
    sort(v.begin(), v.end());

    double avg = 0;
    for (int i = 0; i < N; i++) {
        avg += v[i];
    }
	int ans = round(avg / N);
	if (ans == -0)
		ans = 0;
    cout << ans << '\n';

    cout << v[N / 2] << '\n';


    vector<pair<int, int> > freq(m.begin(), m.end());
    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    int freqValue = freq[0].first;
    if (freq.size() > 1 && freq[0].second == freq[1].second) {
        freqValue = freq[1].first;
    }
    cout << freqValue << '\n';

    cout << v[N - 1] - v[0] << '\n';
}


