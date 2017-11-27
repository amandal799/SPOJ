// solution to the "PT07Y - Is it a tree" problem of spoj

#include <bits/stdc++.h>
using namespace std;
void dfs(int u,bool *vis,vector<int> *adj)
 {
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++)
      {
        if(!vis[adj[u][i]])
                dfs(adj[u][i],vis,adj);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    if(m!=n-1)
        cout<<"NO";
    else
      {
        vector<int> adj[n+1];
        for(int i=1;i<n;i++)
            {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool vis[n+1];
        memset(vis,false,sizeof vis);
        dfs(1,vis,adj);
        int c=0;
        for(int i=1;i<=n;i++)
          {
            if(!vis[i])
               {c=1;break;}
        }
        if(c)cout<<"NO";
        else cout<<"YES";
    }
}
