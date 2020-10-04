#include <bits/stdc++.h>

using namespace std;

int wanted = 0;
int sum = 0;  
stack<int> st;
int flag = 0;
int n = 0;
void dfs(vector<vector<int>> &edges,vector<int> &vis,int x)
{
 
   /* for(int i=0;i<n;i++)
    {
        cout<<vis[i]<<" ";
    } */
    //cout<<endl;
    vis[x] = 1;
    st.push(x);
    for(int y=0;y<n;y++)
    {
        if(flag == 1)
        return;
        if(vis[y] == 0 && edges[y][x] != 0)
        {
            if(sum+edges[y][x] == wanted)
            {
                flag = 1;
                st.push(y);
                return ;
            }
            else if(sum+edges[y][x] < wanted)
            {
                sum = sum+edges[y][x];
                dfs(edges,vis,y);
                if(flag == 1)
                return;
                sum = sum-edges[y][x];
                st.pop();
                vis[y] = 0;
            }
            
        }
    }
    
}

int main()
{
    int e;
    cin>>n>>e;
    
    //vector<pair<pair<int,int>,int>> edges;
    vector<vector<int>>  edges(n,vector<int>(n,0));
    vector<int> vis(n);
    int source;
    
    int w,x,y;
    
    for(int i = 0;i<e;i++)
    {
        cin>>x>>y>>w;
        
        edges[x][y] = w;
        edges[y][x] = w;
       
    }
    cin>>source;
    
    cin>>wanted;
    
    flag = 0;
    dfs(edges,vis,source);
    
   /// cout<<"hello"<<endl;
   // cout<<flag<<endl;
  
   if(flag == 0)
      cout<<"There is No such Path"<<endl;
    
    if(flag == 1)
    {
        cout<<st.top();
        st.pop();
        while(!st.empty())
        {
            cout<<"<-"<<st.top();
            st.pop();
        }
    }
    
    
}
