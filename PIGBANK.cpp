// solution to the "PIGBANK - Piggy-Bank" problem of spoj

#include<iostream>
#include <algorithm>
using namespace std;
const long M=10000000;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int e,w;
              cin>>e>>w;
              w-=e;
              int n;
              cin>>n;
              long c[n],wt[n];
              for(int i=0;i<n;i++)
                      cin>>c[i]>>wt[i];
                      long dp[n][w+1];
                      for(int j=0;j<=w;j++)
                      {
                              if(wt[0]>j || j%wt[0]!=0) dp[0][j]=M;
                              else
                              dp[0][j]=(j/wt[0])*c[0];
                      }
                      for(int i=1;i<n;i++)
                      {
                        for(int j=0;j<=w;j++)
                        {
                                   
                                   dp[i][j]=dp[i-1][j];
                                   if(wt[i]==j)
                                   dp[i][j]=min(c[i],dp[i][j]);
                                   else if(wt[i]<j && dp[i][j-wt[i]]!=M)
                                        dp[i][j]=min(c[i]+dp[i][j-wt[i]],dp[i][j]);
                                    
                        }
                      }
                      if(dp[n-1][w]!=M) cout<<"The minimum amount of money in the piggy-bank is "<<dp[n-1][w]<<".\n";
                      else cout<<"This is impossible.\n";
    }
}
                      
