// solution to the "PT07Z - Longest path in a tree" problem of spoj

#include <bits/stdc++.h>
using namespace std;
const int N=10001;
vector<int> adj[N];
int node;
int mx=-1;
void dfs(int u,int p,int dep)
{
     if(dep>mx) {node=u;mx=dep;}
    for(int i=0;i<adj[u].size();i++)
     {
        if(adj[u][i]!=p)
         {
            dfs(adj[u][i],u,dep+1);
        }
    }
}
int main()
 {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
      {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,0);
    mx=-1;
    dfs(node,0,0);
    cout<<mx;
}
