// solution to the "NHAY - A Needle in the Haystack" problem of spoj

#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
//ios_base::sync_with_stdio(0);
 long n;
while(scanf("%ld",&n)!=EOF)
{
    getchar();
    //cout<<n<<"\n";
 string s;
cin>>s;
   getchar();
long lps[n];
lps[0]=0;
long i=1,len=0;
while(i<n)
{
 if(s[i]==s[len])
{
 lps[i]=++len;
 i++;
}
else
{
 if(len)
 len=lps[len-1];
 else
{
lps[i]=0;i++;
}
}
}
    //cout<<s<<"\n";
register char c;
c=getchar();
long k=0,j=0;
while(c>='a'&& c<='z')
{ //cout<<c<<" "<<k<<"  ";
 if(c==s[j])
{
 c=getchar();k++;j++;
}
if(j==n)
{
 cout<<k-n<<"\n";
 j=lps[j-1];
}
else if(c!='\n' && c!=s[j])
{
 if(j)
 j=lps[j-1];
 else
 {c=getchar();k++;}
}
}
cout<<"\n";
}
}
