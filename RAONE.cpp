// solution to the "RAONE - Ra-One Numbers" problem of spoj

#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10][100][100];
ll DP(vector<int> &v,int idx,int even,int odd,int flag)
{
    if(idx==-1)return even-odd==1;
    if(flag==1 && dp[idx][even][odd]!=-1) return dp[idx][even][odd];
    ll ans=0;
    int k=(flag)?9:v[idx];
    for(int i=0;i<=k;i++)
    {
        if(idx%2)
            ans+=DP(v,idx-1,even+i,odd,flag|(i<v[idx]));
        else
            ans+=DP(v,idx-1,even,odd+i,flag|(i<v[idx]));
    }
    if(flag==1) dp[idx][even][odd]=ans;
    return ans;
}
ll solve(ll n)
{
    vector<int> v;
    for(int i=0;i<9;i++)
    {
        v.push_back(n%10LL);
        n/=10LL;
    }
    ll ans=0;
    int flag=0;
    for(int i=v.size()-1;i>=0;i--)
    {
        int k=(flag)?9:v[i];
        for(int j=1;j<=k;j++)
        {
            if(i%2)
            ans+=DP(v,i-1,j,0,flag|(j<v[i]));
            else
                ans+=DP(v,i-1,0,j,flag|(j<v[i]));
        }
        flag|=(0<v[i]);
    }
    return ans;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<solve(r)-solve(l-1)<<"\n";
    }
}
