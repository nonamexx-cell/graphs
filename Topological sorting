#include<bits/stdc++.h>
 
using namespace std;
int flag  =0;
stack<int> st;

void dfs(vector<vector<int>> &edges,vector<int> &vis,int p)
{
    vis[p] = 1;
    for(auto x: edges[p])
    {
        if(vis[x] == 0 )
        {
            dfs(edges,vis,x);
        }
    }
    st.push(p);
}


int  main()
{
   
   int n,e;
   
   cin>>n>>e;
   
    vector<vector<int>> edges(n);
    
    int x,y;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        
        edges[x].push_back(y);
       // edges[y].push_back(x);
        
    }
    
    vector<int> vis(n,0);
    for(int i=0;i<n;i++)
     if(vis[i] == 0)
      {
          dfs(edges,vis,i);
      }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
     
    
}
