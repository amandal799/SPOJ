// solution to the UPDATEIT - Update the array ! problem on spoj

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        long arr[n+1];
        memset(arr,0,sizeof arr);
        while(q--)
        {
            int l,r,val;
            cin>>l>>r>>val;
            arr[l]+=val;
            arr[r+1]-=val;
        }
        for(int i=1;i<n;i++) arr[i]+=arr[i-1];
        cin>>q;
        while(q--)
        {
            int ind;
            cin>>ind;
            cout<<arr[ind]<<"\n";
        }
    }
}
