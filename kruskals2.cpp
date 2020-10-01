#include <bits/stdc++.h>
 
using namespace std;

int parent[100];           // set to maximum possible value;

int find(int x)
{
      if(parent[x] == x)
         return x;
     return(find(parent[x]));
}
void union1(int x,int y)
{
     int p = find(x);
     int q = find(y);
     
     parent[p] = q;
    
}

int main()
{
    int n,e;
    
    cin>>n>>e;
    
    for(int i=0;i<100;i++)
      parent[i] = i;
    
   
   vector<pair<int,pair<int,int>>> edges;
   
    int x,y,w;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        edges.push_back({w,{x,y}});
    }
    
    sort(edges.begin(),edges.end());
    
    int Nedge = 0;
    
    int ans = 0;
    for(int i=0;i<n;i++)
    {
         if(Nedge == n-1)
         {
             break;
         }
         else
         {
             x = edges[i].second.first;
             y = edges[i].second.second;
            if(find(x) != find(y))
            {
                Nedge++;
                union1(x,y);
                ans = ans+edges[i].first;
                cout<<x<<" "<<y<<endl;  // only if we want to print edges..
            }
         }
    }
    
    cout<<ans<<endl;
}
