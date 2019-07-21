#include<iostream>

using namespace std;

int main()
{
	long long x, y, z, e, s, mid, key;
	cin >> x >> y;
	z = 100 * y / x;
	if (z >= 99)
	{
		cout << -1 << '\n';
		return 0;
	}
	s = 0;
	e = 1000000000;
	while (s <= e)
	{
		
		mid = (s + e) / 2;
		key = 100 * (y + mid) / (x + mid);
		if (z < key)
		{
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	cout << s << '\n';
	return 0;
}