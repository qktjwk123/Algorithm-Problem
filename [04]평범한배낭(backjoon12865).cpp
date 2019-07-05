#include<iostream>
#include<algorithm>
#include<memory.h>


using namespace std;

int W[101];
int V[101];
int Bagpack[101][100001];
int N, K, w, v;

int go(int i, int j)
{
	int &result = Bagpack[i][j];
	if (i <= 0 || j > K) return 0;
	if (result != -1)return result;
	Bagpack[i][j] = go(i - 1, j);
	if (j - W[i] >=0)
	{
		Bagpack[i][j] = max(go(i - 1, j - W[i]) + V[i], Bagpack[i][j]);
	}
	return result;
}
int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> W[i] >> V[i];
	}
	memset(Bagpack, -1, sizeof(Bagpack));
	go(N, K);

	cout << Bagpack[N][K] << '\n';
	return 0;
}