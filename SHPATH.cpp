// solution to the SHPATH-The shortest Path problem on spoj

#include<bits/stdc++.h>
using namespace std;

#define PII   pair<int,int> 
#define PLI   pair<long,int> 
#define pb push_back
#define mk make_pair

void dijkstra(int u,vector<PII> *adj,long *dis,int v)
 {
    priority_queue<PLI,vector<PLI>,greater<PLI> > q;
    q.push(mk(dis[u],u));
    while(!q.empty())
     {
        u=q.top().second;
        q.pop();
        if(u==v)break;
        for(int i=0;i<adj[u].size();i++)
           {
             int v1=adj[u][i].first;
            int w=adj[u][i].second;
             if(dis[v1]>dis[u]+w)
                 {
                  dis[v1]=dis[u]+w;
                 q.push(mk(dis[v1],v1));
             }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
     {
        int n;
        cin>>n;
       vector<PII> adj[n+1];
        map<string,int> id;
        for(int i=1;i<=n;i++)
           {
            string s;
            cin>>s;
            id[s]=i;
            int m;
            cin>>m;
            while(m--)
             {
                int u,w;
                cin>>u>>w;
                adj[i].pb(mk(u,w));
            }
        }
        int q;
        cin>>q;
        while(q--)
         {
            string s1,s2;
            cin>>s1>>s2;
            int i=id[s1];
            int j=id[s2];
            long dis[n+1];
            for(int i=1;i<=n;i++)dis[i]=INT_MAX;
            dis[i]=0;
            dijkstra(i,adj,dis,j);
            cout<<dis[j]<<"\n";
        }
    }
}
