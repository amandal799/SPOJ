// solution to the "NSTEPS - Number Steps" problem of spoj

#include <bits/stdc++.h>
using namespace std;
int main()
    {
    int n;
    cin>>n;
    while(n--)
       {
       int x,y;
        cin>>x>>y;
        if(x==y)
          {
            if(x%2)
               cout<<2*x-1<<"\n";
            else
                cout<<2*x<<"\n";
         }
        else if(x-y==2)
          {
            if(x%2)
               cout<<x+y-1<<"\n";
            else
                cout<<x+y<<"\n";
        }
        else cout<<"No Number\n";
    }
}
