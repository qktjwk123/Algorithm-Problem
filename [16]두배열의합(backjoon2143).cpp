#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A[1001];
int B[1001];

int T,N, M;
vector<int> v;
vector<int> ASub;
vector<int> BSub;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> B[i];
	}
	for (int i = 1; i < N; i++)
	{
		A[i] += A[i - 1];
	}
	for (int i = 1; i < M; i++)
	{
		B[i] += B[i - 1];
	}
	for (int i = 1; i <= N; i++)
	{
		ASub.push_back(A[i - 1]);
		for (int j = i; j < N; j++)
		{
			ASub.push_back(A[j] - A[j - i]);
		}
	}
	for (int i = 1; i <= M; i++)
	{
		BSub.push_back(B[i - 1]);
		for (int j = i; j < M; j++)
		{
			BSub.push_back(B[j] - B[j - i]);
		}
	}
	
	sort(ASub.begin(), ASub.end());
	sort(BSub.begin(), BSub.end());
	int s = 0, e = BSub.size() - 1;
	long long  answer = 0;
	while (1)
	{
		// 합이 t와 같은 경우
		if (ASub[s] + BSub[e] == T)
		{
			long long int cnt1 = 1;
			long long int cnt2 = 1;

			while (s + 1 <= ASub.size() - 1 && ASub[s] == ASub[s + 1])
			{
				s++;
				cnt1++;
			}

			while (e - 1 >= 0 && BSub[e] == BSub[e - 1])
			{
				e--;
				cnt2++;
			}

			answer += cnt1 * cnt2;
			s++; 
		}
		if (s <= ASub.size() - 1 && e >= 0 && ASub[s] + BSub[e] < T)
			s++;

		if (s <= ASub.size() - 1 && e >= 0 && ASub[s] + BSub[e] > T)
			e--;

		if (s > ASub.size() - 1 || e < 0)
			break;
	}

	cout << answer << '\n';
	return 0;
}