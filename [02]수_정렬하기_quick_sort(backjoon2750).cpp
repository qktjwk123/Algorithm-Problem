#include<iostream>

using namespace std;
int num[1001];
int N;
void swap_value(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partitioning(int *arr, int left, int right)
{
	if (arr == NULL || left < 0)return -1;
	int mid = (left + right) / 2;
	swap_value(&arr[mid], &arr[left]);
	int pivot_Value = arr[left];
	int i = left, j = right;

	while (i < j)
	{
		while (pivot_Value < arr[j])
		{
			j--;
		}
		while (i < j && pivot_Value >= arr[i])
		{
			i++;
		}
		swap_value(&arr[i], &arr[j]);
	}
	arr[left] = arr[i];
	arr[i] = pivot_Value;

	return i;
}



void quick_sort(int *arr, int left, int right)
{

	if (left >= right)return;

	int pivot_idx = partitioning(arr,left,right);

	quick_sort(arr, left, pivot_idx-1);
	quick_sort(arr, pivot_idx + 1, right);
}



int main()
{

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	quick_sort(num, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << num[i] << '\n';
	}

	return 0;
}