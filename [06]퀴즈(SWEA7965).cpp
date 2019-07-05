#include<iostream>
// 지수를 분해 4^4 = 4^2 * 4^2
using namespace std;

int N;
long long num[1000001];
long long MOD = 1000000007;
long long cal_pow(int a, int n)
{
	long long result = 1;
	long long multiply = a;
	while (n > 0)
	{
		if (n % 2 == 1)
		{
			result *= multiply;
			result %= MOD;
		}
		multiply = multiply * multiply % MOD;
		n /= 2;
	}
	return result;
}
int main()
{
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> N;
		long long answer = 0;
		for (int i = 1; i <= N; i++)
		{
			if (num[i]>0)continue;
			num[i] = (cal_pow(i, i) + num[i - 1]) % MOD;
		}
		printf("#%d %lld\n", t, num[N]);
	}
	return 0;
}