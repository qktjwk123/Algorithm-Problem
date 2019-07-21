#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX = 4003;
int arr[4][MAX];

int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)

		for (int j = 0; j < 4; j++)

			cin >> arr[j][i];

	vector<int> v;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}
	sort(v.begin(), v.end());

	long long result = 0;
	int key, lb, ub;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			key = (arr[0][i] + arr[1][j])*-1;
			
			int s, e, mid;
			s = 0, e = N * N;
			while (s < e)
			{
				mid = (s + e) / 2;
				if (v[mid] < key)
				{
					s = mid + 1;
				}
				else
				{
					e = mid;
				}
			}
			if(e == N * N) lb = 999999;
			else lb = e;

			s = lb, e = N * N;
			while (s < e)
			{
				mid = (s + e) / 2;
				if (v[mid] <= key)
				{
					s = mid + 1;
				}
				else
				{
					e = mid;
				}
			}
			ub = e;

			if (lb < ub) result += (ub - lb);
		}
	}
	cout << result << "\n";

	return 0;

}