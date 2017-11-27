// solution to the "RANGESUM - Range Sum" problem of spoj

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll arr[2][N];
void update(int x,long val,int n,int i)
{
    while(x<=n)
      {
        arr[i][x]+=val;
        x+=(x & (-x));
    }
}
ll query(int x,int i)
{ 
    ll sum=0;
    while(x>0)
      {
        sum+=arr[i][x];
        x-=x & (-x);
    }
    return sum;
}
int main()
 {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
       {
        long k;
        cin>>k;
        update(i,k,n,0);
     }
    int q;
    cin>>q;
    int k=0;
    for(int i=1;i<=q;i++)
      {
        int a;
        cin>>a;
        if(a==1)
          {
           int l,r;
            ll sum=0;
            cin>>l>>r;
            int diff=r-l+1;
            int c=k-l+1;
            if(c>0)
             {
                sum+=query(c,1);
                if(c>=diff)
                    sum-=query(c-diff,1);
                else
                   sum+=query(diff-c,0);
            }
            else 
             {
                r-=k;
                l-=k;
                sum+=query(r,0)-query(l-1,0);
            }
            cout<<sum<<"\n";
         }
        else
         {
            long val;
            cin>>val;
             k++;
            update(k,val,q,1);
        }
    }
}
