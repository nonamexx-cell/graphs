#include <bits/stdc++.h>

using namespace std;

int n,s;   // number of vertices and source vertex
int mindis(vector<int> &ans,vector<bool> &vis)
{
   int minima = INT_MAX;
   int minindex = 0;
  for(int i=0;i<n;i++)
  {

     if(!vis[i] && ans[i] < minima)
     {
        minima = ans[i];
        minindex = i;
     }
  }

  return minindex;
}
void call(vector<int> &ans,vector<vector<int>> &edges)
{
    
   // Dijikstras Algorithm
   // complexity O(n^2)
   // donot work for negative edges
   // Algo to find minimum distance between source vertex to all other vertices
   
     vector<bool> vis(false);  // visited array to note covered points
  
    
  
    for(int j=0;j<n;j++) // sufficient to run n times. on every iteration we get one vertex
    {

        int k = mindis(ans,vis); // to find not visited vertex with minimum distance
        
          vis[k] = true;
       for(int i=0;i<n;i++)
       {
            if(edges[k][i] && !vis[i] && ans[k] != INT_MAX && ans[k]+edges[k][i] < ans[i])
            {
               ans[i] = edges[k][i]+ans[k];
            }
       }
    }
}
int main()
{
   cin>>n;
  
  vector<vector<int>> edges(n,vector<int> (n,0));
   
  int m;  // number of edges
  cin>>m; 
  
  int x,y,z;  // vertices and cost;
  
  for(int i=0;i<m;i++)
  {
     cin>>x>>y>>z;
     edges[x][y] = z;
     edges[y][x] = z;
  }
  
  
  vector<int> ans(n,INT_MAX);  // final answer -> distance from source vertex
  
  cin>>s;
  

    ans[s] = 0; // distance from source vertex to itself is 0
  
   call(ans,edges);
  
  for(int i=0;i<n;i++)  // prints distance from every points to source vertex
  { 
     cout<<ans[i]<<" ";
  }
  cout<<endl;
  
   return 0;
}
