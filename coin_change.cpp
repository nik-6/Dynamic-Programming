#include <iostream>
using namespace std;

int solve(int s[], int n, int m)
{
    int dp[m+1];
    for(int i = 0; i<=m;++i)
    {
        dp[i] = 0;
    }
    dp[0] =1;
    for(int i = 0; i<n; ++i)
    {
        for(int j = s[i]; j<=m;++j)
        {
            dp[j] += dp[j-s[i]];
        }
    }
    return dp[m];
}



int main()
{
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n ;
        int a[n];
        for(int i =0; i < n;++i)
        {
            cin >> a[i];
        }
        cin >> m;
        cout << solve(a,n,m)<<endl;
    }
    
    return 0;
}