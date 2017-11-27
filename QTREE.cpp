// solution to the "QTREE - Query on a tree" problem of spoj

#include <bits/stdc++.h>
using namespace std;
const int N0=10100;
const int L=14;
const int root=1;
#define pb push_back
int ci[N0],pos[N0],ch[N0],oe[N0],p[N0][L],sz[N0],d[N0],base[N0];
vector<int> adj[N0],cost[N0],ind[N0];
int ptr,cn;
int st[N0*6];
int max(int a,int b)
    {
    return a>b?a:b;
}
int make_tree(int c,int s,int e)
 {
    if(s==e)
        {st[c]=base[s];return st[c];}
    int c1=(c<<1),c2=c1|1,m=(s+e)>>1;
    st[c]=max(make_tree(c1+1,s,m),
    make_tree(c2+1,m+1,e));
    return st[c];
}
void update_tree(int c,int s,int e,int x,int val)
  {
    if(x<s || x>e)return;
    if(x==s && x==e) {st[c]=val;return;}
    int c1=(c<<1),c2=c1|1,m=(s+e)>>1;
    update_tree(c1+1,s,m,x,val);
    update_tree(c2+1,m+1,e,x,val);
    st[c]=max(st[c1+1],st[c2+1]);
}
int q_tree(int c,int s,int e,int l,int r)
    {
     if(r<s || l>e)return -1;
     if(l<=s && r>=e)
         return st[c];
    int c1=(c<<1),c2=c1|1,m=(s+e)>>1;
    return max(q_tree(c1+1,s,m,l,r),q_tree(c2+1,m+1,e,l,r));
}
int q_up(int u,int v)
  {
    if(u==v) return 0;
    int u_c,v_c=ci[v],ans=-1;
    while(1)
       {
        u_c=ci[u];
        if(u_c==v_c)
            {
            if(u==v)break;
           ans=max(ans,q_tree(0,0,ptr,pos[v]+1,pos[u]));
            break;
          }
        else
          {
            ans=max(ans,q_tree(0,0,ptr,pos[ch[u_c]],pos[u]));
            u=p[ch[u_c]][0];
        }
    }
    return ans;
}
int LCA(int u,int v)
 {
    if(d[u]<d[v])swap(u,v);
    int diff=d[u]-d[v];
    for(int i=0;i<L;i++)
       {
         if((diff>>i)&1)u=p[u][i];
    }
    if(u==v)return u;
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
int query(int u,int v)
  {
    int lca=LCA(u,v);
    return max(q_up(u,lca),
    q_up(v,lca));
}
void change(int x,int val)
  {
    int u=oe[x];
    update_tree(0,0,ptr,pos[u],val);
}
void HLD(int c,int w,int pre)
  {
    if(ch[cn]==-1)
        ch[cn]=c;
    ci[c]=cn;
    pos[c]=ptr;
    base[ptr++]=w;
    int sc=-1,nc;
    for(int i=0;i<adj[c].size();i++)
       {
         if(adj[c][i]!=pre)
             {
              if(sc==-1 || sz[adj[c][i]]>sz[sc])
                  {
                   sc=adj[c][i];
                  nc=cost[c][i];
              }
         }
    }
    if(sc!=-1)
     HLD(sc,nc,c);
    for(int i=0;i<adj[c].size();i++)
      {
         int v=adj[c][i];
        if(v!=pre)
         {  
            if(v!=sc)
                {
            cn++;
            HLD(v,cost[c][i],c);
            }
        }
            
    }
}
void dfs(int c,int pre,int dep)
  {
    sz[c]=1;
    p[c][0]=pre;
    d[c]=dep;
    for(int i=0;i<adj[c].size();i++)
      {
        int v=adj[c][i];
        if(v!=pre)
         {
            oe[ind[c][i]]=v;
            dfs(v,c,dep+1);
            sz[c]+=sz[v];
        }
    }
}
int main()
 {
    int T;
    scanf("%d",&T);
    while(T--)
     {
        int N;
         scanf("%d",&N);
        ptr=0;cn=0;
        for(int i=1;i<=N;i++)
          {
            adj[i].clear();
            cost[i].clear();
            ind[i].clear();
            ch[i]=-1;
            for(int j=0;j<L;j++)
               p[i][j]=-1;
         }
        for(int i=1;i<N;i++)
          {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
            ind[u].pb(i);
            ind[v].pb(i);
        }
        dfs(root,root,0);
        HLD(root,-1,root);
        ptr--;
        make_tree(0,0,ptr);
        for(int i=1;i<L;i++)
            {
            for(int j=1;j<=N;j++)
              {
                if(p[j][i-1]!=-1)
                  p[j][i]=p[p[j][i-1]][i-1];
            }
        }
        while(1)
         {
           char s[100];
           scanf("%s",s);
            if(s[0]=='D')break;
            if(s[0]=='Q')
                {
                int u,v;
                scanf("%d%d",&u,&v);
                printf("%d\n",query(u,v));
            }
            else
               {
                int x,val;
                scanf("%d%d",&x,&val);
                change(x,val);
            }
        }
    }
}
