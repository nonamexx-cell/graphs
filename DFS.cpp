#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void dfs(int x,vector<int> &vis,vector<vector<int>> &edges)
{
    ans.push_back(x);
      vis[x] = 1;
     
   for(auto y: edges[x])
   {
       if(vis[y] == 0)
       {
           dfs(y,vis,edges);
       }
   }
}

int mian()
{
   int n;
  cin>>n;
 
   int m;
  cin>>m;
  
  vector<vector<int>> edges(n);
  
   int x,y;
  
  for(int i=0;i<m;i++)
  {
     edges[x].push_back(y);
  }
   vector<int> vis(n,0);
  
   dfs(0,vis,edges);
  
  // final Answer present in vector<int> ans;
  
  return 0;
}
