//solution to the "PARTY - Party Schedule" problem of spoj

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int dp(pair<int,int> *p,int n,int m)
  {
    int arr[n+1][m+1];
    int cost[n+1][m+1];
    int t=0;
    for(int i=0;i<=n;i++)
      {
        for(int j=0;j<=m;j++)
            {
             if(i==0 || j==0)
             {arr[i][j]=0;cost[i][j]=0;}
             else 
              {
                 int c=p[j-1].f;
                 int fn=p[j-1].s;
                 if(c<=i)
                 {
                     int a=arr[i-c][j-1]+fn;
                     int b=arr[i][j-1];
                     if(a>b)
                     {cost[i][j]=c+cost[i-c][j-1];
                      arr[i][j]=a;
                     }
                      else if(b>a)
                      {cost[i][j]=cost[i][j-1];
                       arr[i][j]=b;
                      }
                     else
                         {
                      cost[i][j]=min(c+cost[i-c][j-1],cost[i][j-1]);
                         arr[i][j]=a;
                     }
                 }
                 else
                 {
                   arr[i][j]=arr[i][j-1];
                   cost[i][j]=cost[i][j-1];
                 }
             }
           // cout<<arr[i][j]<<" ";
         }//cout<<"\n";
     }
    cout<<cost[n][m]<<" "<<arr[n][m]<<"\n";
    return 0;
}
int main()
 {
 ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    
    while(n!=0 || m!=0)
        {
    pair<int,int> p[m];
    for(int i=0;i<m;i++)
       {
        int c,fn;
        cin>>c>>fn;
        p[i]=make_pair(c,fn);
     }
      dp(p,n,m);
        getchar();
    cin>>n>>m;
    }
}
