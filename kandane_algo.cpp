#include <bits/stdc++.h>
using namespace std;

int find(int a[], int  n)
{
	int i = 0;
	int max_sum = INT_MIN;
	int sum = 0;
	while(i < n)
	{
		sum += a[i];
		if(sum > max_sum)
			max_sum = sum;
		if(sum < 0)
			sum = 0;
		i++;
	}
	
	return max_sum;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cout << find(a,n) <<endl;
	}
	return 0;
}