// solution to the "NUMTSN - 369 Numbers" problem of spoj

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
const ll M=1000000007;
ll dp[55][55][55][55];
ll DP(string &s,int idx,int a3,int a6,int a9,int flag)
{
    if(idx==s.size())
    {
        return (a3>=1 && (a3==a6 && a3==a9));
    }
    ll ans=dp[idx][a3][a6][a9];
    if(flag==1 && ans!=-1) return ans;
    int k=(flag)?9:s[idx]-'0';
    ans=0;
    for(int j=0;j<=k;j++)
    {
        if(j==3)
            ans=(ans+DP(s,idx+1,a3+1,a6,a9,flag|(j<(s[idx]-'0'))))%M;
            else if(j==6)
                ans=(ans+DP(s,idx+1,a3,a6+1,a9,flag|(j<(s[idx]-'0'))))%M;
            else if(j==9)
             ans=(ans+DP(s,idx+1,a3,a6,a9+1,flag|(j<(s[idx]-'0'))))%M;
            else
                ans=(ans+DP(s,idx+1,a3,a6,a9,flag|(j<(s[idx]-'0'))))%M;
    }
    if(flag==1)
    dp[idx][a3][a6][a9]=ans;
    return ans;
}
void concatString(string &s)
{
    for(int i=s.size();i<=50;i++)
        s+='0';
}
ll solve(string &s)
{
    int n=s.size();
     //memset(dp,-1,sizeof dp);
    ll ans=0;
    int flag=0;
    for(int i=0;i<s.size();i++)
    {
        int k=(flag)?9:s[i]-'0';
      
        for(int j=1;j<=k;j++)
        {
            if(j==3)
            ans=(ans+DP(s,i+1,1,0,0,flag|(j<(s[i]-'0'))))%M;
            else if(j==6)
                ans=(ans+DP(s,i+1,0,1,0,flag|(j<(s[i]-'0'))))%M;
            else if(j==9)
             ans=(ans+DP(s,i+1,0,0,1,flag|(j<(s[i]-'0'))))%M;
            else
                ans=(ans+DP(s,i+1,0,0,0,flag|(j<(s[i]-'0'))))%M;
        }
        flag|=(0<(s[i]-'0'));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t=0;
   cin>>t;
   //  high_resolution_clock::time_point t1 = high_resolution_clock::now();
   memset(dp,-1,sizeof dp);
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        reverse(s1.begin(),s1.end());
         reverse(s2.begin(),s2.end());
        concatString(s1);
        concatString(s2);
        reverse(s1.begin(),s1.end());
         reverse(s2.begin(),s2.end());
       //cout<<s1<<"\n"<<s1.size()<<"\n";
         ll b=solve(s1);
        ll a=solve(s2);
        int a3,a6,a9;
        a3=a6=a9=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]=='3')a3++;
            else if(s1[i]=='6')a6++;
            else if(s1[i]=='9')a9++;
        }
        ll k=0;
        if(a3>=1 && a3==a6 && a3==a9) k=1;
        ll ans=(a-b+k+M)%M;
        cout<<ans<<"\n";
    }
    
       /* high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = t2 - t1;
          std::cout << "It took me " << time_span.count()<< " seconds.";*/
}
