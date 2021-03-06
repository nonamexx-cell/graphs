// detects cycels in graph.

#include<bits/stdc++.h>
using namespace std;

int flag  =0;
stack<int> st;
stack<int> temp;
void dfs(vector<vector<int>> &edges,vector<int> &vis,int x)
{
    vis[x] =1;
    st.push(x);
    for(auto p : edges[x])
    { 
        if(vis[p] == 1)
        {
            flag = 1;
            cout<<p<<" ";
          //  temp.clear();
            while(st.top() != p)
            {
                cout<<st.top()<<" ";
                temp.push(st.top());
                st.pop();
            }
            while(!temp.empty())
            {
                st.push(temp.top());
                temp.pop();
            }
            cout<<endl;
        }
        else if( vis[p] == 0)
         {
             dfs(edges,vis,p);
         }
    }
    st.pop();
    vis[x] = 2; 
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
        //edges[y].push_back(x)
    }
    
    vector<int> vis(n,0);
    
    for(int i=0;i<n;i++)
     if(vis[i] == 0)
      dfs(edges,vis,i);
    
    if(flag == 0)
    {
        cout<<"There is No cycles in Graph"<<endl;
    }
}
