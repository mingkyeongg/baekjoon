#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_PRIME 1000000
bool prime[1000001] = {false, };

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, num;
    cin >> T;

    prime[2] = true;
    for (int i = 3; i <= MAX_PRIME; i += 2)
        prime[i] = true;

    int limit = sqrt(MAX_PRIME);
    for (int i = 3; i <= limit; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i * 2)
                prime[j] = false;
        }
    }

    while (T--) {
        cin >> num;
		if (num == 0)
			break;
        bool found = false;
        for (int i = 3; i <= num / 2; i += 2) {
            if (prime[i] && prime[num - i]) {
                cout << num << " = " << i << " + " << num - i << '\n';
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }
}
