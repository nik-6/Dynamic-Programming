#include <iostream>
using namespace std;

int min(int a,int b,int c){

    return (min(min(a,b),c));
}


int weighed_edit_distance(string a , string b)
{
    int n = a.size();
    int m = b.size();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; ++i)
    {
        for(int j = 0; j <= n; ++j)
        {
            if(j==0)
                dp[i][j] = i;
            else if(i == 0)
                dp[i][j] = j;
            else 
            {
                if(b[i-1] == a[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+ min(dp[i-1][j], dp[i][j-1] , dp[i-1][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    int t ;
    cin >> t;
    while(t--)
    {
       string a;
       string b;
       int n,m;
       cin >> n >> m;
       cin >> a;
       cin >> b;
       cout<< weighed_edit_distance(a,b) <<endl;
    }
    return 0;
}