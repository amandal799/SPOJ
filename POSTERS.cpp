// solution to the "POSTERS - Election Posters" problem of spoj

#include<bits/stdc++.h>
using namespace std;
const long N=1e7;
int lazy[40000005];
set<int> st;
void update(long s,long e,long i,long l,long r,int c)
{
    if(l>e || r<s) return;
    if(l<=s && r>=e) 
    {
        lazy[i]=c;
        return;
    }
    long m=(s+e)>>1L;
    if(lazy[i])
    {
    lazy[2*i+1]=lazy[2*i+2]=lazy[i];
    lazy[i]=0L;
    }
    update(s,m,2*i+1,l,r,c);
    update(m+1,e,2*i+2,l,r,c);
}
void cnt(long s,long e,long i)
{
    if(lazy[i])
    {
        st.insert(lazy[i]);
        return;
    }
    if(s==e) return;
    int m=(s+e)>>1L;
    cnt(s,m,2L*i+1L);
    cnt(m+1L,e,2L*i+2L);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(lazy,0,sizeof lazy);
        for(int i=1;i<=n;i++)
        {
            int l,r;
            cin>>l>>r;
            update(0L,N-1L,0L,l-1L,r-1L,i);
        }
        st.clear();
        cnt(0L,N-1L,0L);
        cout<<st.size()<<"\n";
    }
}

