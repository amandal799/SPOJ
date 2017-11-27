// solution to the YODANESS - Yodaness Level problem on spoj

#include<bits/stdc++.h>
using namespace std;
int ans=0;
void merge(int *arr,int l,int m,int r)
{
    int arr1[r-l+1];
    int i=l,j=m+1;
    int k=0;
    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j]) {arr1[k++]=arr[i++];}
        else
        {
           arr1[k++]=arr[j++];
           ans+=(m-i+1); 
        }
    }
    while(i<=m)
        arr1[k++]=arr[i++];
    while(j<=r) arr1[k++]=arr[j++];
     k=0;
    for(int i=l;i<=r;i++)
    {
        arr[i]=arr1[k++];
    }
}
void countInversion(int *arr,int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        countInversion(arr,l,m);
        countInversion(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string,int> mp;
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            mp[s]=i;
        }
        int arr[n];
         for(int i=0;i<n;i++) {
            string s;
            cin>>s;
           arr[i]=mp[s];
         }
        ans=0;
        countInversion(arr,0,n-1);
       cout<<ans<<"\n";
    }
}
