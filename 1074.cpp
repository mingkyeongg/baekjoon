#include <iostream>
#include <cmath>

using namespace std;


int findOrder(int n, int r, int c)
{
	if (n == 1)
	{
		if (r == 0 && c == 0)
			return 0;
		else if (r == 0 && c == 1)
			return 1;
		else if (r == 1 && c == 0)
			return 2;
		else if (r == 1 && c == 1)
			return 3;
	}

	int half = pow(2, n - 1);
	if (r < half && c < half)
		return findOrder(n - 1, r, c);
	else if (r < half && c >= half)
		return half * half + findOrder(n - 1, r, c - half);
	else if (r >= half && c < half)
		return 2 * half * half + findOrder(n - 1, r - half, c);
	else
		return 3 * half * half + findOrder(n - 1, r - half, c - half);
}



int main(void)
{
	int N, r, c;
	cin >> N >> r >> c;
	cout << findOrder(N, r, c);

}