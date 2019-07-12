#include<iostream>
#include<queue>
#include<map>
#include<string>

using namespace std;
int dc[4] = { 0,0,-1,1 };
int dr[4] = { -1,1,0,0 };
int main()
{
	int n = 3;
	int start = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 0)temp = 9;
			start = start * 10 + temp;
		}
	}
	queue<int> q;
	map<int, int> dist;
	q.push(start);
	dist[start] = 0;
	while (!q.empty())
	{
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();
		int z = now.find('9');
		int r = z / 3;
		int c = z % 3;
		for (int k = 0; k < 4; k++)
		{
			int ar = r + dr[k];
			int ac = c + dc[k];
			if (ar < 0 || ar >= 3 || ac < 0 || ac >= 3)continue;
			string next = now;
			
			swap(next[r * 3 + c], next[ar * 3 + ac]);

			int num = stoi(next);
			if (dist.count(num) == 0)
			{
				dist[num] = dist[now_num] + 1;
				q.push(num);
			}
		}
		
	}
	if (dist.count(123456789) == 0)
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << dist[123456789] << "\n";
	}
	return 0;
}