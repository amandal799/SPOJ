// solution to the "ONP - Transform the Expression" problem of spoj

#include <bits/stdc++.h>
using namespace std;
struct node{
    node *left,*right;
    char val;
};
void Print(node *root)
{
    if(root==NULL)return;
    Print(root->left);
    Print(root->right);
    cout<<root->val;
    
}
int main()
    {
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    while(n--)
     {
       stack<node*> st;
        string s;
        cin>>s;
        //cout<<s<<"\n";
        for(int i=0;i<s.size();i++)
        {
           // cout<<s[i];
            if(s[i]!=')')
                {
             struct node *Node;
             Node=new node;
            Node->left=Node->right=NULL;
                Node->val=s[i];
                st.push(Node);
            }
            else
             {
                    struct node *root;
                    root=new node;
                    root->right=st.top();
               // cout<<st.top()->val<<" ";
                    st.pop();
                    root->val=st.top()->val;
                    st.pop();
                  root->left=st.top();
               // cout<<st.top()->val<<" ";
                st.pop();st.pop();
                st.push(root);
            }
        }
        Print(st.top());
        cout<<"\n";
    }
}
