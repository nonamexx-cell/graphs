#include <bits/stdc++.h>
// do not forget to use long long 
using namespace std;
#define mod 1000000007
#define modc 998244353
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vl vector<ll>
#define vul vector<ull>
#define fr(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define ret return
const double pi = 3.14159265359;

int find(int x,vector<int> &par)
{
    while(x != par[x])
     {
         x = par[x];
     }
     
     return x;
}
void solve()
{
    
     // Cycle detection Using Disjoint sets
     // find method is used to find Ancestors of given vertex
     // Only Applicable for Undirected Grpahs
      
     int n;
     cin>>n;  // number of vertices starts from 0.
     
     vector<vector<int>> vec(n);
     
     int m;
     cin>>m;
     
     int x,y;
     for(int i=0;i<m;i++)
     {
         cin>>x>>y;
         vec[x].pb(y);    // edge from x to y;
     }
     
     vector<int> par(n);
     for(int i=0;i<n;i++)
       par[i] = i;
      
      int p,q; 
    for(int i=0;i<n;i++)
    {
         p = find(i,par);
        for(auto x: vec[i])
        {
            q = find(x,par);
            
            if(p == q)
             {
                 cout<<"Cycle Present"<<endl;
                 ret;
             }
             
             else
             {
                 par[q] = p;
             }
        }
    }
    
    cout<<"NO Cycle Found"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
       int t = 1;
      cin>>t;
      while(t--)
         solve();
	return 0;
}
