// solution to the "PPATH - Prime Path" problem of spoj

#include <bits/stdc++.h>
using namespace std;
#define N 10001
bool prime[N];
long mn;
vector<int> adj[N];
#define PLI pair<long,int>

void fun(int a)
 {
    int a1;a1=a/1000;
    int b1;b1=a%1000;
    for(int i=1;i<=9;i++)
       {
        int k=i*1000+b1;
         if(k!=a && prime[k])
             adj[a].push_back(k);
     }
    int a2=b1/100;
    int b2=b1%100;
    for(int i=0;i<=9;i++)
      {
        int k=a1*1000+i*100+b2;
        if(k!=a && prime[k])
          adj[a].push_back(k);
    }
    int a3=b2/10;
    int b3=b2%10;
    for(int i=0;i<=9;i++)
       {
        int k=a1*1000+a2*100+i*10+b3;
        if(k!=a && prime[k])
           adj[a].push_back(k);
          
     }
    a1=a/10;
    for(int i=1;i<=9;i++)
     {
        int k=a1*10+i;
        if(k!=a && prime[k])
            adj[a].push_back(k);
    }
}
void initialise()
  {
    memset(prime,true,sizeof prime);
    for(int i=2;i*i<N;i++)
        {
         if(prime[i])
            {
         for(int j=2*i;j<N;j+=i)
             prime[j]=false;
         }
    }
    for(int i=1000;i<=9999;i++)
        {
        if(prime[i])fun(i);
    }
}
void dfs(int u,long *dis,int b)
 {
    priority_queue<PLI,vector<PLI>,greater<PLI> > q;
    q.push(make_pair(dis[u],u));
    while(!q.empty())
      {
         u=q.top().second;//cout<<u<<" "<<dis[u]<<"\n";
       // if(u==b) break;
        q.pop();
        for(int i=0;i<adj[u].size();i++)
          {
            int k=adj[u][i];
            if(dis[k]>dis[u]+1)
               {
                dis[k]=dis[u]+1;
                q.push(make_pair(dis[k],k));
             }
        }
    }
}
int main()
  {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    initialise();
   while(T--)
     {
        int a,b;
        cin>>a>>b;
        mn=INT_MAX;
        long dis[10000];
       for(int i=1001;i<=9999;i++)dis[i]=INT_MAX;
       dis[a]=0;
        dfs(a,dis,b);
        if(dis[b]==INT_MAX) cout<<"Impossible\n";
        else
        cout<<dis[b]<<"\n";
    }
}
