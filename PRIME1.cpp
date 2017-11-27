// solution to the "PRIME1 - Prime Generator" problem of spoj

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<long> v;
void initialise()
 {
    bool p[40000];
   memset(p,true,sizeof p);
   
    for(int i=2;i<=180;i++)
        {
         if(p[i])
           {
             for(long j=2*i;j<=32000;j+=i)
                 p[j]=false;
         }
    }
    for(int i=2;i<=32000;i++)
       {
        if(p[i]){v.pb(i);}
    }
}
int main() {
	
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
    initialise();
	while(n--)
	{
        long a,b;
        cin>>a>>b;
        bool prime[100001];
       memset(prime,true,sizeof prime);
        int x=sqrt(b);
        if(a==1)a++;
        for(int i=0;i<v.size();i++)
          {
            if(v[i]<=x)
              { 
                int d;
               if(a<=v[i]) d=2;
               
               else if(a%v[i])
                    d=a/v[i]+1;
                else
                  d=a/v[i];
               long y=v[i]*d;
               
                for(long j=y;j<=b;j+=v[i])
                    prime[j-a]=false;
            }
            else break;
        }
        for(long i=a;i<=b;i++)
            {
            if(prime[i-a]) cout<<i<<"\n";
        }
        cout<<"\n";
	}

	return 0;
}
