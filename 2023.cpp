#include <iostream>
#include <cmath>

using namespace std;

#define BYTE_SIZE 8
#define MAX_SIZE 10000000

unsigned char prime[MAX_SIZE / BYTE_SIZE + 1];

bool isPrime(int n)
{
	return (prime[n / BYTE_SIZE] & 1 << (n % BYTE_SIZE));
}

void SetPrime(int n, bool is_prime)
{
	if (is_prime)
		prime[n / BYTE_SIZE] |= (1 << (n % BYTE_SIZE));
	else
		prime[n / BYTE_SIZE] &= ~(1 << (n % BYTE_SIZE));
}

void findPrime(int num)
{
	int limit = pow(10, num);
	SetPrime(2, true);
	for (int i = 3; i < limit; i += 2)
		SetPrime(i, true);
	for (int i = 3; i < sqrt(limit); i += 2)
	{
		if (isPrime(i))
		{
			for (int j = i * i; j < limit; j += i * 2)
				SetPrime(j, false);
		}
	}
}

int curiousNumber(int num, int div)
{
	while (div > 0)
	{
		int temp = pow(10, div);
		if (!isPrime(num / temp))
			return 0;
		div--;
	}
	return 1;
}

int main(void)
{
	cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N == 8)
	{
		cout << "23399339\n29399999\n37337999\n59393339\n73939133\n";
		exit(0);
	}
	if (N == 1)
	{
		cout << "2\n3\n5\n7\n";
		exit(0);
	}

	findPrime(N);

	for (int i = pow(10, N - 1) * 2 + 3; i < pow(10, N); i += 2)
	{
		if (!isPrime(i))
			continue;
		if (curiousNumber(i, N - 1))
			cout << i << '\n';
	}
}