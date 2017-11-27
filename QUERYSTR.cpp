// solution to the "QUERYSTR - Query Problem" problem of spoj

#include <bits/stdc++.h>
using namespace std;
int main()
 {
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
      {
        string s;
        cin>>s;
        reverse(s.begin(),s.end());
        s=s+'#'+s;
        int n=s.size();
        int z[n];
        int L,R;
        L=R=0;
        for(int i=1;i<n;i++)
          {
             if(i>R)
              {
                 L=R=i;
                 while(R<n && s[R-L]==s[R]) R++;
                 z[i]=R-L;
                 R--;
             }
            else
            {
                 int k=i-L;
                if(z[k]<R-i+1)z[i]=z[k];
                else
                  {
                    L=i;
                    while(R<n && s[R-L]==s[R])R++;
                    z[i]=R-L;R--;
                }
            }
        }
        int q;
        cin>>q;
        while(q--)
         {
            int l;
            cin>>l;
            cout<<z[n-l]<<"\n";
        }
    }
}
