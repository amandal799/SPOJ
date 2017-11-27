// solution to SUBSUMS - Subset Sums problem of spoj

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void calc(vector<ll> &mp,ll *arr,int n)
{
    int N=(1<<n);
    for(int i=0;i<N;i++)
    {
        ll sum=0;
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j)) sum+=arr[j];
        }
        mp.push_back(sum);
    }
}
int main()
{
    int n;
    ll a,b;
    cin>>n>>a>>b;
    ll arr[n];
    for(int i=0;i<n/2;i++)
         cin>>arr[i];
    vector<ll> mp1,mp2;
    calc(mp1,arr,n/2);
    for(int i=n/2;i<n;i++)
        cin>>arr[i-n/2];
    calc(mp2,arr,n-n/2);
    sort(mp2.begin(),mp2.end());
    auto it=mp1.begin();
    ll ans=0;
    while(it!=mp1.end())
    {
        ll k=*it;
        int r=upper_bound(mp2.begin(),mp2.end(),b-k)-mp2.begin();
        int l=lower_bound(mp2.begin(),mp2.end(),a-k)-mp2.begin();
        ans+=r-l;
        it++;
    }
    cout<<ans<<"\n";
}
