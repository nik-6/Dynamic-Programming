#include <iostream>
using namespace std;
int dp[11][51];
int main()
{
    int tem,test,n,k;
    for(int i = 1; i < 11; ++i)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(int i = 2; i <51; ++i)
    {
        dp[1][i] = i;
    }
    for(int  i = 2; i < 11; ++i)
    {
        for(int j = 2; j < 51; ++j)
        {
            dp[i][j] = 999999;
            for(int t = 1; t <= j; ++t)
            {
                tem = 1+max(dp[i-1][t-1],dp[i][j-t]);
                dp[i][j] = min(dp[i][j],tem);
            }
        }
    }
    cin >> test;
    while(test--)
    {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
	return 0;
}