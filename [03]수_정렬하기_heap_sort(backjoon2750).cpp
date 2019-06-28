#include<iostream>

using namespace std;

int N;
int heap[20001];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> heap[i];
	}
	int Num = N / 2;
	for (int i = 1; i < N; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	for (int i = N - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do
		{
			c = 2 * root + 1;
			if (c < i - 1 && heap[c] < heap[c + 1])
			{
				c++;
			}
			if (c < i&&heap[root] < heap[c])
			{
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	for (int i = 0; i < N; i++)
	{
		cout << heap[i] << '\n';
	}
	return 0;
}
