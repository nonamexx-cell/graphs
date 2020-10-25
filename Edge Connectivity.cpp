#include <bits/stdc++.h>

using namespace std;

void dfs(int x,vector<vector<int>> &edges,vector<int> &val,vector<int> &par)
{
   for(auto y : edges[x])
   {
       if(val[y] == INT_MAX)
       {
           par[y] = x;
           val[y] = val[x]+1;
           dfs(y,edges,val,par);
       }
   if (y != par[x])
       {
           val[x] = min(val[x],val[y]);
       }
   }
    
}

int main()
{
     int n,m;
     cin>>n>>m;
     
     vector<vector<int>> edges(n);
     
     int x,y;
     
     for(int i=0;i<n;i++)
     {
         cin>>x>>y;
         edges[x].push_back(y);
         edges[y].push_back(x);
     }

     vector<int> val(n,INT_MAX);
     val[0] = 0;
     vector<int> par(n,-1);
     par[0] = -2;
     dfs(0,edges,val,par);

     cout<<endl;
   for(int i=1;i<n;i++)
   {
       //cout<<i<<" "<<par[i]<<endl;
       if(val[par[i]] < val[i])
       {
           cout<<i<<" "<<par[i]<<endl;
       }
   }
}
