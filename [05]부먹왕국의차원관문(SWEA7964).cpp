#include<iostream>
#include<memory.h>
using namespace std;

int door[300000];
int N, d;

int main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		cin >> N >> d;

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &door[i]);
		}
		int d_cnt = d;
		int answer = 0;
		for (int i = 0; i < N; i++)
		{
			
			if (d_cnt == d && door[i] == 0)
			{
				answer++;
				d_cnt = 0;
			}
			else if (d_cnt == d && door[i] == 1)
			{
				d_cnt = 0;
			}
			else if (d_cnt != d && door[i] == 1)
			{
				d_cnt = 0;
			}
			d_cnt++;
		}
		cout <<'#'<<t<<' '<< answer << '\n';
		memset(door, 0, sizeof(door));
	}
	
	return 0;
}