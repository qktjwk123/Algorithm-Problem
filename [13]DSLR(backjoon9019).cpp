#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int S, F;
char dist[10001];
bool check[10001];
int from[10001];
void print_answer(int S, int F)
{
	if (S != F)
	{
		print_answer(S, from[F]);
	}
	if (S == F)return;
	cout << dist[F];
}
void bfs()
{
	queue<int> q;
	q.push(S);
	check[S] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == F)return;
		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				int next = cur * 2;
				if (next > 9999)next %= 10000;
				if (check[next] == false)
				{
					check[next] = true;
					q.push(next);
					dist[next] = 'D';
					from[next] = cur;
				}
			}
			else if (i == 1)
			{
				int next = cur - 1;
				if (next < 0)next = 9999;
				if (check[next] == false)
				{
					check[next] = true;
					q.push(next);
					dist[next] = 'S';
					from[next] = cur;
				}
			}
			else if (i == 2)
			{
				int next = (cur % 1000) * 10 + cur / 1000;
				if (check[next] == false)
				{
					check[next] = true;
					q.push(next);
					dist[next] = 'L';
					from[next] = cur;
				}
			}
			else if (i == 3)
			{
				int next = (cur / 10) + (cur%10) * 1000;
				if (check[next] == false)
				{
					check[next] = true;
					q.push(next);
					dist[next] = 'R';
					from[next] = cur;
				}
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		cin >> S >> F;
		bfs();
		print_answer(S, F);
		cout << '\n';
		memset(check, false, sizeof(check));
		memset(dist, false, sizeof(dist));
		memset(from, false, sizeof(from));
	}
	return 0;
}