// solution to the DQUERY problem on spoj

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define PPI pair<pair<int,int>,int>
#define pb push_back
#define mk make_pair

int k;

bool myway(PPI &p1,PPI &p2)
 {
    int x=p1.f.f/k;
    int y=p2.f.f/k;
    if(x!=y)
       return x<y;
    return p1.f.s<p2.f.s;
}
int main()
 {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int arr[n];
    int f[1000001]={0};
     k=sqrt(n);
    vector<PPI> v;
    for(int i=0;i<n;i++)
       cin>>arr[i];
        int q;
    cin>>q;
    int B[n+1];
     for(int i=0;i<q;i++)
       {
         int l,r;
         cin>>l>>r;
         l--;r--;
         v.pb(mk(mk(l,r),i));
     }
    sort(v.begin(),v.end(),myway);
    int m_l=0,m_r=-1;
    int ans=0;
    int A[q];
    for(int i=0;i<q;i++)
      {
        int l=v[i].f.f;
        int r=v[i].f.s;
         while(m_r<r)
         {
            m_r++;
            f[arr[m_r]]++;
            if(f[arr[m_r]]==1)
                ans++;
        }
        while(m_r>r)
          {
           f[arr[m_r]]=(f[arr[m_r]]==1)?0:f[arr[m_r]]-1;
            if(f[arr[m_r]]==0)
              ans--;
              m_r--;
        }
        while(m_l<l)
        {
             f[arr[m_l]]=(f[arr[m_l]]==1)?0:f[arr[m_l]]-1;
            if(f[arr[m_l]]==0)ans--;
            m_l++;
        }
        while(m_l>l)
         {
            m_l--;
           f[arr[m_l]]++;
            if(f[arr[m_l]]==1)ans++;
        }
        A[v[i].s]=ans;
    }
    for(int i=0;i<q;i++)cout<<A[i]<<"\n";
}
