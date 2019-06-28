#include<iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	long long cnt = 1;
	int n=0;
	while (1)
	{
		if (N / cnt == 0)break;
		n++;
		cnt *= 10;
	}
	cnt /= 10;
	
	long long result = 0;
	long long r_cnt = 1;
	for (int i = 1; i < n; i++)
	{
		result += (((r_cnt * 10) - r_cnt)*i);
		r_cnt *= 10;
	}
	
	long long answer = (N - cnt + 1)*n;

	answer += result;
	cout << answer << '\n';
	return 0;
}