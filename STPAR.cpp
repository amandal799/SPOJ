// solution to the "STPAR - Street Parade" problem of spoj

#include <bits/stdc++.h>
using namespace std;
int main()
    {
    int n;
    cin>>n;
    while(n)
      {
        int arr[n+1];
        for(int i=0;i<n;i++)
          {
          cin>>arr[i];
        }
        int k=0;
        stack<int> s;
        int i=0;
        while(i<n)
          {
            int b=arr[i];
                while(s.size() && s.top()==k+1){k++;s.pop();}
            if(b==k+1)
               k++;
            else
              s.push(b);
            i++;
        }
          while(s.size() && s.top()==k+1){k++;s.pop();}
        if(k==n)cout<<"yes\n";
        else cout<<"no\n";
        cin>>n;
    }
}
