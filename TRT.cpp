// solution to the TRT - Treats for the Cows problem on spoj

#include<bits/stdc++.h>
using namespace std;
int M[2000][2000];
int max(int a,int b)
    {
    return a>b?a:b;
}
int fun(int l,int r,int a,int *arr)
    {
     if(M[l][r]!=-1) return M[l][r];
    if(l==r)
    {M[l][r]=a*arr[l];return M[l][r];}
    M[l][r]=max(a*arr[l]+fun(l+1,r,a+1,arr),a*arr[r]+fun(l,r-1,a+1,arr));
    return M[l][r];
}
int main()
  {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    memset(M,-1,sizeof M);
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<fun(0,n-1,1,arr);
}
