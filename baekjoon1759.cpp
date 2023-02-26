#include <iostream>
#include <algorithm>

using namespace std;
char alpha[16] = {0};
char new_alpha[16] = {0};

int count_vowel(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (new_alpha[i] == 'a' ||new_alpha[i] == 'e'|| new_alpha[i] == 'i' || new_alpha[i] == 'o' || new_alpha[i] == 'u') {
            count++;
        }
    }
    return count;
}

int count_consonant(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (new_alpha[i] != 'a'&& new_alpha[i] != 'e' && new_alpha[i] != 'i' && new_alpha[i] != 'o' && new_alpha[i] != 'u') {
            count++;
        }
    }
    return count;
}

int check_arr(int n) {
    if (n == 0)
        return 1;
    for (int i = 0; i < n; i++) {
        if (new_alpha[n] <= new_alpha[i])
            return 0;
    }
    return 1;
}

void put_alpha(int m, int n, int k) {
    if (n == k) {
        if (count_vowel(k) == 0 || count_consonant(k) < 2) {
            return;
        }
        else {
            for (int i = 0; i < k; i++) {
                cout << new_alpha[i];
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 0; i < m; i++) {
            new_alpha[n] = alpha[i];
            if (check_arr(n)) {
                    put_alpha(m, n + 1, k);
                }
            }
        }
}

int main(void) {
    int L, C;
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> alpha[i];
    }
    sort(alpha, alpha+C);
    put_alpha(C, 0, L);
}

