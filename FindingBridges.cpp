#include <bits/stdc++.h>
using namespace std;
// template <class X>
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
const int N = 1e9+7;
// do not forget to use long long 

vector<vector<int>> vec(101);
vector<int> low(101);
vector<int> in(101);
vector<int> vis(101);
int timer = 0;

void dfs(int st,int par)
{
    vis[st]  = 1;
    
    low[st] = in[st] = timer;
    
    timer++;
    
    for(auto x : vec[st])
    {
        if(x == par)
        {
            continue;
        }
        if(vis[x] == 1)
        {
            low[st] = min(low[st],in[x]);
        }
        else 
        {
            dfs(x,st);
            
            
            if(low[x] > in[st])
            {
                cout<<x<<" "<<st<<endl;
            }
            
            low[st] = min(low[st],low[x]);
        }
 
    }

}
void solve()
{
    int n;   // number of vertices starting from "0";
    cin>>n;
   
   int m;
   cin>>m;
   
   int x,y;
   
   while(m--)
   {
       cin>>x>>y;
       vec[x].pb(y);
       vec[y].pb(x);
   }
   
   dfs(0,-1);
   

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
