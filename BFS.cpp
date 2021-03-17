#include <bits/stdc++.h>

using namespace std;


int main()
{
  
  int n; // number of vertices
  cin>>n;
  
  vector<vector<int>> edges(n); // Always store edges in eges array
  
  int m;
  cin>>m; // number of edges
  int x,y;
  for(int i=0;i<m;i++)
  {
     cin>>x>>y;
    edges[x].push_back(y); // directed edges
  }
  
  vector<int> vis(n);
	     
	     queue<int> q;
	     
	     q.push(0);     // always starting from root node 0
	     
	     vector<int> ans;
	     ans.push_back(0);
	     
	     while(!q.empty())
	     {
	         for( auto x : edges[q.front()])
	         {
	             
	             if(vis[x] == 0)
	             {
	                 ans.push_back(x);
	                 q.push(x);
	                 vis[x] = 1;
	             }
	         }
	         
	         q.pop();
	     }
	     
	     
	  // final answers present in vector ans;
  
  return 0;
}
