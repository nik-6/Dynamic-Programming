#include <iostream>
using namespace std;

int knap_sack(int w[], int v[],int n, int b)
{
   int dp[n+1][b+1];
   for (int i = 0; i < n+1; ++i)
   {
      for(int j = 0; j < b+1; ++j)
      {
        if(i==0 || j == 0)
            dp[i][j] = 0;
        else if((j - w[i-1]) >= 0)
            dp[i][j] = max(dp[i-1][j-w[i-1]]+v[i-1] , dp[i-1][j]);
        else
            dp[i][j] = dp[i-1][j];
            
      }
   }
   return dp[n][b];
}

int main()
{
   int t;
   cin >> t;
   while(t--)
   {
      int n;
      cin >> n;
      int b;
      cin >> b;
      int v[n],w[n];
      for (int i = 0; i < n; ++i)
      {
         cin >> v[i];
      }
      for (int i = 0; i < n; ++i)
      {
         cin >> w[i];
      }
      cout << knap_sack(w,v,n,b)<<endl;
   }
   return 0;
}