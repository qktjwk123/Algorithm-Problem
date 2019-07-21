#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
struct info
{
	int h, w;
};
info dis[2];
int H, W;
char map[101][101];
int check[101][101];
int dh[4] = { 0,0,-1,1 };
int dw[4] = { -1,1,0,0 };
int bfs()
{
	int idx = 0;
	bool flag1 = true;
	bool flag2 = true;
	queue<info> q[2];
	
	q[0].push(dis[0]);
	check[dis[0].h][dis[0].w] = 1;
	q[1].push(dis[1]);
	check[dis[1].h][dis[1].w] = 1;

	while (1)
	{
		info cur_1;
		info cur_2;
		if (flag1==true && (!q[0].empty()))
		{
			cur_1 = q[0].front();
			q[0].pop();
		}
		if (flag2 == true && (!q[1].empty()))
		{
			cur_2 = q[1].front();
			q[1].pop();
		}

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << check[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		for (int i = 0; i < 4; i++)
		{

			if (flag1==true && (!q[0].empty()))
			{
				info next_1;
				next_1.h = cur_1.h + dh[i];
				next_1.w = cur_1.w + dw[i];

				if (next_1.h < 0 || next_1.w < 0 || next_1.h >= H || next_1.w >= W)
				{
					flag1 = false;
					continue;
				}
				else if (check[next_1.h][next_1.w] > 0)continue;
				else if (map[next_1.h][next_1.w] == '*')continue;
				else if (map[next_1.h][next_1.w] == '.' || map[next_1.h][next_1.w] == '$')
				{
					check[next_1.h][next_1.w] = check[cur_1.h][cur_1.w];
					q[0].push(next_1);
				}
				else if (map[next_1.h][next_1.w] == '#')
				{
					idx++;
					check[next_1.h][next_1.w] = idx;
					q[0].push(next_1);
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (flag2 == true && (!q[1].empty()))
			{
				info next_2;
				next_2.h = cur_2.h + dh[i];
				next_2.w = cur_2.w + dw[i];

				if (next_2.h < 0 || next_2.w < 0 || next_2.h >= H || next_2.w >= W)
				{
					flag2 = false;
					continue;
				}
				else if (check[next_2.h][next_2.w] > 0)continue;
				else if (map[next_2.h][next_2.w] == '*')continue;
				else if (map[next_2.h][next_2.w] == '.' || map[next_2.h][next_2.w] == '$')
				{
					check[next_2.h][next_2.w] = check[cur_2.h][cur_2.w];
					q[1].push(next_2);
				}
				else if (map[next_2.h][next_2.w] == '#')
				{
					idx++;
					check[next_2.h][next_2.w] = idx;
					q[1].push(next_2);
				}
			}
		}
		if (flag1 == false && flag2 == false)break;
	}
	return idx;
}
int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		cin >> H >> W;
		int idx = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				scanf("%1s", &map[i][j]);
				if (map[i][j] == '$')
				{
					dis[idx].h = i;
					dis[idx].w = j;
					idx++;
				}
			}
		}
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << map[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		int answer = bfs();
		
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cout << check[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
		cout << answer << '\n';
	}
	return 0;
}