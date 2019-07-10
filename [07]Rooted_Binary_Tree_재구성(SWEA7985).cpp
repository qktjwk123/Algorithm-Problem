#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

vector<int> tree[11];
int tree_num[1025];
int K;

int main()
{
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++)
	{
		scanf("%d", &K);
		int t_size = 1 << K;
		for (int i = 1; i < t_size; i++)
		{
			scanf("%d", &tree_num[i]);
		}

		int cnt = 1;
		int idx = 0;
		while (1)
		{
			if (idx == K)break;
			for (int i = cnt; i < t_size; i += (cnt * 2))
			{
				tree[idx].push_back(tree_num[i]);
			}
			cnt *= 2;
			idx++;
		}
		printf("#%d ", t);
		for (int i = K-1; i >=0; i--)
		{
			int tree_size = tree[i].size();
			for (int j = 0; j < tree_size; j++)
			{
				printf("%d ", tree[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < K; i++)
		{
			tree[i].clear();
		}
		memset(tree_num, 0, sizeof(tree_num));
	}
	return 0;
}