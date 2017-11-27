// solution to the "QTREE2 - Query on a tree II" problem of spoj

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
    const int N0=10100;
    const int L=14;
        int p[N0][L];
        ll dis[N0],d[N0];
  vector<pair<int,int> > adj[N0];
void dfs(int u,int pre,int dep)
 {
    p[u][0]=pre;
    d[u]=dep;
    for(int i=0;i<adj[u].size();i++)
       {
        int v=adj[u][i].first;
        int w=adj[u][i].second;
        if(v!=p[u][0])
        {
            dis[v]=dis[u]+w;
            dfs(v,u,dep+1);
        }
        }
}
void sparse(int N)
  {
    for(int i=1;i<L;i++)
       {
        for(int j=1;j<=N;j++)
           {
             if(p[j][i-1]!=-1)
               p[j][i]=p[p[j][i-1]][i-1];
         }
    }
}
int LCA(int u,int v)
 {
    if(d[u]<d[v])swap(u,v);
    int diff=d[u]-d[v];
    for(int i=0;i<L;i++)
        {
         if((diff>>i)&1)
             u=p[u][i];
      }
    if(u==v) return u;
    for(int i=L-1;i>=0;i--)
      {
        if(p[u][i]!=p[v][i])
            {
            u=p[u][i];
            v=p[v][i];
        }
    }
    return p[u][0];
}
ll dist(int u,int v)
  {
    int lca=LCA(u,v);
    ll sum=dis[u]+dis[v]-2*dis[lca];
    return sum;
}
int kth(int u,int v,int k)
 {
    int lca=LCA(u,v);
    int t;
    if(u==lca)
      {
          t=d[v]-d[u]+1;
         swap(u,v);
        k=t-k+1;
     }
    else if(v==lca);
      else
      {
        if(d[u]-d[lca]+1<k)
          {
            t=d[u]+d[v]-2*d[lca]+1;
            k=t-k+1;
            swap(u,v);
        }
    }
    k--;
    for(int i=L-1;i>=0;i--)
      {
        if((1<<i)<=k)
           {
            u=p[u][i];
            k-=(1<<i);
        }
    }
    return u;
}
int main()
 {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
     {
        int N;
        cin>>N;
       for(int i=1;i<=N;i++)
          {
            adj[i].clear();
           for(int j=0;j<L;j++)
               p[i][j]=-1;
       }
        for(int i=1;i<N;i++)
            {
            int u,v,c;
            cin>>u>>v>>c;
            adj[u].pb(mk(v,c));
            adj[v].pb(mk(u,c));
         }
        dis[1]=0;
        dfs(1,1,0);
        sparse(N);
        string s;
        cin>>s;
        while(s!="DONE")
          {// cout<<s<<" ";
            if(s[0]=='D')
               { 
                 int u,v;
                cin>>u>>v;
                cout<<dist(u,v)<<"\n";
            }
            else
             {
                int u,v,k;
                cin>>u>>v>>k;
                cout<<kth(u,v,k)<<"\n";
            }
            cin>>s;
        }
        cout<<"\n";
    }
}
