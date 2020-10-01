#include <bits/stdc++.h>

using namespace std;

int n;
int flag;
bool fun(pair<pair<int,int>,int> mp1,pair<pair<int,int>,int> mp2)
{
    
    return mp2.second>mp1.second;
}
void dfs(int x,vector<int> &vis,vector<vector<int>> &vec,int par)
{
   // cout<<"hello"<<endl;
    vis[x] = 1;
    
    for(auto i : vec[x])
    {
        if(vis[i] == 1&& i != par)
        {
           flag = 0;
           return ;
        }
        else if(vis[i] == 0 && i != par)
         {
              
             dfs(i,vis,vec,x);
         }
    }
    
 
}
int check(int a,int b,vector<vector<int>> &vec)
{
    
      vec[a].push_back(b);
      vec[b].push_back(a);
      vector<int> vis(n,0);
      flag = 1;
      dfs(a,vis,vec,-1);
      return(flag);
}
int main()
{
    int e;
    cin>>n;
    cin>>e;
   vector<pair<pair<int,int>,int>> mp; // to store input.
   vector<vector<int>> vec(n);
   int x,y,w;
   
   for(int i=0;i<e;i++)
   {
       cin>>x>>y>>w;
       mp.push_back({{x,y},w});  
   }
   
    sort(mp.begin(),mp.end(),fun); // sorting krushals algorithm.
   int val;
   int ans = 0;
   for(int i=0;i<n;i++)
   {
       val = check(mp[i].first.first,mp[i].first.second,vec); // checks wheter mp[i] edge should present in spanning tree or not.
       if(val == 1)
       {
           ans = ans+mp[i].second;
           
       }
       else
       {
           vec[mp[i].first.first].pop_back();
           vec[mp[i].first.second].pop_back();
           
       }
   }
   
   /*for(int i=0;i<n;i++)    **  in case needed to print edges too 
   {
       //int count = 0;
       for(auto x : vec[i])
       {
           cout<<x<<"--"<<i<<endl;
       }
   } */
   
   cout<<ans<<endl;
    
}
