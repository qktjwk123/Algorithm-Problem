#include<iostream>
#include<queue>

using namespace std;

const int MAX = 200000;
int check[MAX + 1];
int dist[MAX + 1];

int main()
{
	int S, F;
	cin >> S >> F;
	check[S] = 1;
	dist[S] = 0;
	int answer = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty())
	{
		int cur = q.front();
		if (cur == F) answer++;
		q.pop();
		if (cur - 1 >= 0)
		{
			int next = cur - 1;
			if (check[next] == 0 )
			{
				check[next] = 1;
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
			else if (dist[next] == dist[cur] + 1)
			{
				q.push(next);
			}
		}
		if (cur + 1 < MAX)
		{
			int next = cur + 1;
			if (check[next] == 0)
			{
				check[next] = 1;
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
			else if (dist[next] == dist[cur] + 1)
			{
				q.push(next);
			}
		}
		if (cur * 2 < MAX)
		{
			int next = cur * 2;
			if (check[next] == 0)
			{
				check[next] = 1;
				q.push(next);
				dist[next] = dist[cur] + 1;
			}
			else if (dist[next] == dist[cur] + 1)
			{
				q.push(next);
			}
		}
	}
	cout << dist[F] << "\n";
	cout << answer << '\n';
	return 0;
}
