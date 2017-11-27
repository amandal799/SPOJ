// solution to SUMFOUR problem of spoj

#include <bits/stdc++.h>
using namespace std;
int main()
    {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    long arr1[2501],arr2[2501],arr3[2501],arr4[2501];
    for(int i=0;i<n;i++)
      {
       
            cin>>arr1[i];
            cin>>arr2[i];
            cin>>arr3[i];
            cin>>arr4[i];
           
    }
    vector<long> v;
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
            v.push_back(arr3[i]+arr4[j]);
      }
    sort(v.begin(),v.end());
    pair<vector<long>::iterator,vector<long>::iterator> p;
    long ans=0;
    for(int i=0;i<n;i++)
      {
        long diff=0-arr1[i];
        for(int j=0;j<n;j++)
           {
             p=equal_range(v.begin(),v.end(),diff-arr2[j]);
            ans+=p.second-p.first;
          }
     }
    cout<<ans;
}
