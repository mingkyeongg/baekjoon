#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int cnt, idx;
        cin >> cnt >> idx;
        queue<pair<int, int > > q;
        priority_queue<int> pq;
        for (int i = 0; i < cnt; i++) {
            int x;
            cin >> x;
            q.push(make_pair(x, i));
            pq.push(x);
        }

        int ans = 0;
        while (!q.empty()) {
            int currentImp = q.front().first;
            int currentIdx = q.front().second;
            q.pop();
            if (currentImp == pq.top()) {
                ans++;
                pq.pop();
                if (currentIdx == idx) {
                    cout << ans << '\n';
                    break;
                }
            } else {
                q.push(make_pair(currentImp, currentIdx));
            }
        }
    }
}
