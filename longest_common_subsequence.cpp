#include <iostream>
using namespace std;

int lcs(string a, string b, int n, int m)
{
	int dp[n+1][m+1];
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0;j<=m;++j)
		{
			if(i==0 || j==0)
				dp[i][j] = 0;
			else if(a[i-1] == b[j-1])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		string a,b;
		cin >> a >> b;
		cout << lcs(a,b,n,m) << endl;
	}
	return 0;
}