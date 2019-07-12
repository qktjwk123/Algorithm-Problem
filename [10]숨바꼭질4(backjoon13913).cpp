#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int MAX = 200000;

bool check[MAX + 1];
int D[MAX + 1];
int before[MAX + 1];


void print(int n, int m) {
	if (n != m) {
		print(n, before[m]);
	}
	cout << m << ' ';
}

int main()
{
	int S, F;
	cin >> S >> F;
	check[S] = true;
	D[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now - 1 >= 0)
		{

			if (check[now - 1] == false)
			{
				check[now - 1] = true;
				D[now - 1] = D[now] + 1;
				before[now - 1] = now;
				q.push(now - 1);
			}

		}
		if (now + 1 < MAX)
		{
			if (check[now + 1] == false)
			{
				check[now + 1] = true;
				D[now + 1] = D[now] + 1;
				before[now + 1] = now;
				q.push(now + 1);
			}

		}
		if (now * 2 < MAX)
		{
			if (check[now * 2] == false)
			{
				check[now * 2] = true;
				D[now * 2] = D[now] + 1;
				before[now * 2] = now;
				q.push(now * 2);
			}

		}


	}
	cout << D[F] << '\n';
	print(S, F);
	cout << '\n';
	return 0;
}