#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;


vector<int> v[501];
int d[501];
int bt[501];
int N;

int dfs(int here)

{
	int& ret = d[here];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < (int)v[here].size(); i++)

	{
		int next = v[here][i];
		ret = max(ret, bt[next] + dfs(next));
	}
	return ret;

}

int main()

{

	cin >> N;



	for (int i = 1; i <= N; i++)

	{

		int a, b, c;

		scanf("%d", &a);
		bt[i] = a;
		while (true) {

			scanf("%d", &b);

			if (b == -1)break;

			v[i].push_back(b);

		}

	}

	memset(d, -1, sizeof(d));

	for (int i = 1; i <= N; i++)

	{

		cout << dfs(i) + bt[i] << '\n';

	}



	return 0;

}