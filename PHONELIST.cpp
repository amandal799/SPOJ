// solution to the "PHONELST - Phone List" problem of spoj

    #include <bits/stdc++.h>
    using namespace std;
    struct node{
        bool isleaf;
        node *child[10];
    };
    node* getNode()
     {
        node *Node=new node;
          Node->isleaf=false;
         for(int i=0;i<10;i++)
           Node->child[i]=NULL;
        return Node;
    }
    bool add(node *root,string &s)
    { 
        int l=s.size();
        node *Node=root;
        bool v=true;
        for(int i=0;i<l;i++)
         {
            int j=s[i]-'0';
            if(Node->child[j]==NULL)
            {Node->child[j]=getNode();v=false;}
              Node=Node->child[j];
             if(Node->isleaf) return true;
        } 
        Node->isleaf=true;
        return v;
    }
bool myway(string &s1,string &s2)
  {
    return s1.size()<s2.size();
}

    int main()
     {
        ios_base::sync_with_stdio(0);
        int T;
        cin>>T;
        while(T--)
         {
          node *root=getNode();
            bool state=true;
            int n; cin>>n;
            vector<string> v;
         while(n--)
         {
            string s;
            cin>>s;
            if(state)
                {
                 if(add(root,s))
                    state=false;
                }
            }
  
            if(state) cout<<"YES\n";
            else cout<<"NO\n";
        }
    } 
